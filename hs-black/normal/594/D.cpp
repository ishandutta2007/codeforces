#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
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

const int P = 1e9+7;
ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P;
		mi >>= 1;
	}
	return res;
}

const int N = 1005000;
vector<int> v[N];

ll inv[N], mul[N], d[N];
int maxn;
void prework(int maxn) {
	for (int i = 2;i <= maxn; i++) 
		if (!v[i].size()) 
		for (int j = i;j <= maxn; j += i)
				v[j].push_back(i);
	mul[0] = inv[0] = inv[1] = d[1] = 1;
	for (int i = 2;i <= maxn; i++)
		d[i] = 1, inv[i] = (P - P / i) * inv[P % i] % P;
}

int val[N], m, n;
ll lst[N], ans[N];
void add(int x, ll k) {
	for (; x <= maxn; x += (x & -x)) (d[x] *= k) %= P;
}

ll sum(int x) {
	ll res = 1;
	for (; x; x -= (x & -x)) res = res * d[x] % P;
	return res;
}

struct node {
	int l, r, num;
	bool operator < (const node &i) const {
		return r < i.r;
	}
}q[N];

int main() {
	
	read(n);
	for (register int i = 1;i <= n; i++) 
		read(val[i]), maxn = max(maxn, val[i]);
	read(m); prework(maxn);
	for (int i = 1;i <= m; i++) q[i].num = i, read(q[i].l), read(q[i].r);
	sort(q + 1, q + m + 1);
	
	
	int now = 0;
	for (int i = 1;i <= m; i++) {
		while (now < q[i].r) {
			now++; mul[now] = mul[now-1] * val[now] % P;
			for (auto j: v[val[now]]) {
				if (lst[j]) add(lst[j], inv[j-1] * j % P);
				add(now, (j - 1) * inv[j] % P), lst[j] = now;
			}
		}
		int k = q[i].num;
		ans[k] = fpw(mul[q[i].l-1], P - 2) * mul[q[i].r] % P;
		ans[k] = ans[k] * sum(q[i].r) % P * fpw(sum(q[i].l-1), P - 2) % P;
	}
	for (register int i = 1;i <= m; i++) 
		printf ("%lld\n", ans[i]);
	
	return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
2
8 10
7 9

*/