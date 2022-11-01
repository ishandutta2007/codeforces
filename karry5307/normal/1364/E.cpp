#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51; 
ll n,p,q,vl,vl2,vl3,pos;
ll x[MAXN];
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
inline ll query(ll x,ll y)
{
	cout<<"? "<<x<<" "<<y<<endl;
	return read();
}
inline ll queryZero(ll x)
{
	ll res=2047,px;
	for(register int i=0;i<10;i++)
	{
		px=rand()%n+1;
		while(px==x)
		{
			px=rand()%n+1;
		}
		res&=query(x,px);
	}
	return res==0;
}
int main()
{
	memset(x,-1,sizeof(x)),n=read(),p=1,q=2,vl=query(p,q);
	srand(time(0));
	for(register int i=3;i<=n;i++)
	{
		vl2=query(p,i);
		if(vl2>vl)
		{
			continue;
		}
		vl3=query(q,i),vl3<=vl2?(p=q,q=i,vl=vl3):(q=i,vl=vl2);
	}
	pos=queryZero(p)?p:q;
	for(register int i=1;i<=n;i++)
	{
		x[i]=i==pos?0:query(i,pos);
	}
	cout<<"! ";
	for(register int i=1;i<=n;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}