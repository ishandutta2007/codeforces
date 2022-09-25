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
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 11;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int a[maxn], b[maxn];
int v[maxn];

int f(int l, int r) {
	if (l == r) return 0;
	int m = (l + r) >> 1;
	int res = f(l, m) + f(m + 1, r);

	int i = l, j = m + 1, cnt = 0;
	while (i <= m || j <= r) {
		if (j > r || i <= m && b[i] <= b[j]) {
			v[cnt++] = b[i++];
		} else if (i > m || j <= r && b[j] < b[i]) {
			res += m - i + 1;
			v[cnt++] = b[j++];
		}
	}
	for (int i = l; i <= r; i++) b[i] = v[i - l];
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> a[i], a[i] = abs(a[i]);

		for (int i = 0; i < n; i++) b[i] = a[i];
		int ans = f(0, n - 1);
		for (int k = 0; k <= n; k++) {
			a[k] = -a[k];
			for (int i = 0; i < n; i++) b[i] = a[i];
			int nres = f(0, n - 1);
			if (nres > ans) a[k] = -a[k];
			else ans = nres;
		}
		
		cout << ans << endl;
	}

	return 0;
}