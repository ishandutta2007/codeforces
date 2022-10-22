/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Just Run this (Type !!sh in Vim).

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005, mod = 1000000007;
std::vector<par> G[maxn], T[maxn * 6];
int len[maxn];
int deep[maxn];
ll ans[maxn * 6];
std::vector<int> dq[maxn * 6];

int main () {
	int n = read, m = read;
	std::priority_queue<par> q;
	for (int i = 1; i <= m; i ++) {
		len[i] = len[i / 10] + 1;
		int u = read, v = read;
		G[u].push_back(par(v, i));
		G[v].push_back(par(u, i));
	}

	for (int i = 2; i <= n; i ++) deep[i] = 1000000000;

	q.push(par(0, 1));
	while (!q.empty()) {
		int u = q.top().second, d = -q.top().first;
		q.pop();
		if (d > deep[u]) continue;
		for (par p : G[u])
			if (d + len[p.second] < deep[p.first]) {
				deep[p.first] = d + len[p.second];
				q.push(par(-deep[p.first], p.first));
			}
	}

	int ip = n;
	for (int u = 1; u <= n; u ++) {
		int num[10], np = 0;
		for (par p : G[u])
			if (deep[u] + len[p.second] == deep[p.first]) {
				np = 0;
				for (int x = p.second; x; x /= 10)
					num[++ np] = x % 10;
				for (int i = np, x = u; i; i --) {
					int y = i == 1 ? p.first : ++ ip;
					T[x].push_back(par(y, num[i]));
					x = y;
				}
			}
	}

	std::fill(ans + 2, ans + ip + 1, -1);

	dq[0].push_back(1);
	for (int d = 0; !dq[d].empty(); d ++) {
		for (size_t l = 0, r; l < dq[d].size(); l = r + 1) {
			r = l;
			ll now = ans[dq[d][l]];
			while (r + 1 < dq[d].size() and ans[dq[d][r + 1]] == now)
				++ r;
			std::vector<int> tmp[10];
			for (size_t i = l; i <= r; i ++)
				for (par p : T[dq[d][i]])
					tmp[p.second].push_back(p.first);
			for (int x = 0; x < 10; x ++)
				for (int u : tmp[x])
					if (ans[u] == -1) {
						ans[u] = (now * 10 + x) % mod;
						dq[d + 1].push_back(u);
					}
		}
	}

	for (int u = 2; u <= n; u ++)
		printf("%lld\n", ans[u]);
}