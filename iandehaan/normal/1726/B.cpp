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
		int n, m;
		cin >> n >> m;

		if (n > m) {
			cout << "No\n";
		} else {
			if (n % 2 == 1) {
				//cout << "c1\n";
				cout << "Yes\n";
				rep(i, 0, n-1) cout << "1 ";
				cout << m - (n-1) << '\n';
			} else {
				int leftover = m - (n-2);
				if (leftover % 2 == 0) {
					cout << "Yes\n";
					// great!
					rep(i, 0, n-2) cout << "1 ";
					cout << leftover/2 << ' ' << leftover/2 << '\n';
				} else {
					cout << "No\n";
				}
			}
		}
	}
}