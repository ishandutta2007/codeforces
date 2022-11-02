#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
//#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int MXN = (int)1e6 + 7;
long long a[MXN];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld", a + i);
		int ans = 0;
		long long cur = 0;
		for (int i = 1; i < n; i++) {
			long long v = a[i+1] - (a[i] + cur);
			if (v >= 0) {
				cur = 0;
				continue ;
			}
			cur = -v;
			while ( (1ll<<ans) - 1 < cur) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}