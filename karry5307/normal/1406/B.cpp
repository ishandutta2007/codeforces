#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=5e5+51;
ll test,n,x,syk,ak,res;
ll u[MAXN],v[MAXN];
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
	n=read(),syk=ak=0;
	for(register int i=1;i<=n;i++)
	{
		x=read(),x>=0?u[++syk]=x:v[++ak]=-x;
	}
	sort(u+1,u+syk+1),sort(v+1,v+ak+1),res=-1e18;
	syk>=5?res=max(res,u[syk]*u[syk-1]*u[syk-2]*u[syk-3]*u[syk-4]):1;
	syk>=4&&ak>=1?res=max(res,-u[1]*u[2]*u[3]*u[4]*v[1]):1;
	syk>=3&&ak>=2?res=max(res,u[syk]*u[syk-1]*u[syk-2]*v[ak]*v[ak-1]):1;
	syk>=2&&ak>=3?res=max(res,-u[1]*u[2]*v[1]*v[2]*v[3]):1;
	syk>=1&&ak>=4?res=max(res,u[syk]*v[ak]*v[ak-1]*v[ak-2]*v[ak-3]):1;
	ak>=5?res=max(res,-v[1]*v[2]*v[3]*v[4]*v[5]):1;
	printf("%lld\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}