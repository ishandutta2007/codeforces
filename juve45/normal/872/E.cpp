#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100100
#define NMAX 1
#define MMAX 1
#define MOD 1000000007
using namespace std;

int n, k, p2[DMAX], use[DMAX], nr, X, Y, ax[DMAX], ay[DMAX], sz, ok;
long long ans = 1LL;
string s; 
set<int> xc, yc;
map<int, int> m;
vector <pair<int, int> > x[2 * DMAX], y[2 * DMAX];
vector <int> v[DMAX];


int get(int x)
{
	if(m.find(x) != m.end())
		return m[x];
	m[x] = nr++;
	return m[x];
}


int dfs(int k, int t)
{
	int ans = 0;
	use[k]++;
	xc.insert(ax[k]);
	yc.insert(ay[k]);

	for(int i = 0; i < v[k].size(); i++)
	{
		if(v[k][i] == t) 
			continue;
		if(use[v[k][i]] == 1)
			ans = 1;
		else ans = ans | dfs(v[k][i], k);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;

	p2[0] = 1;
	for(int i = 1; i < DMAX; i++)
		p2[i] = p2[i - 1] * 2,
		p2[i] %= MOD;
	dbg_v(p2, 2000);
	for(int i = 1; i <= n; i++)
	{
		cin >> ax[i] >> ay[i];
		X = get(ax[i]);
		Y = get(ay[i]);
		x[X].push_back({Y, i});
		y[Y].push_back({X, i});
	}


	for(int i = 0; i < 2 * DMAX; i++)
	{
		sort(x[i].begin(), x[i].end());
		for(int j = 1; j < x[i].size(); j++)
		{
			int a = x[i][j].second;
			int b = x[i][j - 1].second;
			v[a].push_back(b);
			v[b].push_back(a);
		}


		sort(y[i].begin(), y[i].end());
		for(int j = 1; j < y[i].size(); j++)
		{
			int a = y[i][j].second;
			int b = y[i][j - 1].second;
			v[a].push_back(b);
			v[b].push_back(a);
		}
	}

	//for(int i = 1; i <= n; i++)

	dbg_v(v[1], v[1].size());
	for(int i = 1; i <= n; i++)
	{
		if(use[i])
			continue;

		xc.clear();
		yc.clear();
		ok = dfs(i, -1);
		sz = xc.size() + yc.size();

		//if(p2[sz] < 1) return -1;
		//if(ans < 0) return i;
		if(ok)
			ans *= 1LL * p2[sz];
		else 
			ans *= 1LL * (p2[sz] - 1);
		ans %= MOD;		
		
	}

	cout << ans << '\n';

}