#include <bits/stdc++.h>
#define x first
#define y second
#define DMAX 1010
#define dbg(x) //cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

long long n, k, m;
vector<long long> v[DMAX], f;
long long x, y, ans, use[DMAX];

long long dfs(long long x)
{
	long long ans = 1;
	use[x] = 1;
	for(long long i=0;i<v[x].size();i++)
	{
		if(!use[v[x][i]])
			ans += dfs(v[x][i]);
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	for(long long i=1;i<=k;i++)
		cin >> x, f.push_back(x);

	for(long long i=1;i<=m;i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	long long Max = 0;
	for(long long i=0;i<f.size();i++)
		if(!use[f[i]])
		{
			long long g = dfs(f[i]);
			Max = max(g, Max);
			ans += (g*(g-1)/2);
			dbg(ans);
			dbg(g);
		}
		long long rr = 0;

	for(long long i=1;i<=n;i++)
	{
		rr+=use[i];
	}
	rr= n-rr;
	dbg(ans);
		
		cout << (rr*(rr-1)/2) + rr*Max +  ans-m << '\n';

	return 0;
}