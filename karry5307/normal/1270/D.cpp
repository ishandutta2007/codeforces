#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=3e5+51;
ll cnt,ccnt,p,q,s,t,u,v,res=1;
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
int main()
{
	cin>>cnt>>ccnt,cout<<"? ";
	for(register int i=1;i<=ccnt;i++)
	{
		cout<<i<<" ";
	}
	cout<<endl,cin>>p>>q,cout<<"? ";
	for(register int i=1;i<=ccnt;i++)
	{
		if(i!=p)
		{
			cout<<i<<" ";
		}
	}
	cout<<cnt<<endl,cin>>s>>t,t=t>q?1:-1;
	for(register int i=1;i<=ccnt;i++)
	{
		if(i!=p)
		{
			cout<<"? ";
			for(register int j=1;j<=ccnt;j++)
			{
				if(j!=i)
				{
					cout<<j<<" ";
				}
			}
			cout<<cnt<<endl,cin>>u>>v;
			u==p?x[i]=t:x[i]=-t;
		}
	}
	for(register int i=1;i<=ccnt;i++)
	{
		if(x[i]==-1)
		{
			res++;
		}
	}
	cout<<"! "<<res<<endl;
}