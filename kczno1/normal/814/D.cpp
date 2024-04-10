#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1505;
int n;
int x[N],y[N],r[N];
int nex[N],t[N],f[N];

ll sqr(ll x) { return x*x; }

ll ans;
const double pi=acos(-1.0);
void dfs(int x,bool h1,bool h2)
{
	if(h1) swap(h1,h2);
	if(!h1) 
	{
		ans+=(ll)r[x]*r[x];
		h1=1;
	}
	else 
	{
	   ans-=(ll)r[x]*r[x];
	   h1=0;
	}
	for(int y=t[x];y;y=nex[y])
	dfs(y,h1,h2);
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d%d",x+i,y+i,r+i);
    r[0]=1e9;
    rep(i,1,n)
    rep(j,1,n)
    if(r[i]>r[j])
    if(sqr(x[i]-x[j])+sqr(y[i]-y[j])<=sqr(r[i]-r[j])&&r[i]<=r[f[j]])  f[j]=i;
    
    int j;
	rep(i,1,n)
    if(j=f[i])
	{
		nex[i]=t[j];t[j]=i;
    }
    
    rep(i,1,n)
    if(!f[i]) dfs(i,0,0);
    printf("%.10f\n",ans*pi);
}