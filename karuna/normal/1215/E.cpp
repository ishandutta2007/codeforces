#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
int A[404040];
ll cost[30][30];
ll dp[20][1<<20];
vector<int> v[30];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> A[i]; v[A[i]].push_back(i);
	}

	for (int i=1; i<=20; i++) {
		for (int j=1; j<i; j++) {
			for (int x : v[i]) {
				cost[i][j] += (ll)(v[j].end() - lower_bound(v[j].begin(), v[j].end(), x));
			}

			cost[j][i] = (ll)v[i].size() * v[j].size() - cost[i][j];
		}
	}

	for (int i=0; i<(1<<20); i++) {
		for (int j=0; j<20; j++) {
			dp[j][i] = 1LL<<60;
		}
	}

	for (int i=0; i<20; i++)
		dp[i][1<<i] = 0;

	for (int i=0; i<(1<<20); i++) {
		for (int j=0; j<20; j++) {
			if (!(i>>j&1)) continue;
			int tmp = i ^ (1<<j);

			for (int k=0; k<20; k++) {
				if (!(tmp>>k&1)) continue;
				dp[j][i] = min(dp[j][i], dp[k][tmp]);
			}

			for (int k=0; k<20; k++) {
				if (!(tmp>>k&1)) continue;
				dp[j][i] += (ll)cost[k+1][j+1];
			}
		}
	}

	ll ans = 1LL<<60;
	for (int i=0; i<20; i++) {
		ans = min(ans, dp[i][(1<<20)-1]);
	}

	cout << ans;
}