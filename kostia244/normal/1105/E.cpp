#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long
using namespace std;
//1s
int n, m, t;
long long g[50];
string s;
map<string, int> vid;
vector<int> vs;

int getid(string s) {
	if (vid.find(s) == vid.end())
		vid[s] = vid.size();
	return vid[s];
}

void connect() {
	for (size_t i = 0; i < vs.size(); i++)
		for (size_t j = i + 1; j < vs.size(); j++)
			g[vs[i]] |= 1ll << vs[j], g[vs[j]] |= 1ll << vs[i];
	vs.clear();
}

int ok(long long mask, int j) {
	if((mask >> j)&1)
		return 0;
	for (int i = 0; i < m; i++)
		if (((mask >> i) & 1) && ((g[i] >> j) & 1))
			return 0;
	return 1;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		g[i] |= 1 << i;
	while (n--) {
		cin >> t;
		if (t == 1)
			connect();
		else {
			cin >> s;
			vs.erase(unique(vs.begin(), vs.end()), vs.end());
			vs.push_back(getid(s));
		}
	}
	connect();
	int SL = m / 2;
		int SR = m - SL;
		vector<int> dp1(1 << SL, 0);
		for (long long mask = 0; mask < (1LL << SL); mask++) {
			for (int add = 0; add < SL; add++) {
				if ((mask >> add) & 1)
					continue;
				bool canAdd = true;
				for (int i = 0; i < SL; i++)
					if ((mask >> i) & 1) {
						canAdd &= ~((g[i] >> add) & 1);
					}
				dp1[mask | (1 << add)] = max(dp1[mask | (1 << add)],
						dp1[mask] + canAdd);
			}
		}
		vector<int> dp2(1 << SR, 0);
		for (long long mask = 0; mask < (1LL << SR); mask++) {
			for (int add = 0; add < SR; add++) {
				if ((mask >> add) & 1)
					continue;
				bool canAdd = true;
				for (int i = 0; i < SR; i++)
					if ((mask >> i) & 1) {
						canAdd &= ~((g[i + SL] >> (add + SL)) & 1);
					}
				dp2[mask | (1 << add)] = max(dp2[mask | (1 << add)],
						dp2[mask] + canAdd);
			}
		}
		int ans = 0;
		for (long long mask1 = 0; mask1 < (1LL << SL); mask1++) {
			long long mask = (1LL << m) - 1;
			for (int i = 0; i < SL; i++)
				if ((mask1 >> i) & 1) {
					mask &= ~g[i];
				}
			ans = max(ans, dp1[mask1] + dp2[mask >> SL]);
		}
		cout << ans;
}