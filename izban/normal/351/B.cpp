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

const int maxn = 1 << 12;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int a[maxn];
double ans[maxn * maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> a[i];

		int cnt = 0;
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) cnt += a[i] > a[j];

		for (int i = 0; i <= cnt; i++) ans[i] = -1;
		ans[cnt] = 0;
		for (int i = cnt; i >= 1; i--) if (ans[i] > -0.5) {
			if (i == 1) ans[i - 1] = ans[i] + 1;
			else {
				//ans[i - 2] = (ans[i] + 2) / 2 + (ans[i] + 4) / 4 + (ans[i] + 6) / 8 + ...;
				//ans[i - 2] = ans[i] + 2 / 4 + 4 / 8 + 6 / 16 + 8 / 32 + 
				ans[i - 2] = ans[i] + 4;
			}
		}
		printf("%.10lf\n", ans[0]);
	}

	return 0;
}