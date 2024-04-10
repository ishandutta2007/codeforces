// Hydro submission #62878a464b7a66f002ac8b50@1653049927353
// #include <bits/stdc++.h>
// using namespace std;
 
// inline int read() {
// 	int x = 0, f = 0; char c = 0;
// 	while (!isdigit(c)) f |= c == '-', c = getchar();
// 	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
// 	return f ? -x : x;
// }
 
// #define N 2000005
// #define P 1000000007
 
// int n;
// int res, res1, res2, inv[N];
// char s[N], t[N];
 
// int Pow(int x, int k, int r = 1) {
// 	for (; k; k >>= 1, x = x * x % P) {
// 		if (k & 1) r = r * x % P;
// 	}
// 	return r;
// }
 
// struct cdx {
// 	int res, num, s[27];
// 	cdx() {
// 		num = 0, res = 1;
// 		memset(s, 0, sizeof s);
// 	}
// 	void ins(char c) {
// 		int x = c - 'a' + 1;
// 		s[x] ++, num ++;
// 		(res *= num * inv[s[x]] % P) %= P;
// 	}
// 	bool del(char c) {
// 		int x = c - 'a' + 1;
// 		if (x <= 0) return false;
// 		if (x > 26) return false;
// 		if (s[x] == 0) return false;
// 		(res *= s[x] * inv[num] % P) %= P;
// 		s[x] --, num --; return true;
// 	}
// 	int get() {
// 		if (!num) return 0;
// 		else return res;
// 	}
// } a, b;
 
// signed main() {
// 	for (int i = 0; i < N; i ++) {
// 		inv[i] = Pow(i, P - 2);
// 	}
// 	scanf("%s%s", s + 1, t + 1);
// 	n = strlen(s + 1);
// 	for (int i = 1; i <= n; i ++) {
// 		a.ins(s[i]), b.ins(s[i]);
// 	}
// 	res = a.get();
// 	for (int i = 0; i < n; i ++) {
// 		if (i) a.del(s[i]);
// 		for (char c = 'a'; c < s[i + 1]; c ++) {
// 			if (a.del(c)) {
// 				(res1 += a.get()) %= P;
// 				a.ins(c);
// 			}
// 		}
// 	}
// 	for (int i = 0; i <= n; i ++) {
// 		if (i) if (!b.del(t[i])) break;
// 		if (i == n) { res2 ++; break; }
// 		for (char c = t[i + 1] + 1; c <= 'z'; c ++) {
// 			if (b.del(c)) {
// 				(res2 += b.get()) %= P;
// 				b.ins(c);
// 			}
// 		}
// 	}
// 	res = (res - (res1 + res2) % P - 1 + P) % P;
// 	printf("%lld\n", res);
// 	return 0;
// }


#include <bits/stdc++.h>
using namespace std;
#define int long long
 
inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}
 
#define N 2000005
 
int n, m, P, x, o, a[N], inv[N], fac[N];
 
int Pow(int x, int k, int P, int r = 1) {
	if (!x) return 1;
	for (; k; k >>= 1, x = x * x % P) {
		if (k & 1) r = r * x % P;
	}
	return r;
}
int C(int n, int m) {
	if (!m) return 1;
	if (m > n) return 0;
	return fac[n] * inv[m] % o * inv[n - m] % o;
}

signed main() {
	n = read(), m = read(), x = read(), P = read();
	for (o = 1; Pow(x, o, P) != 1; o ++);
	fac[0] = 1;
	for (int i = 1; i <= m; i ++) {
		fac[i] = fac[i - 1] * i % o;
	}
	inv[m] = Pow(fac[m], o - 2, o);
	for (int i = m - 1; ~i; i --) {
		inv[i] = inv[i + 1] * (i + 1) % o;
	}
	int now = 0;
	for (int i = 0; i < n; i ++) {
		(now += C(m, i)) %= o;
		a[n - i] = Pow(x, now, P);
	}
	for (int i = 1; i <= n; i ++) {
		printf("%lld ", a[i]);
	}
	puts("");
	return 0;
}