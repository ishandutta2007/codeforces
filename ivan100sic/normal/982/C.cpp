#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
vector<int> e[100005];

int sz[100005];

void dfs(int x, int p) {
	sz[x] = 1;
	for (int y : e[x])
		if (y != p) {
			dfs(y, x);
			sz[x] += sz[y];
		}
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	if (n % 2 == 1)
		return cout << -1, 0;

	for (int i=2; i<=n; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	dfs(1, 1);

	int c = 0;
	for (int i=2; i<=n; i++)
		c += 1 - sz[i] % 2;

	cout << c << '\n';
}