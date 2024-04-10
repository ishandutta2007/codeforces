#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int u[200005], v[200005], sol[200005];
basic_string<int> e[200005];
int a[200005];
bool relaxed[200005];

bool cmp(int x, int y) {
	return e[x].size() > e[y].size();
}

void dfs(int x, int i) {
	int c = 1;
	for (int j : e[x]) {
		if (j == i)
			continue;
		int y = u[j] ^ v[j] ^ x;
		if (c == sol[i])
			c++;
		sol[j] = relaxed[x] ? 1 : c++;
		dfs(y, j);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++) {
		cin >> u[i] >> v[i];
		e[u[i]] += i;
		e[v[i]] += i;
	}

	iota(a, a+n, 1);
	sort(a, a+n, cmp);
	for (int i=0; i<k; i++)
		relaxed[a[i]] = 1;
	int r = e[a[k]].size();
	cout << r << '\n';

	dfs(1, 0);
	for (int i=1; i<n; i++)
		cout << sol[i] << " \n"[i == n-1];
}