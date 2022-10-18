#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long double K;
constexpr int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

constexpr int N = 2e5 + 5;

ii pt[N];

void solve() {
	int n, k;
	cin >> n >> k;
	FOR(i, 0, n) cin >> pt[i].X >> pt[i].Y;
	if(n <= k) {
		cout << "-1\n";
		return;
	}
	vector<ii> ans;
	sort(pt, pt + n);
	FOR(h, 0, k + 1) for(int j = n - 1; j >= n - k - 1; j--) {
		ii mid = {pt[h].X + pt[j].X, pt[h].Y + pt[j].Y};
		int zeps = 0, last = n - 1;
		FOR(i, 0, n) {
			ii d = {mid.X - pt[i].X, mid.Y - pt[i].Y};
			while(last >= 0 && pt[last] > d) last--;
			zeps += (last < 0) || (pt[last] != d);
			if(zeps > k) break;
		}
		if(zeps <= k) ans.PB(mid);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	// cout << (SZ(ans) ? "TAK\n" : "NIE\n");
	cout << SZ(ans) << '\n';
	TRAV(x, ans) {
		cout << (x.X == -1 ? "-" : "") << x.X / 2 << (x.X & 1 ? ".5" : ".0") << ' ';
		cout << (x.Y == -1 ? "-" : "") << x.Y / 2 << (x.Y & 1 ? ".5" : ".0") << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin >> tt;
	// FOR(te, 0, tt) {
	// 	// cout << "Case #" << te + 1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}