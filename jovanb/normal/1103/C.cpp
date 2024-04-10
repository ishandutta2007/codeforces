#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 250000;

vector <int> graf[N+5];

bool visited[N+5];
int depth[N+5];
int par[N+5];

vector <int> leaves;

void dfs(int v, int p){
    visited[v] = 1;
    depth[v] = depth[p] + 1;
    par[v] = p;
    bool leaf = 1;
    for(auto c : graf[v]){
        if(visited[c]) continue;
        leaf = 0;
        dfs(c, v);
    }
    if(leaf) leaves.push_back(v);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m, k;
    cin >> n >> m >> k;
    while(m--){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=1; i<=n; i++){
        if(depth[i] >= ((n + k - 1)/k)){
            cout << "PATH\n";
            cout << depth[i] << "\n";
            int x = i;
            while(x){
                cout << x << " ";
                x = par[x];
            }
            cout << "\n";
            return 0;
        }
    }
    assert(leaves.size() >= k);
    while(leaves.size() > k) leaves.pop_back();
    cout << "CYCLES\n";
    for(auto v : leaves){
        vector <int> gr;
        for(auto c : graf[v]){
            if(c == par[v]) continue;
            if(gr.size() >= 2) break;
            gr.push_back(c);
        }
        int a = gr[0], b = gr[1];
        if((depth[v] - depth[a] + 1)%3){
            cout << depth[v] - depth[a] + 1 << "\n";
            int x = v;
            while(x){
                cout << x << " ";
                if(x == a) break;
                x = par[x];
            }
            cout << "\n";
        }
        else if((depth[v] - depth[b] + 1)%3){
            cout << depth[v] - depth[b] + 1 << "\n";
            int x = v;
            while(x){
                cout << x << " ";
                if(x == b) break;
                x = par[x];
            }
            cout << "\n";
        }
        else{
            if(depth[a] > depth[b]) swap(a, b);
            cout << depth[b] - depth[a] + 2 << "\n";
            cout << v << " ";
            int x = b;
            while(x){
                cout << x << " ";
                if(x == a) break;
                x = par[x];
            }
            cout << "\n";
        }
    }
    return 0;
}