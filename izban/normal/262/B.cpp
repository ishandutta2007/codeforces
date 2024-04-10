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

int n, k, a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> k) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (k && a[i] < 0) {
				a[i] = -a[i];
				k--;
			}
		}
		sort(a, a + n);
		if (k & 1)
			a[0] = -a[0];
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[i];
		cout << sum << endl;
	}

	return 0;
}