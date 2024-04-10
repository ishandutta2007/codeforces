#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,pos,l,r,mid,res;
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
	return cout<<"? "<<l<<" "<<r<<endl,read();
}
int main()
{
	n=read(),pos=query(1,n);
	if(n==2)
	{
		return cout<<"! "<<(pos^3)<<endl,0;
	}
	if(pos!=1&&pos==query(1,pos))
	{
		l=1,r=pos-1,res=pos-1;
		while(l<=r)
		{
			mid=(l+r)>>1;
			pos==query(mid,pos)?res=mid,l=mid+1:r=mid-1;
		}
	}
	else
	{
		l=pos+1,r=n,res=pos+1;
		while(l<=r)
		{
			mid=(l+r)>>1;
			pos==query(pos,mid)?res=mid,r=mid-1:l=mid+1;
		}
	}
	cout<<"! "<<res<<endl;
}