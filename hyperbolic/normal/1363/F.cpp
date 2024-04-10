#include <stdio.h>
#define MAX 12345678

int a;
int sum1[30][2010],sum2[30][2010];
char x[2020],y[2020];
int check[2010][2010];

int func(int s, int t)
{
	if(s>a||t>a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	if(x[s]==y[t]) return check[s][t] = func(s+1,t+1);
	else
	{
		int s1 = MAX,s2 = MAX;
		s1 = func(s,t+1)+1;
		if(sum1[x[s]-'a'+1][s-1] < sum2[x[s]-'a'+1][t-1]) s2 = func(s+1,t);
		//printf("%d %d : %d %d!!",s,t,s1,s2);
		return check[s][t] = s1<s2?s1:s2;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) check[i][j] = -1;
		
		scanf("%s%s",x+1,y+1);
		for(int i=1;i<=26;i++) for(int j=1;j<=a;j++) sum1[i][j] = sum1[i][j-1] + (x[j]=='a'+i-1?1:0);
		for(int i=1;i<=26;i++) for(int j=1;j<=a;j++) sum2[i][j] = sum2[i][j-1] + (y[j]=='a'+i-1?1:0);
		
		for(int i=1;i<=26;i++)
		{
			if(sum1[i][a]!=sum2[i][a])
			{
				printf("-1\n");
				goto u;
			}
		}
		
		printf("%d\n",func(1,1));
		u:;
	}
}