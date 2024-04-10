#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 1e5 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}
ll n, cnt[64], tmp[64];
int m, a[N];
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		scanf("%lld%d", &n, &m);
		ll cost = 0, now = 0;
		fill(cnt, cnt + 64, 0);
		for(int i = 1; i <= m; i ++) {
			scanf("%d", a + i); int x = -1;
			for(int y = a[i]; y; y >>= 1) x ++;
			cost += a[i] - 1; cnt[x] += a[i]; now += a[i];
		}
		if(now < n) {
			puts("-1");
			continue ;
		}
		ll pre = 0;
		for(int i = 0; i < 63; i ++) {
			if(n >> i & 1) {
				if(!pre) {
					for(int j = i; j < 63; j ++) if(cnt[j]) {
						cnt[j] --; break ;
					}
				} else {
					pre --;
				}
			}
			pre = (pre + cnt[i]) / 2;
			for(int j = i + 1; j < 63; j ++) {
				cost -= cnt[j] / 2; cnt[j] /= 2;
			}
		}
		printf("%lld\n", cost);
	}
	return 0;
}