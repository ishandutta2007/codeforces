#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define push_back pb
#define make_pair MP
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = (int)1e9 + 7;

const int N = (int)1e6 + 7;

int a[ N ];
long long b[ N ], c[ N ];
int main() {
	int n, d, m; scanf("%d %d %d", &n, &d, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	int n1 = 0, n2 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > m) b[++n1] = a[i];
		else c[++n2] = a[i];
	}
	sort(b + 1, b + n1 + 1);
	sort(c + 1, c + n2 + 1);
	for (int i = 1; i <= n2; i++)
		c[i] += c[i-1];
	long long ans = c[n2], cur = 0;
	for (int i = 1; i <= n1; i++) {
		cur += b[n1 + 1 - i];
		long long v = cur;
		long long num = (i - 1) * 1ll * d - (n1 - i);
		if (num > n2) break ;
		if (num > 0) v += c[n2] - c[num];
		else v += c[n2];
		ans = max(ans, v);
	}
	printf("%lld\n", ans);
	return 0;
}