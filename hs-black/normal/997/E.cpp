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

template<typename F>
inline void write(F x, char ed = '\n')
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 200500;
struct node {
	int mn, add;
	ll res, cnt, cc;
	#define res(p) t[p].res
	#define cc(p) t[p].cc
	#define mn(p) t[p].mn
	#define add(p) t[p].add
	#define cnt(p) t[p].cnt
}t[N<<3];
int p[N], s1[N], s2[N], t1, t2, q, n;

inline void Add(int p, int val) { add(p) += val, mn(p) += val; }
inline void Ans(int p, int c, int mn) {
	if (mn(p) != mn) return;
	res(p) += cnt(p) * c, cc(p) += c;
}

#define ls p << 1
#define rs ls | 1
void spread(int p) {
	if (add(p)) Add(ls, add(p)), Add(rs, add(p)), add(p) = 0;
	if (cc(p)) Ans(ls, cc(p), mn(p)), Ans(rs, cc(p), mn(p)), cc(p) = 0;
}

void build(int p, int l, int r) {
	mn(p) = 1e9, cnt(p) = 1; 
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	cnt(p) = cnt(ls) + cnt(rs);
}

void Update(int p) {
	if (mn(ls) < mn(rs)) mn(p) = mn(ls), cnt(p) = cnt(ls);
	else if (mn(ls) > mn(rs)) mn(p) = mn(rs), cnt(p) = cnt(rs);
	else mn(p) = mn(ls), cnt(p) = cnt(ls) + cnt(rs);
}

void update(int p, int l, int r, int L, int R, int val) {
	if (L <= l && r <= R) return Add(p, val);
	spread(p); int mid = (l + r) >> 1;
	if (L <= mid) update(ls, l, mid, L, R, val);
	if (mid < R) update(rs, mid + 1, r, L, R, val);
	Update(p);
}

void refresh(int p, int l, int r, int x) {
	if (l == r) return mn(p) = 0, void();
	int mid = (l + r) >> 1; spread(p);
	if (x <= mid) refresh(ls, l, mid, x);
	else refresh(rs, mid + 1, r, x);
	Update(p);
}

void maintain(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return Ans(p, 1, 0);
	int mid = (l + r) >> 1; spread(p);
	if (L <= mid) maintain(ls, l, mid, L, R);
	if (mid < R) maintain(rs, mid + 1, r, L, R);
	res(p) = res(ls) + res(rs);
}

ll query(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return res(p);
	int mid = (l + r) >> 1; spread(p); ll ans = 0;
	if (L <= mid) ans += query(ls, l, mid, L, R);
	if (mid < R) ans += query(rs, mid + 1, r, L, R);	
	return ans;
}

vector<pair<int, int> > v[N];
ll ans[N];
int main() {
	read(n); for (int i = 1;i <= n; i++) read(p[i]); read(q);
	for (int i = 1, l, r;i <= q; i++) 
		read(l), read(r), v[r].emplace_back(l, i);
	build(1, 1, n);
	for (int i = 1;i <= n; i++) {
		while (t1 > 0 && p[s1[t1]] < p[i]) update(1, 1, n, s1[t1-1] + 1, s1[t1], -p[s1[t1]]), t1--;
		while (t2 > 0 && p[s2[t2]] > p[i]) update(1, 1, n, s2[t2-1] + 1, s2[t2], p[s2[t2]]), t2--;
		if (i != 1) update(1, 1, n, 1, i - 1, -1); refresh(1, 1, n, i);
		s1[++t1] = i, s2[++t2] = i;
		update(1, 1, n, s1[t1-1] + 1, i, p[i]);
		update(1, 1, n, s2[t2-1] + 1, i, -p[i]);
//		maintain(1, 1, n, 1, i); 
		Ans(1, 1, 0);
		for (auto t: v[i]) ans[t.se] = query(1, 1, n, t.fi, i);
	}
	for (int i = 1;i <= q; i++) write(ans[i]);
	return 0;
}



/*

5
1 3 2 5 4
1
2 3

2 4
2 5
3 3
3 4
3 5
4 4
4 5
5 5

*/