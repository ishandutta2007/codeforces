// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

template<typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
    os << "{";
    for(int i = 0; i < v.size(); i++)
        os << v[i] << (i+1<v.size()?", ":"");
    os << "}";
    return os;
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
//}}}

const int INF = 1000000000;
struct Edge{
    int src, dst, cost, id;
};
typedef vector<Edge> Node;
typedef vector<Node> Graph;
vector<int> dijkstra(const Graph& G, int s){
    typedef pair<int, int> P;
    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> dist(G.size(), INF);
    que.push(P(0, s));
    dist[s] = 0;
    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second, c = p.first;
        if(c > dist[v]) continue;
        for(auto& e : G[v]){
            if(dist[e.dst] > dist[v] + 1){
                dist[e.dst] = dist[v] + 1;
                que.push(P(dist[e.dst], e.dst));
            }
        }
    }
    return dist;
}

int main(){
    iostream_init();

    int N, M;
    while(cin >> N >> M) {
        Graph G(N);
        vector<int> A(M), B(M), C(M);
        REP(i, M) {
            cin >> A[i] >> B[i] >> C[i];
            const int u = A[i]-1, v = B[i]-1, c = C[i];
            G[u].push_back({u, v, c, i});
            G[v].push_back({v, u, c, i});
        }
        vector<int> dist = dijkstra(G, 0);
        vector<int> dp(N, -INF);
        dp[N-1] = 0;
        vector<pair<int, int>> ps(N);
        REP(i, N) ps[i] = make_pair(dist[i], i);
        sort(ps.begin(), ps.end());
        reverse(ps.begin(), ps.end());
        vector<int> eid(N, -1);
        vector<int> to(N, -1);
        for(const auto& p : ps) {
            int u = p.second;
            for(Edge e : G[u]) if(dp[e.dst] >= 0) {
                if(dp[u] < dp[e.dst] + e.cost && dist[u] + 1 == dist[e.dst]) {
                    dp[u] = dp[e.dst] + e.cost;
                    eid[u] = e.id;
                    to[u] = e.dst;
                }
            }
        }
        vector<bool> used(M);
        for(int cur = 0; cur != N-1;) {
            int e = eid[cur];
            assert(e != -1);
            used[ e ] = true;
            assert(cur != to[cur]);
            cur = to[cur];
        }

        vector<tuple<int, int, int>> ans;
        REP(i, M) {
            if(used[i] && C[i] == 0) {
                ans.push_back(make_tuple(A[i], B[i], 1));
            } else if(!used[i] && C[i] == 1) {
                ans.push_back(make_tuple(A[i], B[i], 0));
            }
        }
        cout << ans.size() << endl;
        REP(i, ans.size()) {
            int a, b, c;
            tie(a, b, c) = ans[i];
            cout << a << " " << b << " " << c << endl;
        }
    }

    return 0;
}

/* vim:set foldmethod=marker: */