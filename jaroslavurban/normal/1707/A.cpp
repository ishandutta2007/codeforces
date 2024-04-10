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

void ProGamerMove() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	string res(n, '0');
	for (int& v : a) cin >> v;
	for (int mq = 0, i = n - 1; i >= 0; --i) {
		if (a[i] <= mq) {
			res[i] = '1';
		} else if (mq < q) {
			++mq;
			res[i] = '1';
		}
	}
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}