#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int gcd(int a, int b) {
	int t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int n;
int a[200005];
vector<int> e[200005];

int st[200005], sttt;
int changes[30], chhh;
int sol[200005];

void dfs(int x, int p) {
	// add
	++sttt;
	st[sttt] = gcd(st[sttt-1], a[x]);

	vector<int> changes_cache(changes, changes+chhh+1);

	for (int i=1; i<=chhh; i++) {
		changes[i] = gcd(changes[i], a[x]);
	}
	
	if (st[sttt] != st[sttt-1]) {
		chhh++;
		changes[chhh] = st[sttt-1];
	}

	// process
	for (int i=1; i<=chhh; i++) {
		sol[x] = max(sol[x], changes[i]);
	}
	sol[x] = max(sol[x], st[sttt]);

	// recurse
	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x);
		}
	}
	
	// remove
	copy(changes_cache.begin(), changes_cache.end(), changes);
	chhh = changes_cache.size() - 1;
	--sttt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	fill(sol+1, sol+n+1, 1);
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(1, 1);
	sol[1] = a[1];
	for (int i=1; i<=n; i++) {
		cout << sol[i] << ' ';
	}



}