#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool v[200005];
int n, a[200005], b[200005];
basic_string<int> e[200005], sol;

void dfs(int x) {
	if (v[x])
		return;
	v[x] = 1;
	sol += x;
	for (int y : e[x])
		dfs(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
		a[i] = x;
		b[i] = y;
	}
	dfs(1);
	if (set<int>({sol[1], sol[2]}) != set<int>({a[1], b[1]}))
		reverse(sol.begin(), sol.end());
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}