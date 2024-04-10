#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int n;
int a[200005];
vector<pair<int, int>> e[200005];
int sol[200005];

int xs[200005], ss;
long long ds[200005];

void dfs(int x, long long depth) {
	xs[ss] = x;
	ds[ss] = depth;
	ss++;

	sol[x]++;

	for (auto p : e[x]) {
		dfs(p.first, depth + p.second);
		sol[x] += sol[p.first];
	}

	// reject
	int pos = lower_bound(ds, ds+ss, depth-a[x]) - ds;
	if (pos > 0) {
		sol[xs[pos-1]]--;
	}

	ss--;
}


int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=2; i<=n; i++) {
		int x, w;
		cin >> x >> w;
		e[x].push_back({i, w});
	}

	dfs(1, 0);

	for (int i=1; i<=n; i++) {
		cout << sol[i]-1 << ' ';
	}
}