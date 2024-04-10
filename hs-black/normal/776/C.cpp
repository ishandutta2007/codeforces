
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

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
inline void write(F x, char ed = '\n') {
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

//#pragma GCC optimize(2)
//#include <map>
const int N = 100050;
int n, k, T;
//map<ll, int> mp;
ll sum[N], mx, mn;
inline ll jue(ll t) { return t > 0 ? t : -t; }
ll a[N]; int cnt[N], m;

int Get(ll t) {
	if (t < a[1] || t > a[m]) return 0;
	int pos = lower_bound(a + 1, a + m + 1, t) - a;
	if (a[pos] != t) return 0;
	return cnt[pos];
}

inline void insert(ll t) {
	int pos = lower_bound(a + 1, a + m + 1, t) - a;
	cnt[pos]++;
}

int main() {
//	freopen ("perfume.in","r",stdin);
//	freopen ("perfume.out","w",stdout);
//	for (read(T); T; T--) {
		read(n), read(k);
		mx = 1e15; ll ans = 0;
		for (int i = 1;i <= n + 1; i++) cnt[i] = 0;
		m = n + 1;
		for (int i = 1, x;i <= n; i++) read(x), sum[i] = sum[i-1] + x, a[i] = -sum[i];
		a[n + 1] = 0;
		sort(a + 1, a + m + 1), m = unique(a + 1, a + m + 1) - a - 1;
		insert(0);
		for (int i = 1;i <= n; i++) {
			ll res = 1;
			if (jue(k) > 1) {
				while (jue(res - sum[i]) <= mx) 
					ans += Get(res - sum[i]), res = res * k;
			}
			else {
				ans += Get(1 - sum[i]);
				if (k == -1) ans += Get(-sum[i] - 1);
			}
			insert(-sum[i]);
		}
		write(ans);
//	}
	return 0;
}

/*

8
4 -3
3 -6 -3 12
4 2
2 2 2 2
4 -3
3 -6 -3 12
4 2
2 2 2 2
4 -3
3 -6 -3 12
4 2
2 2 2 2
4 -3
3 -6 -3 12
4 2
2 2 2 2

*/