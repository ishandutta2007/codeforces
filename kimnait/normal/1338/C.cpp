#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
//#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int MXN = (int)1e6 + 7;
int a[4] = {0, 2, 3, 1};
long long fd(int p, long long num, long long val) {
	long long bs = 1ll<<p;
	if (p == 0) return val + a[num];
	else return fd(p - 2, num % bs, (val + a[num/bs])<<2);
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		long long n; scanf("%lld", &n);
		if (n <= 3) { printf("%lld\n", n); continue ; }
		long long ans = -1;
		int p = 0;
		while ((1ll<<(p+2)) - 1 < n) p += 2;
		n -= (1ll<<p) - 1;
		if (n % 3 == 1) {
			ans = (1ll<<p) + n / 3;
		} else if (n % 3 == 2) {
			ans = (2ll<<p) + fd(p - 2, n / 3, 0);
		} else {
			long long v1 = (1ll<<p) + n / 3 - 1;
			long long v2 = (2ll<<p) + fd(p - 2, n / 3 - 1, 0);
			ans = v1 ^ v2;
		}
		printf("%lld\n", ans);
	}
}