#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[1000005], comp, sve;
int self[1000005];

bool vis[1000005];

void dfs(int x) {
	vis[x] = 1;
	comp += x;
	for (int y : e[x])
		if (!vis[y])
			dfs(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		if (x == y)
			self[x]++;
		else {
			e[x] += y;
			e[y] += x;
		}
	}

	int jedan = 0;
	for (int i=1; i<=n; i++) {
		if (!vis[i] && (i == 1 || self[i] || e[i].size())) {
			comp = {};
			dfs(i);
			int odd = 0;
			for (int x : comp) {
				if (e[x].size() % 2) {
					odd++;
				}
			}
			jedan = odd;
			sve += max(odd, 2);
		}
	}

	if (sve.size() == 1) {
		cout << jedan/2 << '\n';
	} else {
		cout << accumulate(sve.begin(), sve.end(), 0) / 2 << '\n';
	}
}