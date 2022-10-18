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

int t[10];
int n, ile, sum;

bool bt(int kt) {
	if(kt == n) {
		if(ile == 0) return false;
		return sum == 0;
	}

	if(bt(kt + 1)) return true;

	ile++;
	sum -= t[kt];
	if(bt(kt + 1)) return true;
	sum += t[kt];

	sum += t[kt];
	if(bt(kt + 1)) return true;
	sum -= t[kt];
	ile--;
	return false;
}

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> t[i];
	ile = sum = 0;
	cout << (bt(0) ? "YES\n" : "NO\n");
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