#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 205, M = N * 10;

template<class T>
struct Dinic {
    int s , t , n , h[N] , cur[N] , level[N] , q[N] , e , ne[M] , to[M];
    T cap[M] , flow, fl[M];
    void liu(int u,int v,T w){ to[e] = v;ne[e] = h[u];cap[e] = fl[e] = w;h[u] = e++;}
    void link(int u,int v,T w){ liu(u , v , w);liu(v , u , 0);}
    void ini(int _n = N) {fill(h , h + _n , -1); e = 0;}
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
    T run(int _s,int _t,int _n) {
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

const int inf = 0x3f3f3f3f;
int n, m, ans[N][N];

int main() {
	scanf("%d%d", &n, &m);
	gao.ini(2 * n + 2);
	int x;
	int s = 0, t = 2 * n + 1;
	int sb = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		gao.link(s, i, x);
		sb += x;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		sum += x;
		gao.link(i + n, t, x);
	}
	for (int i = 1; i <= n; i++) gao.link(i, i + n, inf);
	int u, v;
	while (m--) {
		scanf("%d%d", &u, &v);
		gao.link(u, v + n, inf);
		gao.link(v, u + n, inf);
	}
	if (sb != sum || gao.run(s, t, 2 * n + 2) != sum) printf("NO\n");
	else {
		printf("YES\n");
		for (int u = 0; u < 2 * n + 2; u++) {
			for (int j = gao.h[u]; j + 1; j = gao.ne[j]) {
				if (j % 2) continue;
				int v = gao.to[j];
				if (u == s || v == t) continue;
				if (v > n) ans[u][v - n] = gao.fl[j] - gao.cap[j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				printf("%d ", ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}