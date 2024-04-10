#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
mt19937 mt(20050103);
ll n,st,x,v,nxt,c,vx,nxtx;
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
	n=read(),nxt=st=read(),x=read(),v=-1;
	for(register int i=1;i<=min(n,1000);i++)
	{
		c=mt()%n+1,cout<<"? "<<c<<endl,vx=read(),nxtx=read();
		vx>v&&vx<=x?v=vx,nxt=nxtx:1;
	}
	if(v==x)
	{
		return cout<<"! "<<v<<endl,0;
	}
	for(register int i=1;i<=1000;i++)
	{
		if(nxt==-1)
		{
			return cout<<"! -1"<<endl,0;
		}
		cout<<"? "<<nxt<<endl,vx=read(),nxtx=read();
		if(vx>=x)
		{
			return cout<<"! "<<vx<<endl,0;
		}
		v=vx,nxt=nxtx;
	}
}