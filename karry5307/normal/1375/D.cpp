#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
set<ll>st;
vector<ll>res;
ll test,n,d,pos;
ll x[MAXN],r[MAXN];
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
inline ll mex()
{
	for(register int i=0;i<=n+1;i++)
	{
		if(!r[i])
		{
			return i;
		}
	}
}
inline void solve()
{
	n=read(),st.clear(),res.clear();
	for(register int i=0;i<=n+1;i++)
	{
		r[i]=0;
	}
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),r[x[i]]++,st.insert(i);
	}
	for(register int i=1;i<=n;i++)
	{
		x[i]==i-1?st.erase(i),1:1;
	}
	while(!st.empty())
	{
		if((d=mex())!=n)
		{
			r[x[d+1]]--,r[x[d+1]=d]++,st.erase(d+1),res.push_back(d+1);
			continue;
		}
		pos=*st.begin(),r[x[pos]]--,r[x[pos]=d]++,res.push_back(pos);
	}
	printf("%d\n",res.size());
	for(register int i:res)
	{
		printf("%d ",i);
	}
	puts("");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}