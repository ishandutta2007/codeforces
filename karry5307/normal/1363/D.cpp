#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51;
ll test,n,kk,x,l,r,mid,rx,pos;
string str;
ll res[MAXN],v[MAXN][MAXN],sz[MAXN];
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
inline ll query(ll l,ll r)
{
	cout<<"? "<<r-l+1<<" ";
	for(register int i=l;i<=r;i++)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return read();
}
inline ll query(ll x)
{
	cout<<"? "<<n-sz[x]<<" ";
	for(register int i=1;i<=n;i++)
	{
		if(!v[x][i])
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return read();
}
inline void solve()
{
	l=1,r=n=read(),kk=read(),memset(v,0,sizeof(v));
	for(register int i=1;i<=kk;i++)
	{
		sz[i]=read();
		for(register int j=0;j<sz[i];j++)
		{
			v[i][read()]=1;
		}
	}
	rx=query(1,n),pos=0;
	while(l<r)
	{
		mid=(l+r)>>1,query(l,mid)==rx?r=mid:l=mid+1;
	}
	for(register int i=1;i<=kk;i++)
	{
		!v[i][l]?res[i]=rx:pos=i;
	}
	if(pos)
	{
		res[pos]=query(pos);
	}
	cout<<"! ";
	for(register int i=1;i<=kk;i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl,cin>>str;
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}