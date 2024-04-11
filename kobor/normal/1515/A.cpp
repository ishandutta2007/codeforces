#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef double K;
constexpr int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

void solve() {
	int n, d;
	cin >> n >> d;
	vi arr(n);
	TRAV(x, arr) cin >> x;
	int sum = 0;
	FOR(i, 0, n) {
		sum += arr[i];
		if(sum == d) {
			if(i + 1 == n) {
				cout << "NO\n";
				return;
			}
			swap(arr[i], arr[i + 1]);
			break;
		}
	}
	cout << "YES\n";
	TRAV(x, arr) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt) {
		// cout << "Case #" << te + 1 << ": ";
		solve();
	}
	// solve();
	return 0;
}