#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;

bool in[N+5];
bool isti[N+5][N+5][N+5];

int n;

vector <int> graf[N+5];

void dfs(int v, int p){
    for(int i=1; i<=n; i++){
        if(in[i]) continue;
        if(isti[p][i][v]){
            in[i] = 1;
            graf[v].push_back(i);
            graf[i].push_back(v);
            dfs(i, v);
        }
    }
}

int dist[N+5][N+5];

void bfs(int root){
    for(int i=1; i<=n; i++) dist[root][i] = N + 5;
    dist[root][root] = 0;
    queue <int> q;
    q.push(root);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto c : graf[v]){
            if(dist[root][c] > dist[root][v] + 1){
                dist[root][c] = dist[root][v] + 1;
                q.push(c);
            }
        }
    }
}

bool check(){
    for(int i=1; i<=n; i++) if(!in[i]) return 0;
    for(int i=1; i<=n; i++) bfs(i);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(i == j || j == k || k == i) continue;
                if((dist[i][k] == dist[j][k]) != (isti[i][j][k])) return 0;
            }
        }
    }
    return 1;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                isti[i][j][k] = 0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            string s;
            cin >> s;
            for(int k=1; k<=n; k++){
                if(s[k-1] == '1') isti[i][j][k] = isti[j][i][k] = 1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(isti[i][j][i] || isti[i][j][j]){
                cout << "No\n";
                return;
            }
        }
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<=n; j++) graf[j].clear();
        graf[1].push_back(i);
        graf[i].push_back(1);
        for(int j=1; j<=n; j++){
            in[j] = 0;
            if(j == 1 || j == i) in[j] = 1;
        }
        dfs(1, i);
        dfs(i, 1);
        if(check()){
            cout << "Yes\n";
            for(int i=1; i<=n; i++){
                for(auto c : graf[i]){
                    if(i < c) cout << i << " " << c << "\n";
                }
            }
            return;
        }
    }
    cout << "No\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
}