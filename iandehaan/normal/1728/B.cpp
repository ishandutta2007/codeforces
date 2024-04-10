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
		if (n % 2 == 0) {
			for (int i = n-2; i >= 1; i--) cout << i << ' ';
			cout << n-1 << ' ' << n << endl;
		} else {
			cout << 1 << ' ' << 2 << ' ' << 3 << ' ';
			for (int i = n-2; i >= 4; i--) cout << i << ' ';
			cout << n-1 << ' ' << n << endl;
		}
	}
}