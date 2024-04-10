#include<cstdio>
#include<algorithm>

const int mod = 1000000007;

int l;
std::pair<int,int> a[2222];
int d[2222];
int v[2222];

int f[222222];
int g[222222];

int fo(int x,int y)
{
    if(y==0)return 1;
    if(y&1)return 1LL*x*fo(x,y-1)%mod;
    x=fo(x,y>>1);
    return 1LL*x*x%mod;
}

int dfs(int x)
{
	if(v[x])return d[x];
    int i;
    v[x]=1;
    d[x]=1LL*f[a[x].first+a[x].second-2]*g[a[x].first-1]%mod*g[a[x].second-1]%mod;
    for(i=0;i<l;i++)if(i!=x&&a[x].first>=a[i].first&&a[x].second>=a[i].second)
	{
		d[x]=(d[x]-1LL*dfs(i)*f[a[x].first-a[i].first+a[x].second-a[i].second]%mod*g[a[x].first-a[i].first]%mod*g[a[x].second-a[i].second]%mod+mod)%mod;
	}
	return d[x];
}

int main()
{
    int i,j,n,m;
    scanf("%d%d%d",&n,&m,&l);
	for(i=0;i<l;i++)scanf("%d%d",&a[i].first,&a[i].second);
    a[l].first=n;
    a[l].second=m;
    l++;
    f[0]=1;
    for(i=1;i<222222;i++)f[i]=1LL*i*f[i-1]%mod;
    for(i=0;i<222222;i++)g[i]=fo(f[i],mod-2);
    printf("%d\n",dfs(l-1));
}