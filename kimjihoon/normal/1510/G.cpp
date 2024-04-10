#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int k, pr[109], inf = 10009;
vector<pair<int, int> > d[109][109][2];
vector<int> v[109], ans;

void dp(int n)
{
	for (int i = 0; i <= k; i++) {
		d[n][i][0].push_back(make_pair(inf, 0));
		d[n][i][1].push_back(make_pair(inf, 0));
	}
	d[n][1][0][0].first = d[n][1][1][0].first = 0;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		dp(tn);
		for (int j = 0; j <= k; j++) {
			d[n][j][0].push_back(d[n][j][0].back());
			d[n][j][0].back().second = 0;
			for (int pi = 0; pi < j; pi++)
				if (d[n][j][0].back().first > d[n][pi][0][i].first + d[tn][j - pi][0].back().first + 2) {
					d[n][j][0].back().first = d[n][pi][0][i].first + d[tn][j - pi][0].back().first + 2;
					d[n][j][0].back().second = j - pi;
				}
		}
		for (int j = 0; j <= k; j++) {
			d[n][j][1].push_back(d[n][j][1].back());
			d[n][j][1].back().second = 0;
			for (int pi = 0; pi < j; pi++) {
				if (d[n][j][1].back().first > d[n][pi][1][i].first + d[tn][j - pi][0].back().first + 2) {
					d[n][j][1].back().first = d[n][pi][1][i].first + d[tn][j - pi][0].back().first + 2;
					d[n][j][1].back().second = j - pi;
				}
				if (d[n][j][1].back().first > d[n][pi][0][i].first + d[tn][j - pi][1].back().first + 1) {
					d[n][j][1].back().first = d[n][pi][0][i].first + d[tn][j - pi][1].back().first + 1;
					d[n][j][1].back().second = pi - j;
				}
			}
		}
	}
}

void ps(int n, int tk, int t)
{
	int rtn = -1, rk = -1;
	for (int i = (int)v[n].size(); tk > 0 && i >= 1; i--) {
		if (d[n][tk][t][i].second == 0) continue;
		int tn = v[n][i - 1];
		if (d[n][tk][t][i].second > 0) {
			ans.push_back(tn);
			ps(tn, d[n][tk][t][i].second, 0);
			ans.push_back(n);
			tk -= d[n][tk][t][i].second;
		}
		else {
			rtn = tn; rk = -d[n][tk][t][i].second;
			tk += d[n][tk][t][i].second;
			t = 0;
		}
	}
	if (rtn != -1) {
		ans.push_back(rtn);
		ps(rtn, rk, 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n;  cin >> n >> k;
		for (int i = 0; i <= 100; i++) {
			v[i].clear();
			for (int j = 0; j <= 100; j++) {
				d[i][j][0].clear();
				d[i][j][1].clear();
			}
		}	
		for (int i = 2; i <= n; i++) {
			cin >> pr[i];
			v[pr[i]].push_back(i);
		}
		ans.clear();
		dp(1); 
		ans.push_back(1);  ps(1, k, 1);
		cout << d[1][k][1].back().first << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}