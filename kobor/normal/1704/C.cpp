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

int pro(ii &a) {
	int type = a.X;
	int len = a.Y;
	return (type == 0 ? len * 2 : len);
}

void solve() {
	int n, m, ans = 0;
	cin >> n >> m;
	vi arr(m);
	TRAV(x, arr) cin >> x;
	TRAV(x, arr) x--;
	sort(arr.begin(), arr.end());
	priority_queue<pair<int, ii>> q;
	FOR(i, 0, m) {
		int len = (1ll * arr[(i + 1) % m] - 1 - arr[i] + n + n) % n;
		ii akt = {1, len};
		q.push({pro(akt), akt});
	}
	FOR(day, 0, n) {
		if(q.empty()) break;
		ii akt = q.top().Y;
		q.pop();
		int len = akt.Y;
		if(akt.X == 0) ans += min(len, day);
		else {
			if(day * 2 >= len) ans += len, day--;
			else {
				ans += day;
				ii nowy = {0, len - day - 1};
				q.push({pro(nowy), nowy});
			}
		}
	}
	cout << ans + m << '\n';
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