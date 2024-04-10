#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

struct BipartiteMatching{
    typedef vector<int> Node;
    typedef vector<Node> Graph;

    Graph G;
    vector<int> match;
    vector<bool> used;

    BipartiteMatching(int N) : G(N) {}

    void add_edge(int u, int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool dfs(int u){
        used[u] = true;
        for(int v : G[u]){
            int w = match[v];
            if(w < 0 || (!used[w] && dfs(w))){
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    int matching(){
        int res = 0;
        match.assign(G.size(), -1);
        for(int u = 0; u < G.size(); u++){
            if(match[u] < 0){
                used.assign(G.size(), false);
                if(dfs(u)) res++;
            }
        }
        return res;
    }
};

int main(){
    int n, m;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    REP(i, m) cin >> b[i];

    BipartiteMatching bm(n + m);
    REP(i, n) REP(j, m) {
        if(abs(a[i] - b[j]) <= 1) {
            bm.add_edge(i, n + j);
        }
    }

    cout << bm.matching() << endl;

    return 0;
}