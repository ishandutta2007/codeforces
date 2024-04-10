#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

inline int read(void)
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

vector<int> g[MAXN];

int siz[MAXN], mxson[MAXN];
void dfs_siz(int u,int fa)
{
	siz[u] = 1; mxson[u] = 0;
	for(int v: g[u]) if(v != fa)
	{
		dfs_siz(v, u);
		siz[u] += siz[v];
		mxson[u] = max(mxson[u], siz[v]);
	}
}

int rt, totsiz;
void dfs_rt(int u,int fa)
{
	mxson[u] = max(mxson[u], totsiz - siz[u]);
	if(mxson[u] < mxson[rt]) rt = u;
	for(int v: g[u]) if(v != fa)
		dfs_rt(v, u);
}

int main(void)
{
	int n = read();
	for(int i=2; i<=n; ++i)
	{
		int j = read();
		g[j].push_back(i); g[i].push_back(j);
	}
	
	dfs_siz(1, 0);
	rt = 1; totsiz = n;
	dfs_rt(1, 0);
	
	dfs_siz(rt, 0);
	
	bitset<MAXN / 2> bak;
	bak.set(0);
	
	static int cnt[MAXN];
	for(int v: g[rt]) ++cnt[siz[v]];
	for(int i=1; i<=n; ++i) if(cnt[i])
	{
		int sum = i * cnt[i];
		for(int j=i; j<=sum; sum-=j, j<<=1)
			bak |= bak << j;
		if(sum)
			bak |= bak << sum;
	}
	
	ll ans = 0;
	for(int i=0; i<=(n+1)/2; ++i) if(bak[i])
		ans = max(ans, (ll)i * (n - 1 - i));
	for(int i=1; i<=n; ++i) ans += siz[i];
	
	printf("%lld",ans);
	return 0;
}