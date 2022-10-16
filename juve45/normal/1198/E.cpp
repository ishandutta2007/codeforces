#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

struct Flow {
    const static long long MAX_EDGES = 551005;
    const static long long MAX_NODES = 6105;
    const long long INF = 1e9 + 50;
 
    long long S = MAX_NODES - 2, D = MAX_NODES - 1;
 
    long long G[MAX_NODES];
    struct Edge {
        long long vec, flow, cap, cost, rev, nxt;
    };
    Edge E[2 * MAX_EDGES];
    long long edges = 0;
 
    long long ParentNode[MAX_NODES], ParentEdge[MAX_NODES], Dist[MAX_NODES];
    bool InQ[MAX_NODES];
    queue<long long> Q;
 
    Flow() {
        Reset();
    }
 
    void setSource(long long s) {
        S = s;
    }
    void setSink(long long d) {
        D = d;
    }
 
    void _addEdge(long long a, long long b, long long cap, long long cost, long long rev) {
        ++edges;
        E[edges] = (Edge) {b, 0, cap, cost, rev, G[a]};
        G[a] = edges;
    }
    void AddEdge(long long a, long long b, long long cap, long long cost) {
        _addEdge(a, b, cap, cost, edges + 2);
        _addEdge(b, a, 0, -cost, edges);
    }
 
    bool Bellman() {
        memset(ParentNode, 0, sizeof(ParentNode));
 
        Dist[S] = 0;
        Q.push(S);
 
 
        while(!Q.empty()) {
            long long top = Q.front();
            InQ[top] = 0;
            Q.pop();
 
            for(long long i=G[top]; i; i=E[i].nxt) {
                long long vec = E[i].vec;
                if(E[i].flow < E[i].cap && (ParentNode[vec] == 0 || Dist[vec] > Dist[top] + E[i].cost)) {
                    Dist[vec] = Dist[top] + E[i].cost;
                    ParentNode[vec] = top;
                    ParentEdge[vec] = i;
 
                    if(!InQ[vec]) {
                        Q.push(vec);
                        InQ[vec] = 1;
                    }
                }
            }
        }
 
        return ParentNode[D] != 0;
    }
 
    void Reset() {
        edges = 0;
        memset(G, 0, sizeof(G));
    }
 
    long long MFMC() {
        long long cost = 0, flow = 0;
 
        while(Bellman()) {
            long long M = INF;
 
            for(long long node = D; node != S; node = ParentNode[node]) {
                long long ei = ParentEdge[node];
                M = min(M, E[ei].cap - E[ei].flow);
            }
 
            for(long long node = D; node != S; node = ParentNode[node]) {
                long long ei = ParentEdge[node],
                    ri = E[ei].rev;
 
                E[ei].flow += M;
                E[ri].flow -= M;
 
                cost += E[ei].cost * M;
            }
 
            flow += M;
        }
        dbg(flow);
        return flow;
    }
 
};
Flow F;

const long long N = 55;
long long n, m, szx, szy, cx[2 * N], cy[2 * N], ok[2 * N][2 * N];
set <long long> xs, ys;
pair<long long, long long> p1[N], p2[N], seg_x[2 * N], seg_y[2 * N];
vector <long long> v;


void put(set <long long> &xs, pair<long long, long long> * seg_x, long long & szx) {
	vector <long long> v;
	xs.insert(1);
	xs.insert(n + 1);
	for(auto i : xs)
		v.push_back(i);
	dbg(v);
	szx = v.size() - 1;
	for(long long i = 1; i < v.size(); i++)
		seg_x[i] = {v[i - 1], v[i]};
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(long long i = 1; i <= m; i++) {
		cin >> p1[i].st >> p1[i].nd;
		cin >> p2[i].st >> p2[i].nd;
		p2[i].st++;
		p2[i].nd++;
		xs.insert(p1[i].st);
		xs.insert(p2[i].st);
		ys.insert(p1[i].nd);
		ys.insert(p2[i].nd);
	}

	put(xs, seg_x, szx);
	put(ys, seg_y, szy);

	dbg_v(seg_x, szx + 1);
	dbg_v(seg_y, szy + 1);

	for(long long i = 1; i <= m; i++) {
		for(long long j = 1; j <= szx; j++)
			for(long long k = 1; k <= szy; k++)
				if(p1[i].st <= seg_x[j].st && seg_x[j].nd <= p2[i].st && 
					 p1[i].nd <= seg_y[k].st && seg_y[k].nd <= p2[i].nd && ok[j][k] == 0) {
					ok[j][k] = 1;
					dbg(j, k, min(seg_x[j].nd - seg_x[j].st, seg_y[k].nd - seg_y[k].st));
					int xx = seg_x[j].nd - seg_x[j].st;
					int yy = seg_y[k].nd - seg_y[k].st;
					cx[j]++;
					cy[k]++;
					F.AddEdge(j, szx + k, 1e18, 0);
				}
	}

	dbg_v(cx, szx + 1);
	for(long long i = 1; i <= szx; i++)
		F.AddEdge(F.S, i, seg_x[i].nd - seg_x[i].st, 0);
	for(long long i = 1; i <= szy; i++)
		F.AddEdge(szx + i, F.D, seg_y[i].nd - seg_y[i].st, 0);
	cout << F.MFMC() << '\n';

}