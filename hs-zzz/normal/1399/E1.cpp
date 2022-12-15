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

const int N = 3000500;
ll w[N<<1], n, T, S, sum;
int h[N], ne[N<<1], to[N<<1], siz[N], tot;
inline void add(int x, int y, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}

priority_queue<pair<ll, int> > q;
void dfs(int x, int fa) {
	int fl = 1; siz[x] = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		fl = 0; dfs(y, x), siz[x] += siz[y];
		sum += (ll)w[i] * siz[y];
		q.push(MP((w[i] - w[i] / 2) * siz[y], i));
	}
	siz[x] += fl;
}

int main() {
	for (read(T); T; T--) {
		read(n), read(S); sum = 0;
		memset(h, 0, n * 4 + 50); tot = 0;
		while (q.size()) q.pop();
		for (int i = 1, x, y, z;i < n; i++)
			read(x), read(y), read(z), add(x, y, z), add(y, x, z);
		dfs(1, 0); ll tim = 0;
		while (S < sum) {
			int x = q.top().se; q.pop();
			sum -= (w[x] - w[x] / 2) * siz[to[x]];
			w[x] /= 2; tim++;
			q.push(MP((w[x] - w[x] / 2) * siz[to[x]], x));
		}
		write(tim);
	}
	return 0;
}

/*

2
5 50
1 3 100
1 5 10
2 3 123
5 4 55

2 100
1 2 409


*/