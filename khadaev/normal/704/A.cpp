#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> tp(q), x(q);
	forn(i, 0, q) cin >> tp[i] >> x[i];
	forn(i, 0, q) if (tp[i] != 3) --x[i];
	vector<int> rd(q, INF);
	queue<int> rest;
	int read = 0;
	forn(i, 0, q) {
		if (tp[i] == 1) rest.push(i);
		if (tp[i] == 3) {
			while (x[i] > read && !rest.empty()) {
				++read;
				rd[rest.front()] = i;
				rest.pop();
			}
		}
	}
	vector<vector<int>> rest2(n);
	forn(i, 0, q) {
		if (tp[i] == 1) rest2[x[i]].eb(i);
		if (tp[i] == 2) {
			for (int j : rest2[x[i]])
				rd[j] = min(rd[j], i);
			rest2[x[i]].clear();
		}
	}
	vector<int> ch(q);
	forn(i, 0, q) if (tp[i] == 1) {
		//cerr << i << ' ' << rd[i] << '\n';
		++ch[i];
		if (rd[i] != INF) --ch[rd[i]];
	}
	int ans = 0;
	forn(i, 0, q) {
		ans += ch[i];
		cout << ans << '\n';
	}
	return 0;
}