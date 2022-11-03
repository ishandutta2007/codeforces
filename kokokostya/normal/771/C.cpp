#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>

using namespace std;

long long n, k;
vector< vector<int> > g;
vector<bool> used;
long long ans = 0;
vector<long long> sz;

void get_sz(int v) {
	sz[v] = 1;
	used[v] = 1;
	for(int i : g[v])
		if (!used[i]) {
			get_sz(i);
			sz[v] += sz[i];
		}
	return;
}

vector<long long> dfs(int v) {
	vector<long long> a(k + 1);
	used[v] = 1;
	vector< vector<long long> > res;
	for (int i : g[v]) {
		if (!used[i]) {
			vector<long long> b = dfs(i);
			res.push_back(b);
			for (int j = 0; j <= k; j++) {
				a[j] += b[j];
			}
			ans += 2 * (sz[v] - sz[i] - 1) * b[k];
		}
	}
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < k; j++) {
			for (int f = 0; f < k; f++) {
				ans += ((j + f + 2 - 1) / k + 1) * (a[j] - res[i][j]) * res[i][f];
			}
		}
	}
	long long ws = a[k - 1];
	for (int i = k - 1; i >= 0; i--) {
		a[(i + 1)] += a[i];
		a[i] = 0;
	}
	a[0] = ws;
	for (int i = 1; i <= k; i++)
		ans += 2 * a[i];
	a[0]++;
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	g.resize(n);
	for (long long i = 0; i < n - 1; i++) {
		long long a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	used.resize(n);
	sz.resize(n);
	get_sz(0);
	used.assign(n, 0);
	dfs(0);
	cout << ans / 2;
	return 0;
}