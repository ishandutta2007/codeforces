#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
struct Dinic{ // [0,n) init!!
    const static int N = 205 , M = 4005;
    int s , t , n , h[N] , cur[N] , level[N] , q[N] , e , ne[M] , to[M];
    T cap[M] , flow;
    void liu(int u,int v,T w){ to[e] = v;ne[e] = h[u];cap[e] = w;h[u] = e++;}
    void link(int u,int v,T w){ liu(u , v , w);liu(v , u , 0);}
    void ini(int _n = N) { fill(h , h + _n , -1);e = 0;}
    bool bfs(){
        int L = 0 , R = 0;
        fill(level , level + n , -1);
        level[q[R++] = s] = 0;
        while(L < R && level[t] == -1){
            int c = q[L++];
            for(int k=h[c];~k;k=ne[k])
                if(cap[k] > 0 && level[to[k]] == -1)
                    level[q[R++] = to[k]] = level[c] + 1;
        }
        return ~level[t];
    }
    T dfs(int c,T mx){
        if(c == t) return mx;
        T ret = 0;
        for(int &k = cur[c];~k;k = ne[k]){
            if(level[to[k]] == level[c] + 1 && cap[k] > 0){
                T flow = dfs(to[k] , min(mx , cap[k]));
                ret += flow;cap[k] -= flow , cap[k^1] += flow;mx -= flow;
                if(!mx) return ret;
            }
        }
        level[c] = -1;
        return ret;
    }
    T run(int _s,int _t,int _n){
        s = _s , t = _t , n = _n;
        flow = 0;
        while(bfs()){
            copy(h , h + n , cur);
            flow += dfs(s,~0U>>1);
        }
        return flow;
    }
};
Dinic<int> gao;
int n, m;
struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}
	void read() {
		scanf("%d%d%d", &u, &v, &w);
	}
	bool operator < (const Edge& c) const {
		return w > c.w;
	}
} e[1005], E[205];
int en;

int ans;
int id[205], S[205], T[205];

void solve(int l, int r) {
	if (l == r) return;
	gao.ini(n + 1);
	for (int i = 0; i < m; i++) {
		gao.link(e[i].u, e[i].v, e[i].w);
		gao.link(e[i].v, e[i].u, e[i].w);
	}
	int tmp = gao.run(id[l], id[r], n + 1);
	ans += tmp;
	E[en++] = Edge(id[l], id[r], tmp);
	int sn = 0, tn = 0;
	for (int i = l; i <= r; i++) {
		if (gao.level[id[i]] == -1) T[tn++] = id[i];
		else S[sn++] = id[i];
	}
	for (int i = 0; i < sn; i++) id[i + l] = S[i];
	for (int i = 0; i < tn; i++) id[i + l + sn] = T[i];
	solve(l, l + sn - 1);
	solve(l + sn, l + sn + tn - 1);
}

int fa[205];
vector<int> g[205];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i++) id[i] = i;
		for (int i = 0; i < m; i++) e[i].read();
		en = ans = 0;
		solve(1, n);
		printf("%d\n", ans);
		sort(E, E + en);
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
			g[i].push_back(i);
		}
		for (int i = 0; i < en; i++) {
			int pu = find(E[i].u);
			int pv = find(E[i].v);
			if (pu != pv) {
				fa[pu] = pv;
				g[pv].insert(g[pv].end(), g[pu].begin(), g[pu].end());
			}
		}
		int rt = find(1);
		for (int i = 0; i < g[rt].size(); i++) printf("%d ", g[rt][i]); printf("\n");
	}
	return 0;
}