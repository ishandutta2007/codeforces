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
#include <assert.h>
#include <memory.h>

using namespace std;

#define ll long long


#pragma comment(linker, "/STACK:64000000")
const int maxn = 1 << 17, maxk = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;

int n, k;
int a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	while (cin >> n >> k) {
		for (int i = 1; i < n; i++) a[i] = 1; a[n] = 0;
		for (int it = 0; it < k; it++) {
			for (int i = 1; i <= n; i++) {
				if (a[i] == n - i)
					cout << n << " ";
				else if (a[i] * 2 <= n - i)
					cout << i << " ", a[i] *= 2;
				else cout << i + a[i] << " ", a[i] = n - i;
			}
			cout << endl;
		}
	}

	return 0;
}