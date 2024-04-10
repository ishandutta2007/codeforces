
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

const int N = 200500, K = 255;
const int P = 1e9 + 7;
int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }

int siz[N], n, k; 
ll f[N][K], S[K][K], cnt[K];
inline void Add(ll &x, ll y) { x += y, x >= P && (x -= P); }

void dfs(int x, int fa) {
	siz[x] = 1, f[x][0] = 1;
	static ll g[K];
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue; dfs(y, x);
		memcpy(g, f[x], k * 8 + 20);
		f[x][0] = (f[x][0] + f[y][0]) % P;
		for (int j = 1;j <= k; j++)
			f[x][j] = (f[x][j] + f[y][j] + f[y][j-1]) % P;
		for (int j = 0;j <= min(k, siz[x]); j++) {
			for (int t = 0;t <= min(k - j, siz[y]); t++) {
				ll v = g[j] * f[y][t] % P;
				Add(f[x][j+t], v), Add(cnt[j+t], v);
				Add(f[x][j+t+1], v), Add(cnt[j+t+1], v);
			}
		}
		siz[x] += siz[y];
	}
}

int main() {
	read(n), read(k);
	for (int i = 1, x, y;i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	S[1][1] = 1;
	for (int i = 2;i <= k; i++)
		for (int j = 1;j <= i; j++)
			S[i][j] = (S[i-1][j-1] + S[i-1][j] * j) % P;
	ll fac = 1, ans = 0; dfs(1, 0);
//	for (int i = 1;i <= k; i++) write(cnt[i], ' ');
//	puts("");
	for (int i = 1;i <= k; i++)
		fac = fac * i % P, ans = (ans + fac * S[k][i] % P * cnt[i]) % P;
	write(ans);
	return 0;
}