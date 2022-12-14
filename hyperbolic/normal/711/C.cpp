#include <stdio.h>
int a,b,c;
int x[110],y[110][110];
long long int MAX = 1;
long long int DP[110][110][110];
long long int func(int s, int t, int k)
{
	//s t ,  k
	long long int ans = MAX;
	if(s==a)
	{
		if(t==c) return 0;
		else return MAX;
	}
	if(DP[s][t][k]!=-1) return DP[s][t][k];
	if(x[s+1]==0)
	{
		for(int i=1;i<=b;i++)
		{
			long long int s0;
			if(k==i) s0 = func(s+1,t,i)+y[s+1][i];
			else s0 = func(s+1,t+1,i)+y[s+1][i];
			ans = ans<s0?ans:s0;
		}
		return DP[s][t][k]=ans;
	}
	else
	{
		if(k==x[s+1]) return DP[s][t][k]=func(s+1,t,x[s+1]);
		else return DP[s][t][k]=func(s+1,t+1,x[s+1]);
	}
}
int main()
{
	for(int i=1;i<=13;i++) MAX*=10;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
    for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&y[i][j]);
    for(int i=0;i<=102;i++) for(int j=0;j<=102;j++) for(int k=0;k<=102;k++) DP[i][j][k]=-1;

    if(func(0,0,101)>=MAX) printf("-1");
	else printf("%I64d",func(0,0,101));
}