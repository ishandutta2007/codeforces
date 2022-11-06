#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200200;
typedef array<array<int, N>, 2> F;

void ProGamerMove() {
	int n; cin >> n;
	F a[2];
	int cnt[2] = {};
	for (int t = 0; t < 2; ++t) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j)
				cin >> a[t][i][j];
			cnt[t] += accumulate(a[t][i].begin(), a[t][i].begin() + n, 0);
		}
	}
	if (cnt[0] != cnt[1]) { cout << "-1\n"; return; }
	cnt[0] = cnt[1] = 0;
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		cnt[0] += a[0][0][i] - a[1][0][i];
		cnt[1] += a[0][1][i] - a[1][1][i];
		if (cnt[0] < 0 && cnt[1] > 0) {
			int both = min(-cnt[0], cnt[1]);
			res += both;
			cnt[0] += both, cnt[1] -= both;
		} else if (cnt[0] > 0 && cnt[1] < 0) {
			int both = min(cnt[0], -cnt[1]);
			res += both;
			cnt[0] -= both, cnt[1] += both;
		}
		res += abs(cnt[0]) + abs(cnt[1]);
	}
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	//cin >> tc;
	while (tc--) ProGamerMove();
}