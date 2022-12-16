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

// conditions that make it impossible
// 1. if a[i] > b[i]
// 2. if b[i-1] > b[i]+1 and a[i-1] < b[i-1]

#define MAXN 200'010
int n;
int a[MAXN];
int b[MAXN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 0, n) cin >> a[i];
		rep(i, 0, n) cin >> b[i];

		bool ok = true;
		rep(i, 0, n) {
			if (a[i] > b[i]) ok = false;
		}

		rep(i, 0, n) {
			int nxt = (i+1)%n;
			if (b[i] > b[nxt]+1 && a[i] < b[i]) ok = false;
		}

		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}