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

namespace Hash {
	int primechi[] = {998244353, (int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21};
	const int bas = 13331;
	int P1, P2;
	inline void init(void) {
		srand((ll)new char);
		int x = 0, y = 0;
		while (x == y) x = rand() & 3, y = rand() & 3;
		P1 = primechi[x], P2 = primechi[y];
	}
}
using Hash::P1;
using Hash::P2; 
using Hash::bas;

struct Hs {
	int A, B;
	Hs() {}
	Hs(int a, int b) { A = a, B = b; }
	bool operator == (const Hs &i) const { return A == i.A && B == i.B; }
	Hs operator * (int t) const { return Hs(1ll * A * t % P1, 1ll * B * t % P2); }
	Hs operator * (const Hs &i) const { return Hs(1ll * A * i.A % P1, 1ll * B * i.B % P2); }
	Hs operator + (const Hs &i) const { return Hs((A + i.A) % P1, (B + i.B) % P2); }
	Hs operator + (int c) const { return Hs((A + c) % P1, (B + c) % P2); }
	Hs operator - (const Hs &i) const { return Hs((A + P1 - i.A) % P1, (B + P2 - i.B) % P2); }
};

Hs Add(Hs t, int c) { return t * bas + c; }

const int P = 1e9 + 7;
const int N = 200500, M = 3005000;
Hs A[M], B[M], Bas[M]; 
int C[N][26], n, q, s0;
char s[N], t[N], tq[M];
inline Hs get(int l, int r) { return A[r] - A[l - 1] * Bas[r - l + 1]; }
inline Hs Get(int l, int r) { return B[r] - B[l - 1] * Bas[r - l + 1]; }
inline ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}
int main() {
//	freopen ("hs.out","w",stdout);
	Hash::init();
	read(n), read(q);
	scanf ("%s", s + 1), scanf ("%s", t + 1);
	s0 = strlen(s + 1);
	int k = 0;
	while (k < n && ((1 << k) * s0 + (1 << k) - 1) <= 1000000) ++k;
	int cnt = 0;
	for (int i = 1;i <= s0; i++) ++cnt, A[cnt] = Add(A[cnt - 1], s[i]);
	for (int i = 1;i < (1 << k); i++) { 
		++cnt, A[cnt] = Add(A[cnt - 1], t[__builtin_ctz(i) + 1]);
//		putchar(t[__builtin_ctz(i) + 1]);
		for (int i = 1;i <= s0; i++) ++cnt, A[cnt] = Add(A[cnt - 1], s[i]);
//		putchar(s[i]);
	}
	ll tt = 1;
	for (int i = n;i >= 0; i--) 
		memcpy(C[i], C[i + 1], sizeof(C[i])), C[i][t[i] - 'a'] = (C[i][t[i] - 'a'] + tt) % P, tt <<= 1, tt %= P;
	Bas[0] = {1, 1};
	for (int i = 1;i <= cnt; i++) Bas[i] = Bas[i-1] * bas;
	while (q--) {
		int kk, p; 
		read(kk), scanf ("%s", tq + 1), p = strlen(tq + 1);
		ll ans = 0;
		for (int i = 1;i <= p; i++) B[i] = Add(B[i-1], tq[i]);
		if (p <= s0) {
			for (int i = 1;i + p - 1 <= s0; i++)
				if (get(i, i + p - 1) == B[p]) ans++;
			ans = ans * fpw(2, kk) % P;
		}
		Hs res(0, 0); 
		for (int i = 1;i <= p; i++) {
			int tk = 0;
			while (((1 << tk) * s0 + (1 << tk) - 1) < max(p - i, i - 1)) tk++;
//			write(Get(i + 1, p).A, ' '), write(A[p - i].A);
			if (tk < kk && Get(i + 1, p) == A[p - i] && res == get(cnt - (i - 1) + 1, cnt))
				ans += (C[tk + 1][tq[i] - 'a'] - C[kk + 1][tq[i] - 'a'] + P) * fpw(2, P - 1 - (n - kk)) % P;
			ans %= P, res = Add(res, tq[i]);
		}
		write(ans % P);
	}
	return 0;
}

/*

aba b aba  b  aba b aba

4 1
aba
bbac
2 bab

4 aba



*/