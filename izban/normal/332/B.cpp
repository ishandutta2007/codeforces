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

const int maxn = 1 << 18;
const int inf = 1000000007;
const int mod = 1000000007;

int n, k;
int x[maxn]; 
ll sum[maxn], a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> k) {
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			sum[i] = sum[i - 1] + x[i];
		}
		for (int i = 1; i + k - 1 <= n; i++) {
			a[i] = sum[i + k - 1] - sum[i - 1];
		}

		ll ans = -1;
		int ansa = -1, ansb = -1;
		int curmx = 0;
		for (int i = k + 1; i + k - 1 <= n; i++) {
			if (a[i - k] > a[curmx]) curmx = i - k;
			if (ans < a[i] + a[curmx]) {
				ans = a[i] + a[curmx];
				ansa = curmx;
				ansb = i;
			}
		}
		cout << ansa << " " << ansb << endl;
	}

	return 0;
}