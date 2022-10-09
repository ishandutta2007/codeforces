#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int n, m;
vector<int> e[200005];

int ed, ve;
int maxdeg;

int v[200005];

void dfs(int x) {
	v[x] = 1;
	ve++;
	ed += e[x].size();
	maxdeg = max(maxdeg, (int)e[x].size());
	for (int y : e[x]) {
		if (!v[y]) {
			dfs(y);
		}
	}
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	int c = 0;

	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			ed = ve = maxdeg = 0;
			dfs(i);
			if (ed == 2 * ve && maxdeg == 2) {
				c++;
			}
		}
	}

	cout << c;
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}