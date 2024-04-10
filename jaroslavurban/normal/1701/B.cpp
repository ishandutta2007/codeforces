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
	int n; cin >> n;
	vector<int> done(n + 1);
	cout << "2\n";
	for (int i = 1; i <= n; ++i) if (!done[i]) {
		for (int j = 1; j * i <= n; j *= 2) {
			done[i * j] = true;
			cout << i * j << ' ';
		}
	}
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}