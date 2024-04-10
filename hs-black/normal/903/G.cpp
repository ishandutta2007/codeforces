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

const int N = 200500;
ll a[N], b[N];
struct Segment {
	int l, r;
	ll sum, add, mn;
	#define l(p) t[p].l
	#define r(p) t[p].r
	#define sum(p) t[p].sum
	#define add(p) t[p].add
	#define mn(p) t[p].mn
}t[N<<3];


#define ls p << 1
#define rs p << 1 | 1 
inline void update(int p) {
	mn(p) = min(mn(ls), mn(rs));
}

inline void spread(int p) {
	add(ls) += add(p), add(rs) += add(p);
	mn(ls) += add(p), mn(rs) += add(p);
	add(p) = 0;
}

void build(int l, int r, int p) {
	l(p) = l, r(p) = r;
	if (l == r) return mn(p) = b[l], void();
	int mid = (l + r) >> 1;
	build(l, mid, ls), build(mid + 1, r, rs);
	update(p);
}

void change(int l, int r, int p, int x) {
	if (l <= l(p) && r(p) <= r) {
		add(p) += x, mn(p) += x; return;
	}
	if (add(p)) spread(p);
	if (l <= r(ls)) change(l, r, ls, x);
	if (r >= l(rs)) change(l, r, rs, x);
	update(p);
}

vector<int> to[N], w[N];
ll sum[N], res, n, m, q;
priority_queue<ll> q1, q2;
int main() {
	read(n), read(m), read(q);
	for (int i = 1;i < n; i++) read(a[i]), read(b[i]);
	build(0, n - 1, 1);
	for (int i = 1;i <= m; i++) {
		int x, y, z; read(x), read(y), read(z);
		to[x].push_back(y), w[x].push_back(z); res += z;
	}
	for (int i = 1;i <= n; i++) {
		for (int j = 0;j < to[i].size(); j++) 
			change(0, to[i][j] - 1, 1, w[i][j]);
		sum[i] = mn(1); q1.push(-sum[i] - a[i]);
	}
	printf ("%lld\n", -q1.top());
	while (q--) {
		int x, y; read(x), read(y);
		q2.push(-sum[x] - a[x]); a[x] = y;
		q1.push(-sum[x] - a[x]);
		while (q2.size() && q1.top() == q2.top()) q1.pop(), q2.pop();
		printf ("%lld\n", -q1.top());
	}
	return 0;
}