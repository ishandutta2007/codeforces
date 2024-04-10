#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[1000005], m, n;
basic_string<int> e[1000005];
bool vis[1000005];

void dfs(int x, basic_string<int>& v) {
	v += x;
	vis[x] = 1;
	for (int y : e[x])
		if (!vis[y])
			dfs(y, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			basic_string<int> v, w;
			dfs(i, v);
			for (int x : v)
				w += a[x];
			sort(w.begin(), w.end(), greater<int>());
			sort(v.begin(), v.end());
			int j = 0;
			for (int x : v) {
				a[x] = w[j++];
			}
		}
	}
	for (int i=1; i<=n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}