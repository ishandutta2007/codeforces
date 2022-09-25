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

const int maxn = 1 << 13;
const int inf = 1000000007;
const int mod = 1000000007;

int n, k;
int a[maxn];
int d[1 << 20], f[1 << 20];

bool reading() {
	if (!(cin >> n >> k)) return 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	return 1;
}

int fastsolve() {
	memset(d, 0, sizeof(d));
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			d[abs(a[i] - a[j])]++;
	for (int ans = 1;; ans++) {
		bool ok = 1;
		int s = 0;
		for (int i = 0; i < 1 << 20; i += ans) s += d[i];
		if (s > k * (k + 1) / 2) continue;
		s = 0;
		for (int i = 0; i < n; i++) {
			if (f[a[i] % ans] == ans) s++;
			if (s > k) { ok = 0; break; }
			f[a[i] % ans] = ans;
		}
		if (ok) return ans;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    

	while (reading()) cout << fastsolve() << endl;

	return 0;
}