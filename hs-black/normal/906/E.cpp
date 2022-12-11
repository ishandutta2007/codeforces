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

const int N = 1000250;
int ch[N][26], ans[N], len[N], g[N], f[N], Pr[N], pre[N];
int anc[N], dif[N];
int cnt = 1, las, n;
char s[N], t[N];
int getfail(int x, int c) {
	while (s[c - len[x] - 1] != s[c]) x = f[x];
	return x;
}
void insert(int c, int x) {
	int p = getfail(las, x);
	if (!ch[p][c]) {
		len[++cnt] = len[p] + 2;
		f[cnt] = ch[getfail(f[p], x)][c];
		dif[cnt] = len[cnt] - len[f[cnt]];
		if (dif[cnt] == dif[f[cnt]]) anc[cnt] = anc[f[cnt]];
		else anc[cnt] = f[cnt];
		ch[p][c] = cnt;
	}
	las = ch[p][c];
}

int main() {
	scanf ("%s", s + 1), scanf ("%s", t + 1);
	int n = strlen(s + 1);
	for (int i = n;i >= 1; i--) 
		s[i * 2 - 1] = s[i], s[i * 2] = t[i];
	n *= 2, f[0] = f[1] = 1, len[1] = -1;
	memset(ans, 0x3f, sizeof(ans)); ans[0] = 0;
	memset(g, 0x3f, sizeof(g));
	for (int i = 1;i <= n; i++) {
		insert(s[i] - 'a', i);
		for (int k = las; k; k = anc[k]) {
			Pr[k] = i - len[anc[k]] - dif[k], g[k] = ans[Pr[k]] + 1;
			if (anc[k] != f[k] && g[f[k]] < g[k]) g[k] = g[f[k]], Pr[k] = Pr[f[k]]; 
			if (!(i & 1) && ans[i] > g[k]) pre[i] = Pr[k], ans[i] = g[k]; 
		}
		if (!(i & 1) && s[i] == s[i-1] && ans[i-2] < ans[i])
			ans[i] = ans[i-2], pre[i] = i - 2;
	}
	if (ans[n] > n) return write(-1), 0;
	write(ans[n]);
	for (int nw = n; nw ; nw = pre[nw])
		if (pre[nw] != nw - 2) 
			write(pre[nw]/2 + 1, ' '), write(nw / 2);
	return 0;
}