#include <stdio.h>

int a,b;
char x[1010];
int check[1010][2010];
int next[1010][2010];
int func(int s, int t)
{
	if(t==b||t==-b)
	{
		if(s>a) return 1;
		else return -1;
	}
	if(s>a) return -1;
	
	if(check[s][t+1000]!=0) return check[s][t+1000];
	
	int s1 = -1, s2 = -1, s3 = -1;
	if(x[s]=='?'||x[s]=='W') s1 = func(s+1,t+1);
	if(x[s]=='?'||x[s]=='D') s2 = func(s+1,t);
	if(x[s]=='?'||x[s]=='L') s3 = func(s+1,t-1);
	if(s1==1)
	{
		next[s][t+1000] = 1;
		return check[s][t+1000] = 1;
	}
	if(s2==1)
	{
		next[s][t+1000] = 0;
		return check[s][t+1000] = 1;
	}
	if(s3==1)
	{
		next[s][t+1000] = -1;
		return check[s][t+1000] = 1;
	}
	return check[s][t+1000] = -1;
}

int main()
{
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	
	int t = func(1,0);
	if(t==-1)
	{
		printf("NO");
		return 0;
	}
	
	int p = 1000;
	for(int i=1;i<=a;i++)
	{
		if(next[i][p]==1) printf("W");
		if(next[i][p]==0) printf("D");
		if(next[i][p]==-1) printf("L");
		p += next[i][p];
	}
}