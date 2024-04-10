#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
queue<ll>q;
ll cnt,cur,top,col;
ll l[MAXN],r[MAXN],res[MAXN];
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
	cnt=cur=col=read();
	for(register int i=1;i<=cnt;i++)
	{
		l[i]=read();
	}
	for(register int i=1;i<=cnt;i++)
	{
		r[i]=read();
	}
	while(1)
	{
		for(register int i=1;i<=cnt;i++)
		{
			if(l[i]==0&&r[i]==0)
			{
				q.push(i);
			}
		}
		if(q.empty())
		{
			break;
		}
		cur-=q.size();
		while(!q.empty())
		{
			top=q.front(),q.pop(),l[top]=r[top]=-1,res[top]=col;
			for(register int i=top-1;i;i--)
			{
				r[i]--;
			}
			for(register int i=top+1;i<=cnt;i++)
			{
				l[i]--;
			}
		}
		col--;
	}
	if(cur)
	{
		return puts("NO"),0;
	}
	puts("YES");
	for(register int i=1;i<=cnt;i++)
	{
		printf("%d ",res[i]);
	}
}