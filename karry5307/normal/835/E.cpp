#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e3+51;
vector<ll>tmp,xx,yy;
ll cnt,x,y,res,diff,p,l,r,mid,res1,res2;
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
inline ll makeQuery(vector<ll>v)
{
	ll res;
	if(!v.size())
	{
		return 0;
	}
	cout<<"? "<<v.size()<<" ";
	for(register int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl,fflush(stdout),cin>>res;
	return res;
}
int main()
{
	cnt=read(),x=read(),y=read();
	for(register int i=0;i<10;i++)
	{
		tmp.clear();
		for(register int j=1;j<=cnt;j++)
		{
			if(j&(1<<i))
			{
				tmp.push_back(j);
			}
		}
		res=makeQuery(tmp);
		if(res==y||res==(x^y))
		{
			diff|=(1<<i),p=i;
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		(i&(1<<p))?xx.push_back(i):yy.push_back(i);
	}
	if(xx.size()>yy.size())
	{
		swap(xx,yy);
	}
	r=xx.size()-1;
	while(l<r)
	{
		tmp.clear(),mid=(l+r)>>1;
		for(register int i=l;i<=mid;i++)
		{
			tmp.push_back(xx[i]);
		}
		res=makeQuery(tmp);
		(res==y||res==(x^y))?r=mid:l=mid+1;
	}
	res1=xx[l],res2=res1^diff;
	if(res1>res2)
	{
		swap(res1,res2);
	}
	cout<<"! "<<res1<<" "<<res2<<endl,fflush(stdout);
}