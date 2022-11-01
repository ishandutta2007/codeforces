#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef vector<int> Node;
typedef vector<Node> Graph;
int dfs(Graph& G, Graph& PG, vector<bool>& elect, int prev, int u){
    int res = 0;
    for(int v : G[u]) if(v != prev) {
        int c = dfs(G, PG, elect, u, v);
        res += c;
    }
    for(int v : PG[u]) if(v != prev) {
        int c = dfs(G, PG, elect, u, v);
        if(c == 0){
            elect[v] = true;
            c++;
        }
        res += c;
    }
    return res;
}

int main(){
    int N;
    while(cin >> N){
        Graph G(N), PG(N);
        REP(i, N - 1){
            int x, y, t;
            cin >> x >> y >> t;
            x--; y--;
            if(t == 1){
                G[x].push_back(y);
                G[y].push_back(x);
            }else{
                PG[x].push_back(y);
                PG[y].push_back(x);
            }
        }
        vector<bool> elect(N);
        int c = dfs(G, PG, elect, -1, 0);
        cout << c << endl;
        REP(i, N) if(elect[i]){
            cout << i + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}