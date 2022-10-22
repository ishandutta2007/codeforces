/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  2020.06.03

 * Solution:
   O(n) 


 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 405, maxe = 100000, inf = 1000000000;
int x1[maxn], x2[maxn], y1[maxn], y2[maxn];
int tmp[maxn], tp;
bool cover[maxn][maxn];
int head[maxn], nxt[maxe], to[maxe], cap[maxe], hp = 1;
int cur[maxn], level[maxn];
int S, T;

inline void add (int u, int v, int c) {
	nxt[++ hp] = head[u];
	head[u] = hp;
	to[hp] = v;
	cap[hp] = c;
}

inline void Add (int u, int v, int c) {
	if (!c) return;
	add(u, v, c);
	add(v, u, 0);
}

bool bfs () {
	std::fill(level, level + T + 1, 0);
	std::queue<int> q;
	q.push(S);
	level[S] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u], v; v = to[i], i; i = nxt[i])
			if (cap[i] and !level[v]) {
				level[v] = level[u] + 1;
				q.push(v);
			}
	}
	return level[T];
}

int dfs (int u, int f) {
	if (u == T) return f;
	for (int &i = cur[u], v; v = to[i], i; i = nxt[i])
		if (cap[i] and level[v] == level[u] + 1) {
			int nf = dfs(v, std::min(f, cap[i]));
			if (nf) {
				cap[i] -= nf;
				cap[i ^ 1] += nf;
				return nf;
			}
		}
	return 0;
}

int max_flow () {
	int res = 0;
	while (bfs()) {
		std::copy(head, head + T + 1, cur);
		int f;
		do {
			f = dfs(S, inf);
			res += f;
		} while(f);
	}
	return res;
}

int main () {
	read.operator int();
	int n = read;
	for (int i = 1; i <= n; i ++) {
		read(x1[i], y1[i], x2[i], y2[i]);
		tmp[++ tp] = x1[i] - 1;
		tmp[++ tp] = y1[i] - 1;
		tmp[++ tp] = x2[i];
		tmp[++ tp] = y2[i];
	}

	std::sort(tmp + 1, tmp + tp + 1);
	tp = int(std::unique(tmp + 1, tmp + tp + 1) - tmp - 1);

	for (int i = 1; i <= n; i ++) {
		x1[i] = int(std::lower_bound(tmp + 1, tmp + tp + 1, x1[i]) - tmp);
		x2[i] = int(std::lower_bound(tmp + 1, tmp + tp + 1, x2[i]) - tmp);
		y1[i] = int(std::lower_bound(tmp + 1, tmp + tp + 1, y1[i]) - tmp);
		y2[i] = int(std::lower_bound(tmp + 1, tmp + tp + 1, y2[i]) - tmp);
	}

	for (int i = 1; i <= n; i ++)
		for (int x = x1[i]; x <= x2[i]; x ++)
			for (int y = y1[i]; y <= y2[i]; y ++)
				cover[x][y] = 1;

	S = tp * 2 + 1;
	T = tp * 2 + 2;

	for (int x = 1; x <= tp; x ++)
		Add(S, x, tmp[x] - tmp[x - 1]);
	for (int y = 1; y <= tp; y ++)
		Add(tp + y, T, tmp[y] - tmp[y - 1]);

	for (int x = 1; x <= tp; x ++)
		for (int y = 1; y <= tp; y ++)
			if (cover[x][y])
				Add(x, tp + y, inf);

	printf("%d\n", max_flow());
}