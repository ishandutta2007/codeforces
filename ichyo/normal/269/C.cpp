#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
struct Edge{
    int u, v, c, id;
    Edge() {}
    Edge(int u, int v, int c, int id) :
        u(u), v(v), c(c), id(id) {}
};
typedef vector<Edge> Node;
typedef vector<Node> Graph;

int main(){
    int n, m;
    cin >> n >> m;
    Graph G(n);
    vector<int> f(n);
    REP(i, m){
        Edge e;
        cin >> e.u >> e.v >> e.c;
        e.id = i;
        e.u--; e.v--;
        G[e.u].push_back(e);
        G[e.v].push_back(e);
        f[e.u] += e.c;
        f[e.v] += e.c;
    }
    REP(i, n) f[i] /= 2;
    queue<int> que;
    vector<int> direction(m, -1);
    que.push(0);
    while(!que.empty()){
        int u = que.front(); que.pop();
        for(auto& e : G[u]) if(direction[e.id] == -1){
            int v = (e.u == u ? e.v : e.u);
            direction[e.id] = (e.u == u ? 0 : 1);
            f[v] -= e.c;
            if(f[v] == 0 && v != n - 1){
                que.push(v);
            }
        }
    }

    REP(i, m){
        cout << direction[i] << endl;
    }
    return 0;
}