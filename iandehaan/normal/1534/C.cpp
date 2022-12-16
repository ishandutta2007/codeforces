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

#define MAXN 400010

int par[MAXN];
int getPar(int x) {
	if (par[x] == x) return x;
	return par[x] = getPar(par[x]);
}

void Union(int x, int y) {
	par[getPar(x)] = getPar(y);
}
constexpr ll mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		rep(i, 0, n) par[i] = i;

		map<int, int> seen;
		int a[n][2];
		rep(i, 0, n) {
			cin >> a[i][0];
		} 
		rep(i, 0, n) cin >> a[i][1];
		rep(i, 0, n) {
			if (seen.count(a[i][0]) != 0) {
				Union(i, seen[a[i][0]]);
			}
			if (seen.count(a[i][1]) != 0) {
				Union(i, seen[a[i][1]]);
			}

			seen[a[i][0]] = i;
			seen[a[i][1]] = i;
		}

		ll out = 1;
		rep(i, 0, n) {
			if (getPar(i) == i) {
				out *= 2;
				out %= mod;
			}
		}
		cout << out << endl;
	}
}