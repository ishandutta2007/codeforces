#include <stdio.h>
#define MAX 12345678
int abs(int k)
{
	return k>0?k:-k;
}

int a,b,c;
char x[110];
int next[41][41][41][90],check[41][41][41][90];
int func(int k, int s, int t, int gap)
{
	if(k>a)
	{
		if(s==0&&t==0)
		{
			if(-a<gap&&gap<a) return abs(gap);
			else return MAX;
		}
		else return MAX;
	}
	if(next[k][s][t][gap+a]!=0) return check[k][s][t][gap+a];
	
	int s1 = func(k+1,(10*s+x[k]-'0')%b,t,gap+1);
	int s2 = func(k+1,s,(10*t+x[k]-'0')%c,gap-1);
	if(s1<=s2)
	{
		next[k][s][t][gap+a] = -1;
		return check[k][s][t][gap+a] = s1;
	}
	else
	{
		next[k][s][t][gap+a] = 1;
		return check[k][s][t][gap+a] = s2;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",x+1);
		
		for(int i=1;i<=a;i++) for(int j=0;j<=b;j++) for(int k=0;k<=c;k++) for(int l=0;l<=2*a;l++) next[i][j][k][l] = check[i][j][k][l] = 0;
		int t = func(1,0,0,0);
		if(t==MAX) printf("-1\n");
		else
		{
			int k = 1, s = 0, t = 0, gap = 0;
			for(int i=1;i<=a;i++)
			{
				if(next[k][s][t][gap+a]==-1)
				{
					printf("R");
					s = (10*s+x[k]-'0')%b, gap++, k++;
				}
				else
				{
					printf("B");
					t = (10*t+x[k]-'0')%c, gap--, k++;
				}
			}
			printf("\n");
		}
	}
}