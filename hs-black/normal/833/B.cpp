
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

const int N = 40500;
int f[N], g[N], a[N], cnt[N], n, k;
int L, R, ans;
inline void add(int x) { ans += !cnt[x], cnt[x]++; }
inline void del(int x) { cnt[x]--, ans -= !cnt[x]; }

void movit(int l, int r) {
	while (L > l) add(a[--L]);
	while (R < r) add(a[++R]);
	while (L < l) del(a[L++]);
	while (R > r) del(a[R--]);
}

void solve(int l, int r, int L, int R) {
	if (l > r) return;
	int mid = (l + r) >> 1, poi = L, tmp = 0; 
	for (int i = L;i <= min(mid - 1, R); i++) {
		movit(i + 1, mid);
		if (ans + g[i] > tmp) poi = i, tmp = ans + g[i];
	}
	f[mid] = tmp;
	solve(l, mid - 1, L, poi), solve(mid + 1, r, poi, R);
}

int main() {
	read(n), read(k);
	for (int i = 1;i <= n; i++) read(a[i]);
	memset(f, -0x3f, sizeof(f)); f[0] = 0;
	for (int i = 1;i <= k; i++) 
		swap(f, g), solve(1, n, 0, n - 1);
	write(f[n]);
	return 0;
}