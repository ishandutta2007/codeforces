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

const int N = 2e6+5;
const int P = 1e9+7;
char s[N], ts[N];
int ans[N], ch[N][26], f[N], g[N], anc[N], cnt = 1, las;
int dif[N], len[N], n; 

int getfail(int x, int c) {
	while (s[c - len[x] - 1] != s[c]) x = f[x];
	return x;
}

void insert(int c, int x) {
	int p = getfail(las, x);
	if (!ch[p][c]) {
		len[++cnt] = len[p] + 2, f[cnt] = ch[getfail(f[p], x)][c];
		dif[cnt] = len[cnt] - len[f[cnt]], ch[p][c] = cnt;
		anc[cnt] = (dif[cnt] == dif[f[cnt]]) ? anc[f[cnt]] : f[cnt];
	}
	las = ch[p][c];
}

inline void add(int &x, int y) {
	x += y, x >= P && (x -= P);
}

int main() {
	scanf ("%s", ts + 1); n = strlen(ts + 1);
	if (n & 1) return write(0), 0; int t = 0;
	for (int i = 1, j = n;i <= j; i++, j--) s[++t] = ts[i], s[++t] = ts[j];
	len[1] = -1, f[0] = f[1] = ans[0] = 1;
	for (int i = 1;i <= n; i++) {
		insert(s[i] - 'a', i);
		for (int k = las; k; k = anc[k]) {
			g[k] = ans[i - len[anc[k]] - dif[k]];
			if (anc[k] != f[k]) add(g[k], g[f[k]]);
			if (!(i & 1)) add(ans[i], g[k]);
		}
	}
	write(ans[n]);
	return 0;
}