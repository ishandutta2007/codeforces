#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, cnt;
basic_string<int> e[100005];
int c[100005];

void dfs(int x, int p, int mac) {
	if (!c[x])
		mac = 0;
	else
		mac++;

	if (mac > m)
		return;

	if (e[x].size() == 1 && x != 1)
		cnt++;

	for (int y : e[x])
		if (y != p)
			dfs(y, x, mac);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> c[i];
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	dfs(1, 1, 0);
	cout << cnt;
}