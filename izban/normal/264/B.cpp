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

int n, a[maxn], d[maxn], ans;
int last[maxn];
vector<int> nxt[maxn];
bool pr[maxn];

void precalc() {
	for (int i = 0; i < maxn; i++) pr[i] = 1;

	for (int i = 2; i * i < maxn; i++) {
		if (!pr[i]) continue;
		for (int j = i * i; j < maxn; j += i)
			pr[j] = 0;
	}
}

void foo(int i, int x) {
	nxt[last[x]].push_back(i);
	last[x] = i;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    precalc();

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) d[i] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int x = 2; x * x <= a[i]; x++) if (a[i] % x == 0) {
			d[i] = max(d[i], d[last[x]] + 1);
			d[i] = max(d[i], d[last[a[i] / x]] + 1);
			last[x] = last[a[i] / x] = i;
			//foo(i, x);
			//if (x * x != a[i]) foo(i, a[i] / x);
		}
		ans = max(ans, d[i]);
		last[a[i]] = i;
	}

	/*for (int i = 1; i <= n; i++) d[i] = 1;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < nxt[i].size(); j++)
			d[nxt[i][j]] = max(d[nxt[i][j]], d[i] + 1);
		ans = max(ans, d[i]);
	}*/

	cout << ans;

	return 0;
}