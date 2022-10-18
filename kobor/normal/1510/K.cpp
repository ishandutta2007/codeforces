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

int n;

void op(vi &vec, int co) {
	if(co == 0){
		FOR(i, 0, n * 2) {
			swap(vec[i], vec[i + 1]);
			i++;
		}
	}
	else FOR(i, 0, n) swap(vec[i], vec[i + n]);
}

void solve() {
	cin >> n;
	vi star(n * 2);
	TRAV(x, star) cin >> x;
	int ans = INF;
	vi vec = star;
	FOR(i, 0, n * 6 + 5) {
		if(is_sorted(vec.begin(), vec.end())) {
			ans = min(ans, i);
			break;
		}
		op(vec, i & 1);
	}
	vec = star;
	FOR(i, 0, n * 6 + 5) {
		if(is_sorted(vec.begin(), vec.end())) {
			ans = min(ans, i);
			break;
		}
		op(vec, (i & 1) ^ 1);
	}
	cout << (ans == INF ? -1 : ans) << '\n';
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