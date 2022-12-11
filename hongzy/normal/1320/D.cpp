#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;

const int N = 2e5 + 10;
const int mod1 = 1e9 + 9;
const int mod2 = 19260817;
const int base = 2333;
int n, q, cnt[N], cnt0[N];
ll h1[N << 2], h2[N << 2], pw1[N], pw2[N];
ll rh1[N << 2], rh2[N << 2];
char s[N];
void build(int u, int l, int r) {
	if(l == r) {
		if(s[l] == '0') {
			h1[u] = 0; h2[u] = 0;
			rh1[u] = 1; rh2[u] = 1;
		} else {
			h1[u] = h2[u] = rh1[u] = rh2[u] = 0;
		}
		return ;
	}
	int mid = (l + r) >> 1, ri = cnt0[r] - cnt0[mid];
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	if((cnt[mid] - cnt[l - 1]) & 1) {
		h1[u] = (h1[u << 1] * pw1[ri] % mod1 + rh1[u << 1 | 1]) % mod1;
		h2[u] = (h2[u << 1] * pw2[ri] % mod2 + rh2[u << 1 | 1]) % mod2;
		rh1[u] = (rh1[u << 1] * pw1[ri] % mod1 + h1[u << 1 | 1]) % mod1;
		rh2[u] = (rh2[u << 1] * pw2[ri] % mod2 + h2[u << 1 | 1]) % mod2;
	} else {
		h1[u] = (h1[u << 1] * pw1[ri] % mod1 + h1[u << 1 | 1]) % mod1;
		h2[u] = (h2[u << 1] * pw2[ri] % mod2 + h2[u << 1 | 1]) % mod2;
		rh1[u] = (rh1[u << 1] * pw1[ri] % mod1 + rh1[u << 1 | 1]) % mod1;
		rh2[u] = (rh2[u << 1] * pw2[ri] % mod2 + rh2[u << 1 | 1]) % mod2;
	}
}
ll qh1, qh2, qrh1, qrh2;
int sz;
void query(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) {
		ll _qh1 = qh1, _qh2 = qh2, _qrh1 = qrh1, _qrh2 = qrh2;
		if((cnt[r] - cnt[l - 1]) & 1) {
			qh1 = (h1[u] * pw1[sz] % mod1 + _qrh1) % mod1;
			qh2 = (h2[u] * pw2[sz] % mod2 + _qrh2) % mod2;
			qrh1 = (rh1[u] * pw1[sz] % mod1 + _qh1) % mod1;
			qrh2 = (rh2[u] * pw2[sz] % mod2 + _qh2) % mod2;
		} else {
			qh1 = (h1[u] * pw1[sz] % mod1 + _qh1) % mod1;
			qh2 = (h2[u] * pw2[sz] % mod2 + _qh2) % mod2;
			qrh1 = (rh1[u] * pw1[sz] % mod1 + _qrh1) % mod1;
			qrh2 = (rh2[u] * pw2[sz] % mod2 + _qrh2) % mod2;
		}
		sz += cnt0[r] - cnt0[l - 1];
		return ;
	}
	int mid = (l + r) >> 1;
	if(qr <= mid) query(u << 1, l, mid, ql, qr);
	else if(ql > mid) query(u << 1 | 1, mid + 1, r, ql, qr);
	else {
		query(u << 1 | 1, mid + 1, r, mid + 1, qr);
		query(u << 1, l, mid, ql, mid);
	}
}
pair<ll, ll> query(int l, int r) {
	qh1 = qh2 = qrh1 = qrh2 = 0; sz = 0;
	query(1, 1, n, l, r);
	return pair<ll, ll>(qh1, qh2);
}
int main() {
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; i ++) {
		cnt[i] = cnt[i - 1] + (s[i] == '1');
		cnt0[i] = cnt0[i - 1] + (s[i] == '0');
	}
	pw1[0] = pw2[0] = 1;
	for(int i = 1; i <= n; i ++) {
		pw1[i] = pw1[i - 1] * base % mod1;
		pw2[i] = pw2[i - 1] * base % mod2;
	}
	build(1, 1, n); scanf("%d", &q);
	for(int u, v, l, i = 1; i <= q; i ++) {
		scanf("%d%d%d", &u, &v, &l);
		if(cnt[u + l - 1] - cnt[u - 1] != cnt[v + l - 1] - cnt[v - 1]) {
			puts("No");
		} else {
			puts(query(u, u + l - 1) == query(v, v + l - 1) ? "Yes" : "No");
		}
	}
	return 0;
}