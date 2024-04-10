#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
ll length;
ll dp[MAXN];
char str[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
int main()
{
	scanf("%s",str+1),length=strlen(str+1);
	for(register int i=1;i<=length;i++)
	{
		if(str[i]=='m'||str[i]=='w')
		{
			return puts("0"),0;
		}
	}
	dp[1]=1;
	for(register int i=2;i<=length;i++)
	{
		if((str[i]=='u'&&str[i-1]=='u')||(str[i]=='n'&&str[i-1]=='n'))
		{
			dp[i]=i==2?2:(dp[i-1]+dp[i-2])%MOD;
			continue;
		}
		dp[i]=dp[i-1];
	}
	printf("%d\n",dp[length]);
}