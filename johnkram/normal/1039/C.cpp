#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
#define MAXN 500005
struct node
{
	int s,t;
	ll d;
	bool operator<(const node& y)const
	{
		return d<y.d;
	}
}e[MAXN];
ll a[MAXN];
int n,m,N,i,j,s,ans,f[MAXN];
int get(int x)
{
	if(f[x]==x)return x;
	return f[x]=get(f[x]);
}
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int main()
{
	scanf("%d%d%d",&n,&m,&N);
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=n;i++)scanf("%I64d",a+i);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&e[i].s,&e[i].t);
		e[i].d=a[e[i].s]^a[e[i].t];
	}
	sort(e+1,e+m+1);
	for(i=1;i<=m;)
	{
		for(j=i,s=n;j<=m&&e[i].d==e[j].d;j++)if(get(e[j].s)!=get(e[j].t))
		{
			f[get(e[j].s)]=get(e[j].t);
			s--;
		}
		for(;i<j;i++)
		{
			f[e[i].s]=e[i].s;
			f[e[i].t]=e[i].t;
		}
		ans+=Pow(2,n)-Pow(2,s);
		if(ans>=P)ans-=P;
		if(ans<0)ans+=P;
	}
	ans=Pow(2,n+N)-ans;
	if(ans<0)ans+=P;
	cout<<ans<<endl;
	return 0;
}