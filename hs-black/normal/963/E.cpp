/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
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

const int P = 1e9 + 7;
ll p1, p2, p3, p4, inv;
int lim, cnt, R;
ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}
struct vec {
	int f[105];
	vec (void) { memset(f, 0, sizeof(f)); }
	int & operator [] (int i) { return f[i]; }
	vec operator * (int p) {
		vec t;
		for (int i = 1;i <= lim + 1; ++i) 
			t[i] = 1ll * f[i] * p % P;
		return t;
	}
	vec operator + (vec b) {
		vec t;
		for (int i = 1;i <= lim + 1; ++i)
			t[i] = f[i] + b[i], t[i] >= P && (t[i] -= P);
		return t;
	}
}A[8001], B[105];

#include <map>
map<pair<int, int>, int> mp;
inline int jud(int x, int y) { return x * x + y * y <= R * R; }
int ttt;
int dfs(int x, int y, int fl = 0) {
	if (!jud(x, y) && !fl) return 0;
	if (mp[MP(x, y)]) return mp[MP(x, y)];
	int nw = mp[MP(x, y)] = ++cnt;
	if (!jud(x - 1, y)) { A[nw][++ttt] = 1; return nw; }
	int tx = dfs(x - 1, y), t1 = dfs(x - 2, y);
	int t2 = dfs(x - 1, y - 1), t4 = dfs(x - 1, y + 1);
	A[nw] = A[tx] + A[t1] * (P - p1) + A[t2] * (P - p2) + A[t4] * (P - p4);
	A[nw][lim + 1] = (A[nw][lim + 1] + P - 1) % P;
	return A[nw] = A[nw] * inv, nw;
}

int n;
int main() {
	read(R), read(p1), read(p2), read(p3), read(p4);
	ll s = (p1 + p2 + p3 + p4) % P; s = fpw(s, P - 2);
	p1 = p1 * s % P, p2 = p2 * s % P, p3 = p3 * s % P, p4 = p4 * s % P;
	lim = 2 * R + 1, inv = fpw(p3, P - 2);
	int t = dfs(R + 1, 0, 1); B[1] = A[t];
	for (int i = 1;i <= R; ++i) {
		int j = 0;
		while (jud(j, i)) ++j;
		t = dfs(j, i, 1), B[i << 1] = A[t];
		t = dfs(j, -i, 1), B[i << 1 | 1] = A[t];
	}
	for (int i = 1;i <= lim; ++i) {
		for (int j = i;j <= lim; ++j) 
			if (B[i][j]) { swap(B[i], B[j]); break; }
		ll Inv = fpw(B[i][i], P - 2);
		B[i] = B[i] * Inv;
		for (int j = 1;j <= lim; ++j) if (i != j && B[j][i]) 
			B[j] = B[j] + B[i] * (P - B[j][i]);
	}
	t = mp[MP(0, 0)];
	ll ans = 0;
	for (int j = 1;j <= lim; ++j)
		ans = (ans - 1ll * A[t][j] * B[j][lim + 1]) % P;
	write(((ans + A[t][lim + 1]) % P + P) % P);
	return 0;
}