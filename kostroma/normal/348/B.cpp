#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
//#define FILENAME "1dembedding"
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
#else
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cin >> t;
    while (t--)
        solve();
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

#define int li

int n;
int a[100500];
vector<int> g[100500];

int maxSum[100500];
int haveLCM[100500];

int gcd (int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

int lcm (int q, int w) {
	return q / gcd(q, w) * w;
}

bool flag = true;

void dfs (int v, int p = -1) {
	if (g[v].size() == 1) {
		if (p == -1) {
			flag = false;
		}
		else {
			haveLCM[v] = 1;
			maxSum[v] = a[v];
			return;
		}
	}
	int LCM = 1;
	int cnt = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)
			continue;
		++cnt;
		dfs(to, v);
		if (maxSum[to] == 0) {
			maxSum[v] = 0;
			return;
		}
		LCM = lcm(LCM, haveLCM[to]);
		if (LCM > 1000000000) {
			maxSum[v] = 0;
			return;
		}
	}
	int dom = 1000000000;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)
			continue;
		int cur = LCM / haveLCM[to];
		dom = min(dom, maxSum[to] / cur);
	}
	haveLCM[v] = LCM * cnt;
	maxSum[v] = dom;
	//cout << v << ' ' << LCM << ' ' << dom << "\n";
}

void solve() {
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int q, w;
		cin >> q >> w;
		--q; --w;
		g[q].push_back(w);
		g[w].push_back(q);
	}

	dfs(0);

	if (!flag)
		sum -= a[0];
	cout << sum - maxSum[0] * haveLCM[0] << "\n";

}