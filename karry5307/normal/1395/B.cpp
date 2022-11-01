#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=151;
ll n,m,x,y;
ll vis[MAXN][MAXN];
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
inline void walk(ll c)
{
	x=c,vis[x][y]=1,printf("%d %d\n",x,y);
	for(register int i=1;i<=m;i++)
	{
		!vis[x][i]?vis[x][y=i]=1,printf("%d %d\n",x,y):1;
	}
}
int main()
{
	n=read(),m=read(),x=read(),y=read(),walk(x);	
	for(register int i=1;i<=n;i++)
	{
		!vis[i][1]?walk(i):(void)1;
	}
}