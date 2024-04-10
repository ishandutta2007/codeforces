#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> e[200005];
long long a[200005], sol = -999'999'999'999'999'999ll;
long long sm[200005], mx[200005];

// resimo ako je x lca za ta dva cvora
void dfs(int x, int p) {
	mx[x] = -999'999'999'999'999'999ll;
	sm[x] = 0;
	vector<long long> gg;
	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x);
			sm[x] += sm[y];
			mx[x] = max(mx[x], mx[y]);
			gg.push_back(mx[y]);
		}
	}
	sm[x] += a[x];
	mx[x] = max(mx[x], sm[x]);

	if (gg.size() > 1) {
		nth_element(gg.begin(), gg.end() - 2, gg.end());
		sol = max(sol, gg[gg.size()-1] + gg[gg.size()-2]);
	}	
}

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 1);
	if (sol == -999'999'999'999'999'999ll) {
		cout << "Impossible";
	} else {
		cout << sol;
	}
}