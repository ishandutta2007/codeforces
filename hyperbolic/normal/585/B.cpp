#include <stdio.h>
#include <vector>

int a;
char x[10][1010];
int check(int s, int t)
{
	if('A'<=x[s][t]&&x[s][t]<='Z') return 0;
	else return 1;
}

int check2[10][1010];
int func(int s, int t)
{
	if(t>a) return 1;
	if(!check(s,t)) return 0;
	
	if(check2[s][t]!=-1) return check2[s][t];
	
	int s1 = 0, s2 = 0, s3 = 0;
	if(check(s,t+1)&&check(s,t+2)&&check(s,t+3)) s1 = func(s,t+3);
	if(s>=2&&check(s,t+1)&&check(s-1,t+1)&&check(s-1,t+2)&&check(s-1,t+3)) s2 = func(s-1,t+3);
	if(s<=2&&check(s,t+1)&&check(s+1,t+1)&&check(s+1,t+2)&&check(s+1,t+3)) s3 = func(s+1,t+3);
	if(s1==1||s2==1||s3==1) return check2[s][t] = 1;
	else return check2[s][t] = 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=3;i++) for(int j=1;j<=100;j++) x[i][j] = '.';
		
		int b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=3;i++) for(int j=1;j<=a;j++) check2[i][j] = -1;
		
		for(int i=1;i<=3;i++) scanf("%s",x[i]+1);
		std::pair<int,int> start;
		for(int i=1;i<=3;i++) if(x[i][1]=='s') start = std::make_pair(i,1);
		int k = func(start.first,start.second);
		printf("%s\n",k==1?"YES":"NO");
	}
}