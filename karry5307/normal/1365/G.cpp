#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const ll MAXN=2e5+51;
ll n,tot;
ll mask[MAXN],val[MAXN],res[MAXN]; 
vector<ll>qry[MAXN];
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
inline ll query(ll x)
{
	cout<<"? "<<qry[x].size()<<" ";
	for(register int i=0;i<qry[x].size();i++)
	{
		cout<<qry[x][i]<<" ";
	}
	cout<<endl;
	return read();
}
int main()
{
	n=read();
	for(register int i=1;i<8192;i++)
	{
		if(__builtin_popcount(i)==6)
		{
			mask[++tot]=i;
			for(register int j=0;j<13;j++)
			{
				if(!((i>>j)&1))
				{
					qry[j].push_back(tot);
				}
			}
			if(tot==n)
			{
				break;
			}
		}
	}
	for(register int i=0;i<13;i++)
	{
		if(!qry[i].empty())
		{
			val[i]=query(i);
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=0;j<13;j++)
		{
			if((mask[i]>>j)&1)
			{
				res[i]|=val[j];
			}
		}
	}
	cout<<"! ";
	for(register int i=1;i<=n;i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
}