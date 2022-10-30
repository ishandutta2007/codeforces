#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair<ll,ll> pii;
const ll MAXN=5e3+51;
ll length,width;
ll mp[MAXN][MAXN];
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
inline bool isin(ll minn,ll num,ll maxn)
{
	return num>=minn&&num<=maxn;
}
inline bool check(ll x,ll y)
{
	if(x==length-1||y==width-1)
	{
		return 0;
	}
	ll sum=mp[x][y]+mp[x+1][y]+mp[x][y+1]+mp[x+1][y+1];
	return sum==1;
}
inline bool chk(ll x,ll y)
{
	if(!mp[x][y])
	{
		return 0;
	}
	if(check(x,y))
	{
		return 1;
	}
	if(isin(0,x-1,length-1)&&check(x-1,y))
	{
		return 1;
	}
	if(isin(0,y-1,width-1)&&check(x,y-1))
	{
		return 1;
	}
	if(isin(0,x-1,length-1)&&isin(0,y-1,width+1)&&check(x-1,y-1))
	{
		return 1;
	}
	return 0;
}
inline void bfs()
{
	queue<pii>q;
	pii top;
	ll x,y;
	for(register int i=0;i<length;i++)
	{
		for(register int j=0;j<width;j++)
		{
			if(chk(i,j))
			{
				mp[i][j]=0,q.push(make_pair(i,j));
			}
		}
	}
	while(!q.empty())
	{
		top=q.front(),q.pop(),x=top.first,y=top.second;
		for(register int i=x-1;i<=x+1;i++)
		{
			for(register int j=y-1;j<=y+1;j++)
			{
				if(isin(0,i,length-1)&&isin(0,j,width-1)&&chk(i,j))
				{
					mp[i][j]=0,q.push(make_pair(i,j));
				}
			}
		}
	}
}
int main()
{
	length=read(),width=read();
	for(register int i=0;i<length;i++)
	{
		scanf("%s",str);
		for(register int j=0;j<width;j++)
		{
			mp[i][j]=(str[j]=='*');
		}
	}
	bfs();
	for(register int i=0;i<length;i++)
	{
		for(register int j=0;j<width;j++)
		{
			printf("%c",mp[i][j]?'*':'.');
		}
		puts("");
	}
}