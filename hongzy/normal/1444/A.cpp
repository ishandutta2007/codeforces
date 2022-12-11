#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<long long> ran(0, 1ll << 62);
void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
ll p, q, a[N], d[N], c;
int main() {
   int t; scanf("%d", &t);
   while(t --) {
   	scanf("%lld%lld", &p, &q);
   	if(p % q != 0) {
   		printf("%lld\n", p);
		} else {
			c = 0;
			ll x = q;
			for(ll i = 2; i * i <= x; i ++) {
				if(x % i == 0) {
					a[++ c] = i; d[c] = 0;
					while(x % i == 0) {
						d[c] ++;
						x /= i;
					}
				}
			}
			if(x > 1) {
				d[++ c] = 1;
				a[c] = x;
			}
			ll ans = 1; x = p;
			for(int i = 1; i <= c; i ++) {
				int k = 0;
				while(x % a[i] == 0) {
					k ++;
					x /= a[i];
				}
				ll num = p;
				rep(j, 1, k - d[i] + 1) {
					num /= a[i];
				}
				ans = max(ans, num);
			}
			printf("%lld\n", ans);
		}
	}
   return 0;
}