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
	 int n, m, d;
	 cin >> n >> m >> d;
	 vi blocks(n), ans(n);
	 TRAV(x, blocks) cin >> x;
	 set<ii> towers;
	 FOR(i, 0, m) towers.insert({0, i + 1});
	 FOR(i, 0, n) {
		 auto v = *towers.begin();
		 towers.erase(towers.begin());
		 v.X += blocks[i];
		 ans[i] = v.Y;
		 towers.insert(v);
	 }
	 if((*prev(towers.end())).X - (*towers.begin()).X > d) {
		 cout << "NO\n";
	 }
	 else {
		 cout << "YES\n";
		 TRAV(x, ans) cout << x << ' ';
		 cout << '\n';
	 }
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