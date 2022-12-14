#include <stdio.h>

int a;
char x[110];
int check[110][5];

int func(int s, int t) //count
{
	if(s>a) return 1;
	if(check[s][t]!=-1) return check[s][t];
	if(x[s]=='?')
	{
		int s1;
		if(t==1) s1 = func(s+1,2) + func(s+1,3);
		if(t==2) s1 = func(s+1,1) + func(s+1,3);
		if(t==3) s1 = func(s+1,1) + func(s+1,2);
		//int s1 = func(s+1,1) + func(s+1,2) + func(s+1,3);
		return check[s][t] = s1<100?s1:100;
	}
	else
	{
		if(x[s]=='C')
		{
			if(t==1) return check[s][t] = 0;
			else return check[s][t] = func(s+1,1);
		}
		else if(x[s]=='M')
		{
			if(t==2) return check[s][t] = 0;
			else return check[s][t] = func(s+1,2);
		}
		else
		{
			if(t==3) return check[s][t] = 0;
			else return check[s][t] = func(s+1,3);
		}
	}
}

int main()
{
	scanf("%d%s",&a,x+1);
	for(int i=0;i<=a;i++) for(int j=0;j<=4;j++) check[i][j] = -1;
	int s1;
	if(x[1]=='?') s1 = func(2,1) + func(2,2) + func(2,3);
	else
	{
		if(x[1]=='C') s1 = func(2,1);
		if(x[1]=='M') s1 = func(2,2);
		if(x[1]=='Y') s1 = func(2,3);
	}
	printf("%s",s1<=1?"No":"Yes");
}