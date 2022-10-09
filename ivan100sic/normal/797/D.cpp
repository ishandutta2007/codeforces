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

struct node {
	int lnode, rnode, x;
};

node a[100005];
set<int> goodvals;

void dfs(int node, int l, int r) {

	if (node == -1) {
		return;
	}

	// cerr << node << ' ' << l << ' ' << r << '\n';

	int x = a[node].x;

	if (l <= x && x <= r) {
		goodvals.insert(x);
	}

	dfs(a[node].lnode, l, min(r, x-1));
	dfs(a[node].rnode, max(l, x+1), r);
}

bool not_root[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	for (int i=1; i<=n; i++) {
		cin >> a[i].x >> a[i].lnode >> a[i].rnode;
		if (a[i].lnode != -1) {
			not_root[a[i].lnode] = true;
		}
		if (a[i].rnode != -1) {
			not_root[a[i].rnode] = true;
		}
	}

	for (int r=1; r<=n; r++) {
		if (!not_root[r]) {
			dfs(r, -2'000'000'000, 2'000'000'000);
			break;
		}
	}

	int bad = 0;
	for (int i=1; i<=n; i++) {
		if (goodvals.count(a[i].x) == 0) {
			bad++;
		} else {
			// cerr << i << '\n';
		}
	}
	
	cout << bad;
}