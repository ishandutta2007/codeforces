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

const int N = 510;

int f[N][N];
int id[N][N];
int sz[N * N];
int here[N * N];
int all, in;

void dfs(int i, int j, int _id) {
	if (id[i][j]) return;
	id[i][j] = _id;
	if (f[i - 1][j]) dfs(i - 1, j, _id);
	if (f[i + 1][j]) dfs(i + 1, j, _id);
	if (f[i][j - 1]) dfs(i, j - 1, _id);
	if (f[i][j + 1]) dfs(i, j + 1, _id);
}

void add(int i, int j) {
	if (!f[i][j]) return;
	int _id = id[i][j];
	if (!here[_id]) all += sz[_id];
	++here[_id];
}

void rem(int i, int j) {
	if (!f[i][j]) return;
	int _id = id[i][j];
	--here[_id];
	if (!here[_id]) all -= sz[_id];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<string> s(n);
	forn(i, 0, n) cin >> s[i];
	forn(i, 0, n) forn(j, 0, n) f[i + 1][j + 1] = s[i][j] == '.';
	fore(i, 1, n) fore(j, 1, n) if (f[i][j] && id[i][j] == 0) {
		dfs(i, j, i * N + j);
	}
	int ans = 0;
	fore(i, 1, n) fore(j, 1, n) sz[id[i][j]]++;
	for (int i = 1; i + k - 1 <= n; ++i) {
		forn(t, 0, N * N) here[t] = 0;
		all = 0, in = 0;
		for (int i1 = i - 1; i1 <= i + k; ++i1)
			for (int j1 = 0; j1 <= k + 1; ++j1)
				add(i1, j1);
		rem(i - 1, 0);
		rem(i - 1, k + 1);
		rem(i + k, 0);
		rem(i + k, k + 1);
		for (int i1 = i; i1 < i + k; ++i1)
			for (int j1 = 1; j1 <= k; ++j1)
				if (f[i1][j1])
					++in;
		ans = max(ans, all - in + k * k);
		for (int j = 2; j + k - 1 <= n; ++j) {
			rem(i - 1, j - 1);
			rem(i + k, j - 1);
			for (int t = i; t < i + k; ++t) rem(t, j - 2);
			add(i - 1, j + k - 1);
			add(i + k, j + k - 1);
			for (int t = i; t < i + k; ++t) add(t, j + k);
			for (int t = i; t < i + k; ++t) {
				if (f[t][j - 1]) --in;
				if (f[t][j + k - 1]) ++in;
			}
			ans = max(ans, all - in + k * k);
		}
	}
	cout << ans << '\n';
	return 0;
}