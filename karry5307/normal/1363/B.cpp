#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,res;
ll prefix[MAXN][2],suffix[MAXN][2];
char ch[MAXN];
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
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1),res=0x3f3f3f3f;
	for(register int i=1;i<=n;i++)
	{
		prefix[i][0]=prefix[i-1][0],prefix[i][1]=prefix[i-1][1];
		prefix[i][ch[i]-'0']++;
	}
	suffix[n+1][0]=suffix[n+1][1]=0;
	for(register int i=n;i;i--)
	{
		suffix[i][0]=suffix[i+1][0],suffix[i][1]=suffix[i+1][1];
		suffix[i][ch[i]-'0']++;
	}
	for(register int i=1;i<=n;i++)
	{
		res=min(res,prefix[i-1][0]+suffix[i+1][1]);
		res=min(res,prefix[i-1][1]+suffix[i+1][0]);
	}
	printf("%d\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}