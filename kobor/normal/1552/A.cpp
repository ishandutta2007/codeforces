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
	int n;
	cin >> n;
	string s;
	cin >> s;
	TRAV(x, s) x -= 'a';
	vi cnt(200);
	TRAV(x, s) cnt[x]++;
	int akt = 0, gut = 0;
	TRAV(x, s) {
		while(cnt[akt] == 0) akt++;
		if(akt == x) gut++;
		cnt[akt]--;
	}
	cout << n - gut << '\n';
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