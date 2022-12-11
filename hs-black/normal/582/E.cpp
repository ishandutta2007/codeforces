#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	static short st[30], tp; 
	if (x < 0) putchar('-'), x = -x;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

template <typename T>
void write2(T x, char ed = '\n') {
	static short st[60], tp; 
	if (x < 0) putchar('-'), x = -x;
	do st[++tp] = x % 2, x /= 2; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

const int N = (1 << 16) + 5;
const int P = 1e9 + 7, lim = 1 << 16;
inline int mod(int x) { return x >= P ? x - P : x; }
void FWT(int *f, int f1, int f2 = 0) {
	for (int i = 1;i < lim; i <<= 1)
		for (int j = 0;j < lim; j += i << 1)
			for (int k = 0;k < i; ++k) {
				int x = j + k, y = i + j + k;
				if (f1) swap(x, y);
				f[y] = mod(f[y] + (f2 ? P - f[x] : f[x]));
			}
}

char s[555];
int tr[555], cnt, n;
int f[205][N], len;
int build(int l, int r) {
	if (r == l) {
		//write(s[l]);
		int k = tr[s[l]]; ++cnt;
		for (int j = 0;j < 8; ++j) if (k == j || s[l] == '?') {
			int bt = 0, a = j & 3, b = j >> 2 & 1;
			for (int i = 0;i < 16; ++i) 
				bt |= ((i >> a & 1) ^ b) << i;
			//write2(bt);
			++f[cnt][bt];
		}
		return cnt;
	}
	int fl = 1, st = l + 1;
	while (fl) fl += s[st] == '(', fl -= s[st] == ')', ++st;
	int ls = build(l + 1, st - 2), rs = build(st + 2, r - 1);
	auto Addin = [&](int *f, int *a, int *b, int fl) {
		static int A[N], B[N];
		memcpy(A, a, sizeof(A)), memcpy(B, b, sizeof(B));
		FWT(A, fl), FWT(B, fl);
		for (int i = 0;i < lim; ++i) A[i] = 1ll * A[i] * B[i] % P;
		FWT(A, fl, 1);
		for (int i = 0;i < lim; ++i) f[i] = mod(f[i] + A[i]);
	};
	++cnt;
	if (s[st] != '|') Addin(f[cnt], f[ls], f[rs], 1);
	if (s[st] != '&') Addin(f[cnt], f[ls], f[rs], 0);
	return cnt;
}

int main() {
	//freopen ("hs.in","r",stdin);
	scanf ("%s", s + 1), len = strlen(s + 1);
	for (int i = 0;i < 4; ++i) tr['A' + i] = i, tr['a' + i] = i + 4;
	int rt = build(1, len);
	int all = 0, bt = 0, n;
	read(n); 
	for (int i = 1;i <= n; ++i) {
		int a, b, c, d, e, k;
		read(a), read(b), read(c), read(d), read(e);
		k = a | (b << 1) | (c << 2) | (d << 3);
		//write(k);
		bt |= e << k, all |= 1 << k;
		//write2(all), write2(bt);
	}
	ll ans = 0;
	for (int i = 0;i < lim; ++i)
		if ((i & all) == bt) ans += f[rt][i];
	write(ans % P);
	return 0;
}