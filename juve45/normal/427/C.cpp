#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100010
#define MOD 1000000007
using namespace std;

int n, nr, m, a, b;
long long ans = 1LL, Min;
vector <int> v[DMAX], g[DMAX], c[DMAX];
int use[DMAX], val[DMAX];
stack<int>s;

void dfs1(int k)
{
	use[k]=1;
	for(int i=0;i<v[k].size();i++)
		if(!use[v[k][i]])
			dfs1(v[k][i]);
	s.push(k);
}

void dfs2(int k)
{
	use[k]=1;
	for(int i=0;i<g[k].size();i++)
		if(!use[g[k][i]])
			dfs2(g[k][i]);
	c[nr].push_back(k);
}

bool cmp(int a, int b)
{
	return val[a] < val[b];
}

int main()
{

	cin >> n;

	for(int i=1;i<=n;i++)
		cin >> val[i];

	cin >> m;

	for(int i=1;i<=m;i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i=1;i<=n;i++)
		if(!use[i])
			dfs1(i);

	memset(use, 0, 4*DMAX);

	while(!s.empty())
	{
		if(!use[s.top()])
			dfs2(s.top()), nr++;
		s.pop();
	}

	for(int i=0;i<nr;i++)
	{
		sort(c[i].begin(), c[i].end(), cmp);
		int cnt = 0, j=0;
		while(j<c[i].size() && val[c[i][0]]==val[c[i][j]]) 
			cnt++, j++;
		Min += val[c[i][0]];
		ans *= 1LL*cnt;
		ans %= MOD;
	}
	cout << Min << ' ' << ans;
 	return 0;
}