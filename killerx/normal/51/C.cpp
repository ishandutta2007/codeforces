#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
int n;
ll x[mxn];
ll a, b, c;

bool chk(ll d) {
	int i = 0, j = n - 1;
	while (i < n && x[i] - x[0] <= d * 2) ++ i;
	a = (x[i - 1] + x[0]) / 2;
	while (j >= 0 && x[n - 1] - x[j] <= d * 2) -- j;
	c = (x[n - 1] + x[j + 1]) / 2;
	if (i <= j && x[j] - x[i] > d * 2) return 0;
	b = (x[j] + x[i]) / 2;
	return 1;
}

inline void P2(ll x) {
	printf("%lld", x >> 1);
	if (x & 1) printf(".500000");
	else printf(".000000");
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%lld", &x[i]);
	sort(x, x + n);
	rep(i, n) x[i] <<= 1;
	ll lb = 0, rb = 2e9;
	while (lb < rb) {
		ll md = (lb + rb) >> 1;
		if (chk(md)) rb = md;
		else lb = md + 1;
	}
	chk(lb);
	P2(lb); puts("");
	P2(a); printf(" ");
	P2(b); printf(" ");
	P2(c); puts("");
	return 0;
}