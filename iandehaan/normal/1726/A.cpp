#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		rep(i, 0, n) cin >> a[i];
		int out = a[n-1]-a[0];
		rep(i, 1, n) out = max(out, a[i]-a[0]);

		rep(i, 0, n-1) out = max(out, a[n-1]-a[i]);

		rep(i, 0, n-1) out = max(out, a[i]-a[i+1]);

		cout << out << '\n';
	}
}