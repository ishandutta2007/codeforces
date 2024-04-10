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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, l, r, ql, qr;
int w[maxn], sum[maxn];



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> l >> r >> ql >> qr) {
		for (int i = 0; i < n; i++) cin >> w[i], sum[i] = (i ? sum[i - 1] : 0) + w[i];

		int csum = 0;
		int ans = 2e9 + 20;
		for (int i = 0, j = n - 1, o = 0; i <= j; o++) {
			if (o % 2 == 0) {
				csum += w[i++] * l;
				ans = min(ans, csum + (sum[j] - sum[i - 1]) * l + (j - i + 1) * ql);
			} else {
				csum += w[j--] * r;
				ans = min(ans, csum + (sum[j] - sum[i - 1]) * r + (j - i + 1) * qr);
			}
		}
		csum = 0;
		for (int i = 0, j = n - 1, o = 0; i <= j; o++) {
			if (o % 2 == 1) {
				csum += w[i++] * l;
				ans = min(ans, csum + (sum[j] - sum[i - 1]) * l + (j - i + 1) * ql);
			} else {
				csum += w[j--] * r;
				ans = min(ans, csum + (sum[j] - sum[i - 1]) * r + (j - i + 1) * qr);
			}
		}

		cout << ans << endl;
	}

	return 0;
}