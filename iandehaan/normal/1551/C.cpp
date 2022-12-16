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
		string a[n];
		rep(i, 0, n) cin >> a[i];
		int out = 0;
		for (char c = 'a'; c <= 'z'; c++) {
			int amts[n];
			for (int i = 0; i < n; i++) {
				amts[i] = 0;
				for (char d : a[i]) {
					if (d == c) amts[i]++;
					else amts[i]--;
				}
			}
			sort(amts, amts+n);
			reverse(amts, amts+n);
			int sm = 0;
			int amt = 0;
			for (int i = 0; i < n; i++) {
				if (sm + amts[i] > 0) {
					sm += amts[i];
					amt++;
				}
			}
			out = max(out, amt);
		}
		cout << out << endl;
	}
}