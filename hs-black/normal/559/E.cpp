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

const int N = 1005;
ll f[N][N];

struct L {
	ll l, x, r;
	bool operator < (const L &i) const {
		return x < i.x;
	}
	void Print(void) {
		printf ("%lld %lld %lld\n", l, x, r);
	}
}l[N];

vector<int> pos;

inline void doit(int x) {
	l[x].l = lower_bound(pos.begin(), pos.end(), l[x].l) - pos.begin();
	l[x].x = lower_bound(pos.begin(), pos.end(), l[x].x) - pos.begin();
	l[x].r = lower_bound(pos.begin(), pos.end(), l[x].r) - pos.begin();
}


inline void Mx(ll &x, ll y) { if (y > x) x = y; }
int main() {
	int n, p, len; read(n);
	for (int i = 1;i <= n; i++) {
		read(p), read(len);
		l[i] = (L){p - len, p, p + len};
		pos.push_back(l[i].l);
		pos.push_back(l[i].x);
		pos.push_back(l[i].r);
	}
	sort(l + 1, l + n + 1);
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	for (int i = 1;i <= n; i++) doit(i);
	
	for (int i = 1;i <= n; i++) {
		ll mx = l[i].x;
		f[i][mx] = f[i-1][l[i].l] + pos[l[i].x] - pos[l[i].l];
		for (int k = i - 1;k >= 1; k--)
			Mx(mx, l[k].r),	Mx(f[i][mx], f[k-1][l[i].l] + pos[mx] - pos[l[i].l]); 
		for (int k = pos.size() - 1;k >= l[i].l; k--)
			Mx(f[i][k-1], f[i][k] - pos[k] + pos[k-1]);
		for (int k = l[i].x;k <= l[i].r; k++)
			Mx(f[i][k], f[i-1][l[i].x] + pos[k] - pos[l[i].x]);
		for (int j = 0;j < pos.size(); j++) {
			if (j) Mx(f[i][j], f[i][j-1]);
			Mx(f[i][j], f[i-1][j]);
		}
	}
	printf ("%lld\n", f[n][pos.size()-1]);
	return 0;
}