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
	vector<int> a(n);
	for (int& v : a) cin >> v;
	reverse(a.begin(), a.end());
	int zeros = 0;
	while (a.size() && a.back() == 0) { ++zeros; a.pop_back(); }
	reverse(a.begin(), a.end());
	while (a.size() > 1) {
		vector<int> na;
		if (zeros) na.push_back(a[0]);
		zeros = max(0, zeros - 1);
		for (int i = 0; i + 1 < a.size(); ++i) {
			if (a[i + 1] != a[i]) na.push_back(a[i + 1] - a[i]);
			else ++zeros;
		}
		swap(a, na);
		sort(a.begin(), a.end());
	}
	if (a.size()) cout << a[0] << '\n';
	else cout << "0\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}