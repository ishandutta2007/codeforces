#include <stdio.h>
#define MAX 987654321

int check[60][60][60];
int func(int s, int t, int k)
{
	if(s*t<k) return MAX;
	if(k==0) return 0;
	if(s*t==k) return 0;
	if(check[s][t][k]!=-1) return check[s][t][k];
	
	int min = MAX;
	for(int i=1;i<s;i++)
	{
		for(int j=0;j<=k;j++)
		{
			int s1 = func(i,t,j);
			int s2 = func(s-i,t,k-j);
			min = min<s1+s2+t*t?min:s1+s2+t*t;
		}
	}
	for(int i=1;i<t;i++)
	{
		for(int j=0;j<=k;j++)
		{
			int s1 = func(s,i,j);
			int s2 = func(s,t-i,k-j);
			min = min<s1+s2+s*s?min:s1+s2+s*s;
		}
	}
	return check[s][t][k] = min;
}

int main()
{
	for(int i=1;i<=30;i++) for(int j=1;j<=30;j++) for(int k=0;k<=50;k++) check[i][j][k] = -1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",func(a,b,c));
	}
}