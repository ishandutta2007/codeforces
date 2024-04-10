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
		int n, k;
		cin >> n >> k;
		int mx[k];
		rep(i, 0, k) mx[i] = 0;
		rep(i, 0, n) {
			int x;
			cin >> x;
			mx[i%k] = max(mx[i%k], x);
		}

		ll out = 0;
		rep(i, 0, k) out += mx[i];
		cout << out << endl;
	}
}