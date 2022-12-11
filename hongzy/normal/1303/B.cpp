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

int main() {
	int t; scanf("%d", &t);
	while(t --) {
		int n, g, b;
		scanf("%d%d%d", &n, &g, &b); int m = (n + 1) >> 1;
		ll ans = 0;
		if(m % g != 0) ans = (m / g) * 1ll * (g + b) + (m % g);
		else ans = (m / g) * 1ll * (g + b) + (m % g) - b;
		printf("%lld\n", max((ll) n, ans));
	}
	return 0;
}