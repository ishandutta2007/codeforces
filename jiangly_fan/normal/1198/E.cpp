//Author: HeXun
//Date: 07-30-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 100000;
int a1[maxn], b1[maxn], a2[maxn], b2[maxn];
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
int x[maxn], y[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i += 1) cin >> a1[i] >> b1[i] >> a2[i] >> b2[i];
	int xn = 0, yn = 0;
	for(int i = 1; i <= m; i += 1){
		x[xn ++] = a1[i];
		//x[xn ++] = a1[i] - 1;
		x[xn ++] = a1[i] + 1;
		x[xn ++] = a2[i];
		//x[xn ++] = a2[i] - 1;
		x[xn ++] = a2[i] + 1;
		y[yn ++] = b1[i];
		//y[yn ++] = b1[i] - 1;
		y[yn ++] = b1[i] + 1;
		y[yn ++] = b2[i];
		//y[yn ++] = b2[i] - 1;
		y[yn ++] = b2[i] + 1;
	}
	sort(x, x + xn);
	xn = unique(x, x + xn) - x;
	sort(y, y + yn);
	yn = unique(y, y + yn) - y;
	set<pair<int, int>> s;
	for(int i = 1; i <= m; i += 1){
		for(int p = 0; p + 1 < xn; p += 1)
			for(int q = 0; q + 1 < yn; q += 1){
				if(x[p] >= a1[i] and x[p + 1] - 1 <= a2[i])
					if(y[q] >= b1[i] and y[q + 1] - 1 <= b2[i]){
						s.insert(make_pair(p, q));
						//cout << x[p] << " " << x[p + 1] << " " << y[q] << " " << y[q + 1] << "\n";
					}
			}
	}
	Dinic d(xn + yn + 2, 0, xn + yn + 1);
	for(auto p : s){
		d.add_edge(p.first + 1, p.second + xn + 1, 1e18);
	}
	//cout << (xn + yn + 2) << endl;
	for(int p = 0; p + 1 < xn; p += 1) d.add_edge(d.s, p + 1, x[p + 1] - x[p]);
	for(int p = 0; p + 1 < yn; p += 1) d.add_edge(p + 1 + xn, d.t, y[p + 1] - y[p]);
	cout << d.flow();
	return 0;
}