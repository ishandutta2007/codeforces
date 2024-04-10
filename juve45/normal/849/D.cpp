#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_vp(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<"("<<x[_].first<<','<<x[_].second<<") ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100100
#define NMAX 1 	 	

using namespace std;

int g[DMAX], p[DMAX], t[DMAX];
int h, w;
pair<int, int> ans[DMAX];
int n, mar[4];
vector<pair<int, pair<int, int> > > s[3];
vector <pair<int, int> > m[200100];

int main()
{
	ios_base::sync_with_stdio(false);
	//cin >> n;

	cin >> n >> mar[1] >> mar[2];
	for(int i = 1; i <= n; i++)
	{
		int sgn;
		cin >> g[i] >> p[i] >> t[i];
		if(g[i] == 2) sgn = -1;
		else sgn = 1;
		m[100001 + p[i] - t[i]].push_back({sgn*p[i], i});
	}


	for(int i = 0; i <= 200004; i++)
	{
		if(m[i].size() == 0) continue;
		sort(m[i].begin(), m[i].end());
		int j = 0;
		while(j < m[i].size() && m[i][j].first < 0) j++;
		if(j == m[i].size()) j = 0;
		for(int k = 0; k < m[i].size();k++)
		{
			int curr = m[i][k].second;
			int hit = m[i][(k+j)%m[i].size()].second, x, y;
			if(g[hit] == 1) {
				x = p[hit];
				y = mar[2];
			}
			else{
				x = mar[1];
				y = p[hit];
			}
			ans[curr] = {x, y};
		}
	}

	for(int i = 1; i <= n; i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
}