#include<cstdio>
#include<vector>

std::vector<long long> g[100001];
long long a[100001];
long long v[100001];

long long c[100001];
long long d[100001];

long long f(long long x){return x<0?-x:x;}

void dfs(long long x)
{
	if(v[x])return;
	long long i;
    v[x]=1;
    for(i=0;i<g[x].size();i++)if(!v[g[x][i]])
	{
		dfs(g[x][i]);
        if(c[g[x][i]]>c[x])c[x]=c[g[x][i]];
        if(d[g[x][i]]>d[x])d[x]=d[g[x][i]];
	}
    i=c[x]-d[x]+a[x];
    if(i<0)c[x]-=i;
    if(i>0)d[x]+=i;
}

int main()
{
	long long s,e;
	long long i,n;
	scanf("%I64d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&s,&e);
		g[s].push_back(e);
		g[e].push_back(s);
	}
    for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
    dfs(1);
    printf("%I64d",c[1]+d[1]);
}