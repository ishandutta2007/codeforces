#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct Item{
	ll x,id;
	inline bool operator <(const Item &rhs)const
	{
		return x<rhs.x;
	}
};
Item it[MAXN];
vector<ll>res;
ll test,n;
ll pr[MAXN],f[MAXN];
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
inline void solve()
{
	n=read(),res.clear();
	for(register int i=1;i<=n;i++)
	{
		it[i]=(Item){read(),i},f[i]=0;
	}	
	sort(it+1,it+n+1),f[n]=1,res.push_back(it[n].id);
	for(register int i=1;i<=n;i++)
	{
		pr[i]=pr[i-1]+it[i].x; 
	}
	for(register int i=n-1;i;i--)
	{
		(f[i]=f[i+1]&&pr[i]>=it[i+1].x)?res.push_back(it[i].id):(void)1;
	}
	sort(res.begin(),res.end()),printf("%d\n",res.size());
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