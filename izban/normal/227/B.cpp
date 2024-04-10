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

using namespace std;

#define ll long long


const int maxn = 1 << 17;

ll n, m, x, ansa, ansb, a[maxn], b[maxn], c[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i]] = i+1;
		c[a[i]] = n-b[a[i]]+1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		ansa += b[x];
		ansb += c[x];
	}

	printf("%I64d %I64d\n", ansa, ansb);

	return 0;
}