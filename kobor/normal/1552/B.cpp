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

vector<vi> ranks;

bool better(int a, int b) {
	int pts = 0;
	FOR(i, 0, 5) if(ranks[a][i] < ranks[b][i]) pts++;
	return pts >= 3;
}

void solve() {
	int n;
	cin >> n;
	ranks.clear();
	FOR(i, 0, n) {
		vi xd(5);
		TRAV(x, xd) cin >> x;
		ranks.PB(xd);
	}
	int gosc = 0;
	FOR(i, 1, n) {
		if(better(i, gosc)) gosc = i;
	}
	FOR(i, 0, n) {
		if(i == gosc) continue;
		if(better(i, gosc)) {
			gosc = -2;
			break;
		}
	}
	cout << gosc + 1 << '\n';
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