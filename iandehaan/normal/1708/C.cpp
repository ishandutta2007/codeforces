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
		int n, q;
		cin >> n >> q;
		int a[n];
		rep(i, 0, n) cin >> a[i];

		int req = 0;
		string out;
		rep(i, 0, n) out.pb('1');
		for (int i = n-1; i >= 0; i--) {
			if (req >= a[i]) {
				// get this for free, req doesn't change
			} else {
				req++;
				if (req > q) {
					req = q;
					out[i] = '0';
				}
			}
		}

		cout << out << '\n';
	}
}