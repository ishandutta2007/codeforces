#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

vector<char> ans;
set<int> used;

int n;
vector<vector<bool>> e;

void dfs(int i) {
	if (used.count(i)) return;
	used.insert(i);
	bool edges = false;
	forn(j, 0, n) if (e[i][j]) edges = true;
	if (!edges) return;
	bool isa = false, isc = false;
	forn(j, 0, n) if (e[i][j]) {
		if (ans[j] == 'a') isa = true;
		if (ans[j] == 'c') isc = true;
	}
	if (isa) {ans[i] = 'c';
	} else ans[i] = 'a';
	forn(j, 0, n) if (e[i][j]) dfs(j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> n >> m;
	ans.resize(n);
	forn(i, 0, n) ans[i] = 'b';
	e.resize(n);
	forn(i, 0, n) e[i].resize(n);
	forn(i, 0, n) forn(j, 0, n) e[i][j] = true;
	forn(i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		e[a][b] = false;
		e[b][a] = false;
	}
	forn(i, 0, n) e[i][i] = false;
	forn(i, 0, n) dfs(i);
	forn(i, 0, n) forn(j, 0, n) {
		if ((ans[i] == 'a' && ans[j] == 'c' || ans[i] == 'c' && ans[j]
		== 'a') != e[i][j]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	forn(i, 0, n) cout << ans[i];
	cout << '\n';
	return 0;
}