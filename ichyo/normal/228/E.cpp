#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef vector<int> Node;
typedef vector<Node> Graph;

void add_edge(Graph& G, int a, int b) {
    G[a].push_back(b);
}

// Complexity: O(|V| + |E|)
int scc(const Graph& G, const Graph& RG, vector<int>& cmp) {
    int n = G.size();
    int K = 0; // the number of components
    cmp.assign(n, -1); // cmp[v] := component id of vertex v (0, 1, ..., K-1)
    vector<bool> used(n);
    vector<int> order;
    // ordinary dfs
    function<void(int)> dfs = [&](int u) {
        used[u] = true;
        for(int w : G[u]) if(!used[w]) {
            dfs(w);
        }
        order.push_back(u);
    };
    for(int u = 0; u < n; u++) if(!used[u]) {
        dfs(u);
    }
    reverse(order.begin(), order.end());
    // reverse dfs
    function<void(int)> rdfs = [&](int u) {
        cmp[u] = K;
        for(int w : RG[u]) if(cmp[w] == -1) {
            rdfs(w);
        }
    };
    for(int u : order) if(cmp[u] == -1) {
        rdfs(u);
        K++;
    }
    return K;
}

struct SAT2{
    int n, V;
    Graph G, RG;
    vector<int> truth;
    SAT2(int n) : n(n), V(2 * n), G(V), RG(V) {}
    // p   (<=> "(not p)  p")
    void set_t(int p){
        imply(inv(p), p);
    }
    // p  q (<=> "(not a)  b"  "(not b)  a")
    void set_or(int p, int q) {
        imply(inv(p), q);
        imply(inv(q), p);
    }
    // p  q
    void imply(int p, int q){
        add_edge(G, p, q);
        add_edge(RG, q, p);
    }
    void set_xor(int p, int q) {
        imply(p, inv(q));
        imply(q, inv(p));
        imply(inv(p), q);
        imply(inv(q), p);
    }
    void set_eq(int p, int q) {
        imply(p, q);
        imply(inv(p), inv(q));
        imply(q, p);
        imply(inv(q), inv(p));
    }
    // (`truth`)
    bool satisfy(){
        vector<int> comp;
        scc(G, RG, comp);
        truth.assign(n, false);
        for(int i = 0; i < n; i++){
            if(comp[i] == comp[i + n]) return false;
            if(comp[i] > comp[i + n]) truth[i] = true;
        }
        return true;
    }
    // not p
    int inv(int p){
        return (p + n) % V;
    }
};

int main(){
    int n, m;
    while(cin >> n >> m) {
        SAT2 sat2(n);
        REP(i, m) {
            int a, b, c;
            cin >> a >> b >> c;
            // c == 1 ((a and b) or (not a and not b))
            // c == 0 ((a and not b) or (not a and b))
            // a or (b and c) (a or b) and (a or c)
            a--; b--;
            if(c == 0) {
                sat2.set_xor(a, b);
            } else {
                sat2.set_eq(a, b);
            }
        }
        bool res = sat2.satisfy();
        if(!res) {
            cout << "Impossible" << endl;
            continue;
        }
        vector<int> v;
        REP(i, n) if(sat2.truth[i]) {
            v.push_back(i);
        }
        cout << v.size() << endl;
        REP(i, v.size()) {
            cout << v[i] + 1;
            if(i + 1 < v.size()) cout << " ";
        }
        cout << endl;
    }
    return 0;
}