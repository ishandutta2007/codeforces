#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,qcnt,m,cur,lb;
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
int main()
{
	n=read(),qcnt=read();
	for(register int i=1;i<=qcnt;i++)
	{
		cur=read(),scanf("%s",ch+1),m=strlen(ch+1);
		for(register int j=1;j<=m;j++)
		{
			lb=cur&-cur;
			ch[j]=='L'&&cur%2==0?cur-=(lb>>1):1;
			ch[j]=='R'&&cur%2==0?cur+=(lb>>1):1;
			if(ch[j]=='U'&&cur!=(n+1)>>1)
			{
				cur&(lb<<1)?cur-=lb:cur+=lb;
			}
		}
		printf("%lld\n",cur);
	}
}