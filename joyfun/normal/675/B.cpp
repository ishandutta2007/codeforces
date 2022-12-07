#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
//lower_bound(a+1,a+1+len1,x) - a - 1;
typedef long long LL;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100005;
int n, a[4];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) scanf("%d", &a[i]);
	swap(a[2], a[3]);
	int Min = -INF, Max = INF;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = -INF, r = INF;
		for (int j = 0; j < 4; j++) {
			l = max(l, a[j] + a[(j + 1) % 4] + i + 1);
			r = min(r, a[j] + a[(j + 1) % 4] + i + n);
		}
		if (l <= r) ans += (r - l + 1);
	}
	printf("%lld\n", ans);
	return 0;
}