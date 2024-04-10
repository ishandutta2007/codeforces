#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int N = 400005;
const ll inf = 1e18;

namespace dinic {
	using cap_type = ll;
	using edg_type = pll;
	const cap_type inf = 1e18;
	const int MAXN = 400005;
	struct edge {
		int des, opo;
		cap_type cap;
	};
	vector<edge> adj[MAXN];
	int n, dis[MAXN], pnt[MAXN];
	void init (int N, vector<edg_type> V[]) {
		n = N;
		for(int i=1;i<=n;i++) {
			adj[i].clear();
		}
		for(int i=1;i<=n;i++) {
			for(auto &T : V[i]) {
				int A; cap_type B;
				tie(A, B) = T;
				adj[i].push_back({A, (int)adj[A].size(), B});
				adj[A].push_back({i, (int)adj[i].size()-1, 0});
			}
		}
	}
	bool bfs (int src, int snk) {
		fill(dis+1, dis+1+n, 0);
		fill(pnt+1, pnt+1+n, 0);
		queue<int> Q;
		Q.push(src);
		dis[src] = 1;
		while(!Q.empty()) {
			int C = Q.front();
			Q.pop();
			for(auto &T : adj[C]) {
				if(T.cap > 0 && !dis[T.des]) {
					dis[T.des] = dis[C] + 1;
					Q.push(T.des);
				}
			}
		}
		return dis[snk] > 0;
	}
	cap_type dfs (int C, int S, cap_type F) {
		if(C == S) return F;
		for(; pnt[C] < (int)adj[C].size(); pnt[C]++) {
			auto &T = adj[C][pnt[C]];
			if(T.cap == 0 || dis[T.des] != dis[C] + 1) continue;
			cap_type R = dfs(T.des, S, min(F, T.cap));
			if(R == 0) continue;
			T.cap -= R;
			adj[T.des][T.opo].cap += R;
			return R;
		}
		return 0;
	}
	cap_type match (int src, int snk) {
		cap_type R = 0;
		while(bfs(src, snk)) {
			cap_type T;
			while((T = dfs(src, snk, inf))) R += T;
		}
		return R;
	}
};

struct compressor {
	vector<int> v;
	void ins (int V) {v.push_back(V);}
	void cpr () {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}
	int get (int V) {return lower_bound(v.begin(), v.end(), V) - v.begin();}
} xcp, ycp;

int n, m, r, b, xc[N], yc[N], x[N], y[N], cit[N];
bool vis[N];

vector<pll> adj[N], xl, yl;

int main()
{
	scanf("%d%d%d%d",&n,&m,&r,&b);
	ll D = abs(r-b);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		xcp.ins(x[i]);
		ycp.ins(y[i]);
	}
	for(int i=1;i<=m;i++) {
		int T, A, B;
		scanf("%d%d%d",&T,&A,&B);
		if(T == 1) {
			xl.push_back({B, A});
			xcp.ins(A);
		}
		else {
			yl.push_back({B, A});
			ycp.ins(A);
		}
	}
	xcp.cpr();
	ycp.cpr();
	int SX = xcp.v.size(), SY = ycp.v.size();
	for(int i=1;i<=n;i++) {
		x[i] = xcp.get(x[i]) + 1;
		y[i] = ycp.get(y[i]) + 1;
		xc[x[i]]++;
		yc[y[i]]++;
		adj[x[i]].push_back({SX+y[i], 1});
	}
	sort(xl.begin(), xl.end());
	sort(yl.begin(), yl.end());
	ll LS = 0;
	for(auto &T : xl) {
		T.Y = xcp.get(T.Y) + 1;
		if(vis[T.Y]) continue;
		vis[T.Y] = true;
		int L = max(0ll, (xc[T.Y] - T.X + 1) / 2), R = (xc[T.Y] + T.X) / 2;
		if(L > R) {puts("-1"); return 0;}
		adj[SX+SY+1].push_back({SX+SY+4, L});
		adj[SX+SY+3].push_back({T.Y, L});
		adj[SX+SY+1].push_back({T.Y, R-L});
		LS += L;
	}
	for(auto &T : yl) {
		T.Y = ycp.get(T.Y) + 1;
		if(vis[SX+T.Y]) continue;
		vis[SX+T.Y] = true;
		int L = max(0ll, (yc[T.Y] - T.X + 1) / 2), R = (yc[T.Y] + T.X) / 2;
		if(L > R) {puts("-1"); return 0;}
		adj[SX+T.Y].push_back({SX+SY+4, L});
		adj[SX+SY+3].push_back({SX+SY+2, L});
		adj[SX+T.Y].push_back({SX+SY+2, R-L});
		LS += L;
	}
	for(ll i=1;i<=SX+SY;i++) {
		if(vis[i]) continue;
		if(i <= SX) adj[SX+SY+1].push_back({i, inf});
		else adj[i].push_back({SX+SY+2, inf});
	}
	adj[SX+SY+2].push_back({SX+SY+1, inf});
	dinic::init(SX+SY+4, adj);
	ll F1 = dinic::match(SX+SY+3, SX+SY+4);
	if(F1 != LS) {puts("-1"); return 0;}
	ll F2 = dinic::match(SX+SY+1, SX+SY+2);
	string col = "";
	ll ans = 0;
	for(ll i=1;i<=n;i++) {
		ll T = !dinic::adj[x[i]][cit[x[i]]++].cap;
		ans += max(r, b) - T * D;
		col += ((T^(r<b))?'b':'r');
	}
	printf("%lld\n%s\n", ans, col.c_str());
}