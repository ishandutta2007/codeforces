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

	int n;
	cin >> n;
	int a[n];
	int cnt[3];
	rep(i, 0, 3) cnt[i] = 0;
	rep(i, 0, n) {
		cin >> a[i];
		a[i] %= 3;
		cnt[a[i]]++;
	}

	int out[n];

	if (cnt[0] <= n/2) {
		// z = 0
		int numzero = 0;
		rep(i, 0, n) {
			if (a[i] == 0) {
				numzero++;
				out[i] = 0;
			}
		}

		rep(i, 0, n) {
			if (a[i] == 0) continue;

			if (numzero < n/2) {
				numzero++;
				out[i] = 0;
			} else {
				out[i] = 1;
			}
		}

		cout << 0 << endl;
		rep(i, 0, n) cout << out[i];
		cout << endl;
	} else {
		// z = 2
		int numzero = 0;
		rep(i, 0, n) {
			if (a[i] != 0) {
				numzero++;
				out[i] = 0;
			}
		}

		rep(i, 0, n) {
			if (a[i] != 0) continue;

			if (numzero < n/2) {
				numzero++;
				out[i] = 0;
			} else {
				out[i] = 1;
			}
		}

		cout << 2 << endl;
		rep(i, 0, n) cout << out[i];
		cout << endl;
	}



}