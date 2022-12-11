#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 1000500;
vector<int> v1[N], v2[N];
int a[N], L[N], R[N], n, q;

struct bin {
	ll d[N];
	
	void clear(void) { memset(d, 0, sizeof(d)); }
	void add(int x, int k) { for (; x <= n; x += x & -x) d[x] += k; }
	void add(int l, int r, int x) { add(l, x), add(r + 1, -x); }
	ll query(int x) { ll res = 0; for (; x; x -= x & -x) res += d[x]; return res; }
	
}sum, cnt, tmp;

int l[N], r[N], st[N], tp;
ll ans[N];
int main() {
	read(n), read(q);
	for (int i = 1;i <= n; i++) L[i] = R[i] = i, read(a[i]);
	a[0] = a[n + 1] = n + 1;
	for (int i = 1;i <= n; i++) {
		while (a[st[tp]] < a[i]) tp--;
		L[i] = st[tp] + 1, st[++tp] = i;
	}
	st[tp = 0] = n + 1;
	for (int i = n;i >= 1; i--) {
		while (a[st[tp]] < a[i]) tp--;
		R[i] = st[tp] - 1, st[++tp] = i;
	}
	
	for (int i = 1;i <= q; i++) read(l[i]), v1[l[i]].push_back(i);
	for (int i = 1;i <= q; i++) read(r[i]), v2[r[i]].push_back(i);
	
	for (int i = 1;i <= n; i++)
		sum.add(i, R[i], i), cnt.add(i, R[i], 1), tmp.add(R[i] + 1, n, R[i]);
	for (ll i = 1;i <= n; i++) {
		for (auto j: v1[i]) {
			ll k = r[j];
			ans[j] += cnt.query(k) * k + tmp.query(k);
		}
		cnt.add(i, R[i], -1), tmp.add(R[i] + 1, n, -R[i]);
	}
	
	for (int i = 1;i <= n; i++)
		sum.add(L[i], i, n - i), cnt.add(L[i], i, 1), tmp.add(1, L[i] - 1, L[i]);
	for (ll i = n;i >= 1; i--) {
		for (auto j: v2[i]) {
			ll k = l[j];
			ans[j] -= cnt.query(k) * k + tmp.query(k);
		}
		cnt.add(L[i], i, -1), tmp.add(1, L[i] - 1, -L[i]);
	}
	
	for (int i = 1;i <= q; i++) printf ("%lld ", ans[i] + r[i] - l[i] + 1);
	
	return 0;
}