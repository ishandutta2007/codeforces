#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

const int N = 100005;

ll a[N], b[N], suma, sumb, n, m;

int main() {
    scanf("%llu%llu", &n, &m);
    for (int i = 0; i < n; i++) {
	scanf("%llu", &a[i]);
	suma += a[i];
    }
    for (int i = 0; i < m; i++) {
	scanf("%llu", &b[i]);
	sumb += b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    ll ans = 10000000000000000000ULL;
    ll sum = 0;
    for (ll i = 0; i < n - 1; i++) {
	if (sumb <= a[i]) {
	    sum += (n - i) * sumb;
	    ans = min(ans, sum);
	    break;
	}
	sum += a[i];
    }
    ans = min(ans, sum + sumb);
    sum = 0;
    for (ll i = 0; i < m - 1; i++) {
	if (suma <= b[i]) {
	    sum += (m - i) * suma;
	    ans = min(ans, sum);
	}
	sum += b[i];
    }
    ans = min(ans, sum + suma);
    printf("%llu\n", ans);
    return 0;
}