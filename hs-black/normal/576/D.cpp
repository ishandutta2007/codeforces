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
 
int m, n;
 
const int N = 170;
struct Edge {
	int x, y, d;
	
	void get() { read(x), read(y), read(d); }
	
	bool operator < (const Edge &i) const {
		return d < i.d;
	}
}ed[N];
 
#include <bitset>
struct Mat {
	bitset<N> a[N];
	
	inline Mat operator * (Mat b) {
		Mat tmp;
		for (int i = 1;i <= n; i++)
			for (int j = 1;j <= n; j++)
				if (a[i][j]) tmp.a[i] |= b.a[j];
		return tmp;
	}
	
}B, I;
 
Mat fpw(Mat x, ll mi) {
	Mat res = I;
	while (mi) {
		if (mi & 1) res = res * x;
		x = x * x; mi >>= 1;
	}
	return res;
}
 
ll d[N];
int main() {
	read(n), read(m);
	for (int i = 1;i <= m; i++) ed[i].get();
	sort(ed + 1, ed + m + 1);
	for (int i = 1;i <= n; i++) I.a[i][i] = 1;
	ll ans = 1e15; Mat tmp = I;
	for (ll i = 1, t = 0;i <= m; i++) {
		if (ans <= ed[i].d) return printf ("%lld\n", ans), 0;
		tmp = tmp * fpw(B, ed[i].d - t);
		B.a[ed[i].x][ed[i].y] = 1; t = ed[i].d;
		queue<int> q;
		for (int j = 1;j <= n; j++)
			if (tmp.a[1][j]) q.push(j), d[j] = 0;
			else d[j] = 1e15;
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int j = 1;j <= n; j++)
				if (B.a[x][j] && d[j] == 1e15)
					d[j] = d[x] + 1, q.push(j);
		}
		Mn(ans, (ll)t + d[n]);
	}
	if (ans >= 1e15) puts("Impossible");
	else printf ("%lld\n", ans);
	return 0;
}