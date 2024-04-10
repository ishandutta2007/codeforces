#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[3005], b[3005];
ll dp[3005][3005];

basic_string<pair<ll, int>> eneg[3005], epos[3005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i] -= i;
		b[i] = a[i];
	}
	sort(b, b+n);

	memset(dp, 63, sizeof(dp));
	dp[0][0] = 0;

	for (int i=0; i<n; i++) {
		int bkind = lower_bound(b, b+n, a[i]) - b;
		for (int x=0; x<3005; x++) {
			eneg[x].clear();
			eneg[x].shrink_to_fit();
			epos[x].clear();
			epos[x].shrink_to_fit();
		}

		for (int j=0; j<n; j++) {
			// zadnji je imao vrednost b[j], sad ovaj treba da ima b[k], k >= j
			if (j < bkind) {
				eneg[bkind] += {dp[i][j] - a[i], 1};
				eneg[n] += {dp[i][j] - a[i], -1};

				epos[j] += {dp[i][j] + a[i], 1};
				epos[bkind] += {dp[i][j] + a[i], -1};
			} else {
				eneg[j] += {dp[i][j] - a[i], 1};
				eneg[n] += {dp[i][j] - a[i], -1};
			}
		}

		multiset<ll> pq_pos, pq_neg;

		for (int k=0; k<n; k++) {

			for (auto [v, t] : epos[k]) {
				if (t == 1)
					pq_pos.insert(v);
				else
					pq_pos.erase(pq_pos.find(v));
			}

			for (auto [v, t] : eneg[k]) {
				if (t == 1)
					pq_neg.insert(v);
				else
					pq_neg.erase(pq_neg.find(v));
			}

			if (pq_pos.size())
				dp[i+1][k] = min(dp[i+1][k], *pq_pos.begin() - b[k]);
			if (pq_neg.size())
				dp[i+1][k] = min(dp[i+1][k], *pq_neg.begin() + b[k]);

			// cerr << dp[i+1][k] << ' ';
		}
		// cerr << '\n';
	}

	cout << *min_element(dp[n]+0, dp[n]+n) << '\n';
}