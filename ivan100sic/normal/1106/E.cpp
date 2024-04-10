#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
int sk[100005];
int wt[100005];
ll dp[100005][205];

struct event {
	int tip, w, d;
};

basic_string<event> e[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<k; i++) {
		int s, t, d, w;
		cin >> s >> t >> d >> w;
		e[s] += {1, w, d};
		e[t+1] += {-1, w, d};
	}

	{
		multiset<pair<int, int>> ms;
		for (int i=1; i<=n; i++) {
			// obradi evente
			for (auto [tip, w, d] : e[i]) {
				if (tip == 1) {
					ms.insert({w, d});
				} else {
					ms.erase(ms.find({w, d}));
				}
			}
			if (ms.size()) {
				auto [w, d] = *ms.rbegin();
				sk[i] = d;
				wt[i] = w;
			}
		}
	}

	memset(dp, 63, sizeof(dp));
	dp[n+1][0] = 0;
	ll sol = 123123123123123123ll;
	for (int i=n; i>=1; i--) {
		for (int j=0; j<=m; j++) {
			// distract?
			if (j)
				dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
			// don't
			if (sk[i]) {
				dp[i][j] = min(dp[i][j], dp[sk[i]+1][j] + wt[i]);
			} else {
				dp[i][j] = min(dp[i][j], dp[i+1][j]);
			}
			if (i == 1)
				sol = min(sol, dp[i][j]);
		}
	}

	cout << sol << '\n';
}