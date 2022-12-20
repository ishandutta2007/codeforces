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
		int n, x, y;
		cin >> n >> x >> y;
		if (x != 0 && y != 0) {
			cout << -1 << '\n';
			continue;
		}
		if (x == 0 && y == 0) {
			cout << -1 << '\n';
			continue;
		}

		if (x == 0) swap(x, y);

		if ((n-1) % x != 0) {
			cout << -1 << '\n';
			continue;
		}

		int curr = 0;
		int num = 0;
		for (int i = 0; num < (n-1); i += x) {
			if (i == x) i++;
			num += x;
			for (int j = 0; j < x; j++) cout << i+1 << ' ';
		}
		cout << '\n';
	}
}