#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
int flag=0;int d;
typedef struct player{
char name[100];
char type[100];
int foreigner;
int points;
char team[100];
struct player *next;
}player_t;

typedef struct team
{
	char tname[10];
	player_t player[7];
	float money;
	int tpts;
	int no_player;
	
}team_t;

void disp_team(team_t*);
void player_info(player_t[]);
void team_info(team_t*);
void disp_player(player_t*);
void auction(team_t*,player_t*,player_t*);
void team_details(team_t);
void display_teamwise(player_t*);
void sold_details(player_t *p);
void unsold_details(player_t *p);
void timer();
void winner(team_t *team);




int main()
{
	    	PlaySound(NULL,NULL,SND_FILENAME);				
			sndPlaySound("C:\\Users\\Asus\\Downloads\\perfect.wav", SND_ASYNC | SND_NODEFAULT|SND_LOOP); 

	printf("-------------------------------------------------IPL AUCTION--------------------------------------------------------\n--------------------------------------------------------------------------------------------------------------------\n\n");
	
	team_t team[6];
	team_info(team);
	int n;
	

/*
player_t p1={"Virat Kohli","Batsmen",0,99,"NOT SOLD YET"};
player_t p2={"Rohit Sharma","Batsmen",0,98,"NOT SOLD YET"};
player_t p3={"David Warner","Batsmen",1,97,"NOT SOLD YET"};
player_t p4={"Steve Smith","Batsmen",1,97,"NOT SOLD YET"};
player_t p5={"Shikhar Dhawan","Batsmen",0,95,"NOT SOLD YET"};
player_t p6={"Mayank Agarwal","Batsmen",0,90,"NOT SOLD YET"};
player_t p7={"Nitish Rana","Batsmen",0,90,"NOT SOLD YET"};
player_t p8={"Shreyas Iyer","Batsmen",0,93,"NOT SOLD YET"};
player_t p9={"Shubhman Gill","Batsmen",0,85,"NOT SOLD YET"};
player_t p10={"Devdutt Padikkal","Batsmen",0,83,"NOT SOLD YET"};
player_t p11={"Rashid Khan","Right Arm Spin",1,96,"NOT SOLD YET"};
player_t p12={"Jasprit Bumrah","Right Arm Fast",0,96,"NOT SOLD YET"};
player_t p13={"Trent Boult","Right Arm Fast",1,94,"NOT SOLD YET"};
player_t p14={"Yuzvendra Chahal","Right Arm spin",0,93,"NOT SOLD YET"};
player_t p15={"T.Natarajan","Right Arm Fast",0,88,"NOT SOLD YET"};
player_t p16={"Mohammed Siraj","Right Arm Fast",0,91,"NOT SOLD YET"};
player_t p17={"Harshal Patel","Right Arm Fast",0,90,"NOT SOLD YET"};
player_t p18={"Shardul Thakur","Right Arm Fast",0,92,"NOT SOLD YET"};
player_t p19={"Ravindra Jadeja","All Rounder",0,90,"NOT SOLD YET"};
player_t p20={"Andre Russell","All Rounder",1,92,"NOT SOLD YET"};
player_t p21={"Glenn MAxwell","All Rounder",1,93,"NOT SOLD YET"};
player_t p22={"Rahul Tewatia","All Rounder",0,83,"NOT SOLD YET"};
player_t p23={"Krunal Pandya","All Rounder",0,85,"NOT SOLD YET"};
player_t p24={"Hardik Pandya","All Rounder",0,93,"NOT SOLD YET"};
player_t p25={"Kl Rahul","Wicket-Keeper Batsmen",0,95,"NOT SOLD YET"};
player_t p26={"Rishabh Pant","Wicket-Keeper Batsmen",0,94,"NOT SOLD YET"};
player_t p27={"Jos Buttler","Wicket-Keeper Batsmen",1,95,"NOT SOLD YET"};
player_t p28={"AB Devilliers","Wicket-Keeper Batsmen",1,98,"NOT SOLD YET"};
player_t p29={"Jonny Bairstow","Wicket-Keeper Batsmen",0,95,"NOT SOLD YET"};
player_t p30={"MS Dhoni","Wicket-Keeper Batsmen",0,98,"NOT SOLD YET"};

p1.next=&(p2);
p2.next=&(p3);
p3.next=&(p4);
p4.next=&(p5);
p5.next=&(p6);
p6.next=&(p7);
p7.next=&(p8);
p8.next=&(p9);
p9.next=&(p10);
p10.next=&(p11);
p11.next=&(p12);
p12.next=&(p13);
p13.next=&(p14);
p14.next=&(p15);
p15.next=&(p16);
p16.next=&(p17);
p17.next=&(p18);
p18.next=&(p19);
p19.next=&(p20);
p20.next=&(p21);
p21.next=&(p22);
p22.next=&(p23);
p23.next=&(p24);
p24.next=&(p25);
p25.next=&(p26);
p26.next=&(p27);
p27.next=&(p28);
p28.next=&(p29);
p29.next=&(p30);
p30.next=NULL;

*/

player_t *p1=NULL;
player_t *temp=NULL;
player_t *curr1=NULL;
FILE *f1=fopen("data.txt","r");


if(f1==NULL){
printf("Data file Not open...\n");
}else{
char line[500];



while(fgets(line,500,f1)!=NULL){

char *name=strtok(line,",");
char *type=strtok(NULL,",");
char *form=strtok(NULL,",");
char *poin=strtok(NULL,",");
char *team=strtok(NULL,",");
player_t *temp=(player_t*)malloc(sizeof(player_t));



strcpy(temp->name,name);
strcpy(temp->type,type);
temp->foreigner=atoi(form);
temp->points=atoi(poin);
strcpy(temp->team,team);
temp->next=NULL;





if(p1==NULL){
p1=temp;
curr1=p1;

}else{
curr1->next=temp;
curr1=curr1->next;
curr1->next=NULL;

}



}
}












	printf("Details for each team are as follows:\n");
	int i;
	for(i=0;i<4;i++)
	{
		printf("\n----------------------------------Team%d-------------------------------------\n",i+1);
		disp_team(&team[i]);
	}
	printf("****************************************************************************\n");
	player_t *curr=(p1);
	int j;	
for(j=0;j<30;j++)
	{
		printf("\n------------------------------------------------------------------------------------------------------------------\n");
		printf("Player %d for auction is\n",j+1);
		disp_player(curr);
		auction(team,curr,(p1));
		/*
		printf("Details for each team are as follows:\n");
		for(int j=0;j<4;j++)
		{
			printf("~~Team%d~~\n",j+1);
			disp_team(&team[j]);
		}
		printf("###############################################################\n");
		*/

		curr=curr->next;
	}
	/*char ch;
	printf("Do you want to know full details of a team(y/n): ");
	fflush(stdin);
	scanf("%c",ch);
	while(ch == 'y')
	{
		printf("Enter team no. whose details you want to know");
		fflush(stdin);
		scanf("%d",&n);
		team_details(team[n-1]);
		//printf("Do you want to know full details of another team(y/n): ");
		//fflush(stdin);
		//scanf("%c",ch);
	}*/
	winner(team);
	printf("END");
	return 0;
}
void team_info(team_t *team)
{
	strcpy(team->tname,"RCB");
	//strcpy(team.tname,"RCB");
	team->money = 3000;
	team->tpts = 0;
	team->no_player = 0;
	strcpy(team[1].tname,"CSK");
	team[1].money = 3000;
	team[1].tpts = 0;
	team[1].no_player = 0;
	strcpy(team[2].tname,"MI");
	team[2].money = 3000;
	team[2].tpts = 0;
	team[2].no_player = 0;
	strcpy(team[3].tname,"KKR");
	team[3].money = 3000;
	team[3].tpts = 0;
	team[3].no_player = 0;
}
void disp_team(team_t *team)
{
	printf("Team name: %s\n",(team->tname));
	printf("Money: %0.3f\n",(team->money));
	printf("Points: %d\n",(team->tpts));
	printf("No. of players: %d\n",(team->no_player));		
}
void disp_player(player_t *player)
{
	printf("Name: %s\t",player->name);
	printf("Player Type: %s\t",player->type);
	int frg=(player->foreigner);
	if(frg==1){
	printf("Foreigner: %c\t",'Y');}else{
	printf("Foreigner: %c\t",'N');
}
	printf("Base Points: %d\n",player->points);
	printf("SOLD to: %s\n",player->team);
}






void auction(team_t *team,player_t *p,player_t *first)
{
	int n=0;
	float m=0,tmp=(float)p->points;
	char ch;flag=0;
	
	do
	{
		
		if(flag==0)
			{
				printf("Enter team no. who wants to bid\n");
				printf("1.RCB 2.CSK 3.MI 4.KKR\n");
				int correct=0;
				while(correct==0){
				timer();
				if(d==49 || d==50 || d==51 || d==52 || d==48 || d=='\0'){
				correct=1;
				break;
}			
				printf("Wrong Team code... Enter again..\n");
				}				

				
				switch(d)
				{
					case 49: n=1; break;
					case 50: n=2; break;
					case 51: n=3; break;
					case 52: n=4; break;
					case 48: n=0; break;
					default: n=0;
				}

				printf("The team who wants to start the bid->%d\n",n);
				fflush(stdin);
			}
		else
			{

				int correct=0;
				while(correct==0){
				timer();
				if(d==49 || d==50 || d==51 || d==52 || d==48 || d=='\0'){
				correct=1;
				break;
}			
				printf("Wrong Team code... Enter again..\n");
				}
				

				switch(d)
				{
					case 49: n=1; break;
					case 50: n=2; break;
					case 51: n=3; break;
					case 52: n=4; break;
					case 48: n=0;break;
					default: n=0;
				}
				printf("The team who wants to bid further->%d\n",n);
				fflush(stdin);
			}
		if(n>0 && n<5){
		
		int noplayers=team[n-1].no_player;
		if(noplayers>=6){
			printf("Team already contains maximum number of players can't add more...\n");
			n=7;
		}
	}
		
		
		if(n==0){
			strcpy(p->team,"UNSOLD");
			printf("Player- %s remains UNSOLD...\n",p->name);
			break;
		}
		printf("Enter the amount to bid: ");
		scanf("%f",&m);
		int nofunds=0;
		if(n>0 && n<5){
		
		float curr_money;
		curr_money=team[n-1].money;
		if(curr_money<=0){
			printf("Currently selected team doesn't have any funds left...\n");
			nofunds=1;
		}
		while(m>curr_money && nofunds!=1){
		printf("The entered team doesn't have enough money to bid...\n");
		printf("Enter the amount to bid: ");
			scanf("%f",&m);
		}
	}
		
		
		
		if(m<tmp && n<5 && nofunds==0)
		{
			printf("Too low.Enter value greater than Previous or Base amount..\n");
			printf("Enter the amount to bid: ");
			scanf("%f",&m);
		}
		
		
		
		
		
		//if(n>=5){
		//printf("Wrong team code\n");
		
		
	
	if(nofunds!=1){
	
		printf("Any other team wants to bid\n");
		printf("1.RCB 2.CSK 3.MI 4.KKR\n");
		timer();
		fflush(stdin);
		
}
	
		tmp = m;fflush(stdin);
	}
	while(flag==1); //timer = 0
	
	if(strcmp(p->team,"UNSOLD")!=0 && n>0 && n<5){
	team[n-1].player[(team[n-1].no_player)] = *p;
	team[n-1].money -= m;
	team[n-1].no_player += 1;
	team[n-1].tpts += p->points;
	strcpy(p->team,team[n-1].tname);
	p->points=m;
	sold_details(p);
	}
	fflush(stdin);
	printf("To get the team details ,enter y otherwise n \n");
	scanf("%c",&ch);
	if(ch==('y')){
	printf("\n\n");
	printf("*************************************************************************\n");
	team_details((team[0]));
	team_details((team[1]));
	team_details((team[2]));
	team_details((team[3]));
	display_teamwise(first);
	printf("\n\n");
	printf("*************************************************************************\n");
	}
	fflush(stdin);
	printf("To get the unsold details,enter y otherwise n \n");
	scanf("%c",&ch);
	if(ch=='y'){
	printf("\n\n");
	unsold_details(first);
	}
	
	
	
	//--------------------------------------------------------------------------------------------------------------------------------------------------
	
}
void team_details(team_t team)
{
	printf("Team name: %s\n",(team.tname));
	printf("Money: %.2f\n",(team.money));
	printf("Points: %d\n",(team.tpts));
	printf("No. of players: %d\n",(team.no_player));
	int batsmen=0,bowler=0,all_rounder=0,wicket=0;
	int k;
	for(k=0;k<team.no_player;k++)
	{
		if(strcmp((team.player[k]).type,"Batsmen") == 0)
			batsmen++;
		if(strcmp((team.player[k]).type,"Bowler") == 0)
			bowler++;
		if(strcmp((team.player[k]).type,"all rounder") == 0)
			all_rounder++;
		if(strcmp((team.player[k]).type,"Wicket keeping") == 0)
			wicket++;
	//	int x = strcmp((team.player[k]).type,"Batsmen");
	//	printf("$$%d\n",x);
	}
	printf("No. of batsmen: %d\n",batsmen);
	printf("No. of bowler: %d\n",bowler);
	printf("No. of all rounder: %d\n",all_rounder);
	printf("No. of wicket keeper: %d\n",wicket);
	printf("************************\n");
	
}



void display_teamwise(player_t *player1){
player_t *player=player1;
printf("\n\nSold Player Details are as follows:\n");

while(player!=NULL){
if(strcmp(player->team,"RCB")==0){
disp_player(player);}
player=player->next;
}

player=player1;
while(player!=NULL){
if(strcmp(player->team,"CSK")==0){
disp_player(player);}
player=player->next;
}

player=player1;
while(player!=NULL){
if(strcmp(player->team,"MI")==0){
disp_player(player);}
player=player->next;
}

player=player1;
while(player!=NULL){
if(strcmp(player->team,"KKR")==0){
disp_player(player);}
player=player->next;
}




}


void sold_details(player_t *p){
printf("SOLD!! SOLD!! SOLD!! %s is SOLD to team- %s for %d points...\n\n",p->name,p->team,p->points);
}



void unsold_details(player_t *p){
	player_t *temp=p;
	printf("*************************************************************************\n");
	printf("\n\nUnsold Player Details are as follows:\n");
	while(temp!=NULL){
		if(strcmp(temp->team,"UNSOLD")==0){
disp_player(temp);}
		
	temp=temp->next;
	}
	printf("\n\n");
	printf("*************************************************************************\n");
	
	
}
void timer()
{
	int seconds=15;int s=0;d=0;flag=0;
	while(seconds>0)
	{
		
		seconds--;
		if(seconds>=10)
			printf("%d:00\r",seconds);
		else
			printf("%d%d:00\r",s,seconds);
		Sleep(1000);
		fflush(stdin);
		if(kbhit())
			{
				d=(int)(getch());
				flag=1;
			        break;
			}
	}
}
void winner(team_t *team)
{
	int pts=0;int pos;int i;
	int spent=0;
	for(i=0;i<4;i++)
	{
		if(team[i].tpts > pts)
		{
			pos=i;
			pts=team[i].tpts;
			spent=3000-team[i].money;
		}else if(team[i].tpts == pts){
			if((3000-team[i].money)<spent){
			pos=i;
			pts=team[i].tpts;
			spent=3000-team[i].money;

}
}
		

	}
	Sleep(1000);
	printf("THE WINNER OF IPL AUCTION GAME --> %s !!\n",(team[pos].tname));
	Sleep(1000);
}





















