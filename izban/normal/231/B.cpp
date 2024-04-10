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

int n, d, l, sum, a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n >> d >> l;
	for (int i = 0; i < n; i++)
		a[i] = i%2 ? 1 : l, sum += i % 2 ? -a[i] : a[i];

	for (int i = 0; i < n; i++) {
		if (!(i & 1) && (sum > d))
			a[i] -= min(l - 1, sum - d), sum -= min(l - 1, sum - d);
		if ((i & 1) && (sum > d))
			a[i] += min(l - 1, sum - d), sum -= min(l - 1, sum - d);
	}

	if (d != sum) {
		cout << -1;
	} else {
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
	}


	return 0;
}