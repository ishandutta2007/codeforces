#include <cstdio>
#include <vector>
#include <algorithm>

#define FO(i,a,b) for (int i = a; i < b; i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll A, B;

ll f(ll r) {
	return (r+1)*A + B*r*1ll*(r+1)/2;
}

double f2(ll r) {
	return (r+1)*1.*A + B*r*1.*(r+1)/2;
}

int main() {
	scanf("%lld %lld", &A, &B);
	int n; scanf("%d", &n);
	FO(Z,0,n) {
		ll l, t, m; scanf("%lld %lld %lld", &l, &t, &m); l--;
		ll rs = l, re = l+5000005, br = -2;
		while (rs <= re) {
			ll md = (rs+re)/2;
			if (A+md*B <= t && f2(md)-f2(l-1) <= t*m*10 && f(md)-f(l-1) <= t*m) {
				br = md;
				rs = md+1;
			} else re = md-1;
		}
		printf("%lld\n", br+1);
	}
}