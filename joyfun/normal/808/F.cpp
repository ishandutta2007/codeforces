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

template<class T>
struct Dinic{// [0,n) init!!
    const static int N = 10101 , M = N * 10;
    int s , t , n , h[N] , cur[N] , level[N] , q[N] , e , ne[M] , to[M];
    T cap[M] , flow;
    void liu(int u,int v,T w){ to[e] = v;ne[e] = h[u];cap[e] = w;h[u] = e++;}
    void link(int u,int v,T w){ liu(u , v , w);liu(v , u , 0);}
    void ini(int _n = N) { fill(h , h + (n=_n) , -1);e = 0;}
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
    T run(int _s,int _t){
        s = _s , t = _t;
        flow = 0;
        while(bfs()){
            copy(h , h + n , cur);
            flow += dfs(s,~0U>>1);
        }
        return flow;
    }
};
Dinic<int> gao;

const int N = 105;
int n, k;
struct ST {
	int p, c, l;
	void read() {
		scanf("%d%d%d", &p, &c, &l);
	}
	bool operator < (const ST& x) const {
		if (c == x.c) return p > x.p;
		return c > x.c;
	}
} st[N];

const int inf = 0x3f3f3f3f;
const int M = 222222;
int vis[M];

bool judge(int mid) {
	gao.ini(n + 2);
	int S = 0, T = n + 1;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (st[i].l > mid) continue;
		sum += st[i].p;
		if (st[i].c % 2) gao.link(S, i, st[i].p);
		else gao.link(i, T, st[i].p);
	}
	for (int i = 1; i <= n; i++) {
		if (st[i].l > mid) continue;
		if (st[i].c % 2) {
			for (int j = 1; j <= n; j++) {
				if (st[j].l > mid) continue;
				if (st[j].c % 2 == 0) {
					if (vis[st[i].c + st[j].c] == 0) gao.link(i, j, inf);
				}
			}
		}
	}
	return sum - gao.run(S, T) >= k;
}

int main() {
	vis[0] = vis[1] = 1;
	for (int i = 2; i < M; i++) {
		if (vis[i]) continue;
		if (1ll * i * i >= 1ll * M) continue;
		for (int j = i * i; j < M; j += i)
			vis[j] = 1;
	}
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) st[i].read();
	sort(st + 1, st + 1 + n);
	while (n >= 2 && st[n - 1].c == 1) n--;
	if (!judge(n)) printf("-1\n");
	else {
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r)>>1;
			if (judge(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}