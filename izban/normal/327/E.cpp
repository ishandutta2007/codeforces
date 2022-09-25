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

const int maxn = 24;
const int inf = 1000000007;
const int mod = 1000000007;

int n, k;
int a[maxn], b[2];
int d[1 << maxn];
int sum[1 << maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> k;
	for (int i = 0; i < k; i++) cin >> b[i];

	d[0] = 1; sum[0] = 0;
	for (int mask = 0; mask < 1 << n; mask++) {
		for (int i = 0; i < n; i++) if (mask & (1 << i)) { sum[mask] = min(sum[mask ^ (1 << i)] + a[i], inf); break; }

		bool f = 0;
		for (int i = 0; i < k; i++) if (sum[mask] == b[i]) f = 1;
		if (f) {d[mask] = 0; continue;}
		for (int i = 0; i < n; i++) {
			if (!(mask & (1 << i))) {
				int newmask = mask ^ (1 << i);
				d[newmask] += d[mask];
				if (d[newmask] >= mod) d[newmask] -= mod;
			}
		}
	}
	cout << d[(1 << n) - 1] << endl;

	return 0;
}