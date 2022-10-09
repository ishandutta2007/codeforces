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

int n;
int a[200005];
vector<int> e[200005];
vector<int> v;

void dfs(int x, int p) {
	for (int y : e[x]) {
		if (y != p) {
			v.push_back(y);
			a[y] *= -1;

			dfs(y, x);
			v.push_back(x);
			a[x] *= -1;
			
			if (a[y] == -1) {
				v.push_back(y);
				v.push_back(x);

				a[x] *= -1;
				a[y] *= -1;
			}
		}
	}
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
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	v.push_back(1);
	// a[1] *= -1;
	dfs(1, 1);

	int y = e[1][0];

	if (a[1] == -1) {
		v.push_back(y);
		v.push_back(1);
		v.push_back(y);
	}

	for (int x : v) {
		cout << x << ' ';
	}
}