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

const int N = 300500, M = N << 2;
int cnt;
namespace Graph {
    int h[N], to[M], ne[M], w[M], tot = 1, s, t;
    inline void add(int x, int y, int z) {
        ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
    }
    
    inline void adde(int x, int y, int z) { add(x, y, z), add(y, x, 0); }
    
    int dep[N], cur[N];
    int dfs(int x, int lim) {
        if (!lim || x == t) return lim;
        int res = 0, fl;
        for (int &i = cur[x], y; i; i = ne[i]) {
            if (dep[y = to[i]] != dep[x] + 1 || !w[i]) continue;
            fl = dfs(y, min(lim, w[i]));
            w[i] -= fl, w[i ^ 1] += fl, res += fl, lim -= fl;
            if (!lim) break;
        }
        return res;
    }
    
    queue<int> q;
    bool bfs(void) {
        memset(dep, 0, sizeof(dep));
        dep[s] = 1;
        q.push(s);
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int i = h[x]; i; i = ne[i]) {
                int y = to[i]; if (dep[y] || !w[i]) continue;
                dep[y] = dep[x] + 1, q.push(y);
            }
        }
        memcpy(cur, h, sizeof(h));
        return dep[t];
    }
    int Maxflow(void) {
        int ans = 0;
        while (bfs()) ans += dfs(s, 1e9);
        return ans;
    }
}
using Graph::adde;
using Graph::Maxflow;

int pre[105], n;
ll sum;
int main() {
	read(n), cnt = n + 2; Graph::s = n + 1, Graph::t = n + 2;
	for (int i = 1, x;i <= n; ++i) {
		read(x);
		for (int j = 1;j <= x; ++j) {
			if (x % j == 0) {
				++cnt;
				if (pre[j]) adde(cnt, pre[j], 1e9);
				pre[j] = cnt; adde(i, cnt, 1e9);
			}
		}
		adde(cnt, i, 1e9);
	}
	for (int i = 1, x;i <= n; ++i) {
		read(x);
		if (x < 0) adde(i, n + 2, -x);
		else sum += x, adde(Graph::s, i, x);
	}
	write(sum - Graph::Maxflow());
	return 0;
}