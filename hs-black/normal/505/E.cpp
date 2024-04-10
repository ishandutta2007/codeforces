#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
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
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 200500;
#define MP make_pair
#define Pa pair<ll, ll>
#define fi first
#define se second
priority_queue < Pa > q;
ll n, m, k, p;
ll w[N], h[N], a[N];

bool check(ll H) {
	while (q.size()) q.pop();
	for (int i = 1;i <= n; i++)
		if (H - a[i] * m < h[i]) q.push(MP(-H / a[i], i)), w[i] = H;
	for (int i = 1;i <= m; i++) {
		for (int j = 1;j <= k; j++) {
			if (q.empty()) return true;
			Pa t = q.top(); q.pop();
			if (-t.fi < i) return false;
			w[t.se] += p;
			if (w[t.se] < h[t.se] + a[t.se] * m) 
				q.push(MP(-w[t.se] / a[t.se], t.se));
		}
	}
	return q.empty();
}

int main() {
	read(n), read(m), read(k), read(p); ll l = 0, r = 0;
	for (int i = 1;i <= n; i++)
		read(h[i]), read(a[i]), r = max(r, a[i] * m + h[i]);
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	printf ("%lld\n", l);
}