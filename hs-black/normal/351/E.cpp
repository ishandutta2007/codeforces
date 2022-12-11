
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

const int N = 4050;
int vis[N], s1[N], s2[N], p[N], lim, n;
ll f[N][N], ans;
vector<int> v[200050];
int main() {
	read(n);
	for (int i = 1;i <= n; i++) 
		read(p[i]), p[i] < 0 && (p[i] = -p[i]), Mx(lim, p[i]), v[p[i]].push_back(i);
	for (int i = lim;i >= 0; i--) {
		if (!v[i].size()) continue;
		for (auto t: v[i]) vis[t] = 1;
		for (int t = 1;t <= n; t++) s1[t] = s1[t-1] + (!vis[t]);
		for (int t = n;t >= 1; t--) s2[t] = s2[t+1] + (!vis[t]);
		int siz = v[i].size();
		for (int t = 1;t <= siz; t++) {
			memset(f[t], 0x3f, siz * 8 + 20);
			int x = v[i][t-1];
			for (int j = 0;j < t; j++) {
				Mn(f[t][j+1], f[t-1][j] + s2[x]);
				Mn(f[t][j], f[t-1][j] + s1[x] + j);
			}
		}
		ll tp = 1e15;
		for (int i = 0;i <= siz; i++) Mn(tp, f[siz][i]);
		ans += tp;
	}
	write(ans);
	return 0;
}