#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 100000;

bool visited[MAXN+5];
vector <int> graf[MAXN+5];

int cyclic;

void dfs(int v, int p){
    visited[v] = 1;
    for(auto c : graf[v]){
        if(visited[c]){
            if(c != p) cyclic = 1;
        }
        else dfs(c, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int res = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cyclic = 0;
            dfs(i, 0);
            res += 1 - cyclic;
        }
    }
    cout << res << "\n";
    return 0;
}