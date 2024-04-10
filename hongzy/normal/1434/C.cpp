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

const int N = 6e5 + 10;
const int mod = 1e9 + 7;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<long long> ran(0, 1ll << 62);
void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> ran(0, 1ll << 62);

int main() {
	int t; scanf("%d", &t);
	while(t --) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(1ll * b * c < a) {
			puts("-1");
		} else {
			ll k = a / (1ll * b * d);
			printf("%lld\n", a * (k + 1ll) - 1ll * b * d * (k * (k + 1ll) / 2));
		}
	}
   return 0;
}