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

long long tot = 0;

int n;
vector<int> e[100005];

double dfs(int x, int p, int d) {
	int c = 0;
	double sum = 0;
	for (int y : e[x]) {
		if (y != p) {
			double r = dfs(y, x, d+1);
			sum += r;
			c++;
		}
	}
	if (c == 0) {
		return d;
	}

	return sum / c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	cout.precision(20);
	cout << fixed << dfs(1, 1, 0);
}