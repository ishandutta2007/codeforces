#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m = inf, k, a[maxn], f[maxn];

void dfs(int v) {
	if (f[v]) return;
	f[v] = 1;
	for (int i = 0; i <= min(v, n); i++)
		if (2 * n - 1 >= v - i + n - i) 
			dfs(v - i + n - i);
	m = min(m, v);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++) {
		cin >> a[i];
		k += a[i] < 0;
		a[i] = abs(a[i]);
	}
	sort(a, a + 2 * n - 1);
	dfs(k);
	int ans = 0;
	for (int i = 0; i < m; i++)
		ans -= a[i];
	for (int i = m; i < 2 * n - 1; i++)
		ans += a[i];
	cout << ans << endl;

	return 0;
}