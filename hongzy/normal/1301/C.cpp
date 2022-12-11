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
#define pb push_back 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mo = 1e9 + 7;

ll qpow(ll a, ll b) {
	ll ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}
int n, m;
ll calc(ll n) {
	return n * (n + 1) / 2;
}
ll __div(ll z, ll d) {
	ll c = z / d, r = z % d;
	return (c + 1) * (c + 1) * r + c * c * (d - r);
}
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		scanf("%d%d", &n, &m);
		ll z = n - m, d = m + 1;
		printf("%lld\n", calc(n) - (z + __div(z, d)) / 2);
	}
	return 0;
}