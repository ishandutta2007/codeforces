#include<cstdio>
#include<vector>

const int mod = 1000000007;

std::vector<int> g[111111];
int c[111111];
int d[111111];

void dfs(int x)
{
	int tt;
	int cc,dd;
	int t1,t2;
    int i;
    c[x]=1;
    cc=0;dd=1;
    tt=1;
	for(i=0;i<g[x].size();i++)
	{
		dfs(g[x][i]);
		t1=c[x];
		t2=d[x];
        (c[x]+=(1LL*t1*d[g[x][i]]+1LL*t2*c[g[x][i]])%mod)%=mod;
        (d[x]+=(1LL*t1*c[g[x][i]]+1LL*t2*d[g[x][i]])%mod)%=mod;
        t1=cc;
        t2=dd;
        (cc+=(1LL*t2*c[g[x][i]])%mod)%=mod;
        (dd+=(1LL*t1*c[g[x][i]])%mod)%=mod;
        (tt+=(1LL*tt*d[g[x][i]])%mod)%=mod;
	}
	//printf("%d: %d %d\n",x,c[x],d[x]);
    (c[x]*=2)%=mod;
    (d[x]*=2)%=mod;
	//printf("%d: %d %d\n",x,c[x],d[x]);
	//printf("%d: %d %d\n",x,c[x],d[x]);
	(d[x]+=mod-cc)%=mod;
	(c[x]+=mod-tt)%=mod;
	//printf("%d: %d %d\n",x,c[x],d[x]);
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
	{
		scanf("%d",&j);
		g[j].push_back(i);
	}
	dfs(1);
	printf("%d",(c[1]+d[1])%mod);
}