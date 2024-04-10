#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef pair<int, int> P; // (, )
const int INF = 100000000; // infinity

struct Edge{
    int to, cap, cost, rev;
    Edge() {}
    Edge(int t, int c, int cs, int r) : 
        to(t), cap(c), cost(cs), rev(r) {}
};

vector<vector<Edge>> G;

// from  to cap, cost
void add_edge(int from, int to, int cap, int cost){
    G[from].push_back(Edge(to, cap, cost, G[to].size()));
    G[to].push_back(Edge(from, 0, -cost, G[from].size() - 1));
}

// VGstf
// -1
int min_cost_flow(int s, int t, int f, int V){
    vector<int> h(V);
    vector<int> prevv(V), preve(V);
    int res = 0;
    while(f > 0){
        // dijkstrah
        priority_queue<P, vector<P>, greater<P>> que;
        vector<int> dist(V, INF);
        dist[s] = 0;
        que.push(P(0, s));

        while(!que.empty()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(int i = 0; i < G[v].size(); i++){
                Edge& e = G[v][i];
                int ndist = dist[v] + e.cost + h[v] - h[e.to];
                if(e.cap > 0 && dist[e.to] > ndist){
                    dist[e.to] = ndist;
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(ndist, e.to));
                }
            }
        }

        if(dist[t] == INF){
            // 
            return -1;
        }

        for(int v = 0; v < V; v++) h[v] += dist[v];

        int d = f;
        for(int v = t; v != s; v = prevv[v]){
            d = min(d, G[prevv[v]][preve[v]].cap);
        }

        f -= d;
        res += d * h[t];
        for(int v = t; v != s; v = prevv[v]){
            Edge& e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    int cnt[26] = {};
    REP(i, s.size()) cnt[ s[i] - 'a' ] ++;

    // s -> 26 -> n -> t
    int N; cin >> N; 
    const int S = 26 + N;
    const int T = S + 1;
    vector<string> vs(N);
    vector<int> maxc(N);
    REP(i, N) cin >> vs[i] >> maxc[i];

    G.resize(T + 1);
    REP(i, 26) add_edge(S, i, cnt[i], 0);
    REP(j, N){
        int cnt[26] = {};
        REP(k, vs[j].size()) cnt[ vs[j][k] - 'a' ]++;
        REP(i, 26) add_edge(i, 26 + j, cnt[i], 0);
    }
    REP(i, N) add_edge(26 + i, T, maxc[i], i + 1);
    cout << min_cost_flow(S, T, s.size(), T + 1) << endl;
    return 0;
}