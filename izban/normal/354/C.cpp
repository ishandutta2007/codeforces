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

const int maxn = 1 << 21;
const int inf = 1000000007;
const int mod = 1000000007;

int n, k;
int a[maxn];
int b[maxn], sum[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> k) {
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		
		memset(b, 0, sizeof(b));
		for (int i = 0; i < n; i++) b[a[i]] = 1;
		sum[0] = b[0];
		for (int i = 1; i < maxn; i++) sum[i] = sum[i - 1] + b[i];
		//int ans = min(a[0], k + 1);
		int ans = -1;
		for (int i = 1; i <= a[0]; i++) {
			int start = 0;
			bool ok = 1;
			while (start <= a[n - 1]) {
				int l = start + k + 1;
				int r = start + i - 1;
				if (sum[r] - sum[l - 1] > 0) 
					ok = false;
				start += i;
			}
			if (ok) ans = i;
		}
		cout << ans << endl;
	}

	return 0;
}