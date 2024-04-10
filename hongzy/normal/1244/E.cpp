#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;

int n, a[N];
ll k, L, R, pre[N], suf[N];

ll f(ll x, ll mid) {
	int ll = lower_bound(a + 1, a + n + 1, x) - a - 1;
	int rr = upper_bound(a + 1, a + n + 1, x + mid) - a;
//	printf("ll, rr = %d %d\n", ll, rr);
	return ll * x - pre[ll] + suf[rr] - (n - rr + 1) * (x + mid);
}


bool chk(ll mid) {
	ll l = L, r = R, m1, m2;
	while(r - l > 3) {
		m1 = l + (r - l) / 3;
		m2 = r - (r - l) / 3;
		if(f(m1, mid) <= f(m2, mid)) r = m2;
		else l = m1;
	}
	for(ll x = l; x <= r; x ++)
		if(f(x, mid) <= k) return 1; //printf("x %lld, mid %lld, ok!\n", x, mid), 1;
	return 0;
}

int main() {
	scanf("%d%I64d", &n, &k);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i];
	for(int i = n; i >= 1; i --) suf[i] = suf[i + 1] + a[i];
	R = a[n]; L = a[1];
	ll l = 0, r = R - L, mid, ans = -1;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(chk(mid)) r = (ans = mid) - 1;
		else l = mid + 1;
	}
	printf("%I64d\n", ans);
	return 0;
}