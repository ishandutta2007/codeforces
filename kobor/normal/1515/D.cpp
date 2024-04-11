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
	 int n, l, r;
	 cin >> n >> l >> r;
	 vi cnt[2];
	 cnt[0].resize(n), cnt[1].resize(n);
	 int diff = abs(l - r) / 2, rest = abs(l - r);
	 int ktore = (r > l);
	 FOR(i, 0, n) {
		 int a;
		 cin >> a;
		 cnt[i >= l][a - 1]++;
	 }
	 FOR(i, 0, n) {
		 int ile = min(cnt[0][i], cnt[1][i]);
		 FOR(j, 0, 2) cnt[j][i] -= ile;
		 while(cnt[ktore][i] > 1 && diff > 0) {
			 cnt[ktore][i] -= 2;
			 diff--;
		 }
		 FOR(j, 0, 2) rest += cnt[j][i];
	 }
	 cout << rest / 2 << '\n';
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