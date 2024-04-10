#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int val[50005];

vector <int> nvec;

vector <int> graf[505];
vector <pair <int, int>> edges;

bool visited[505];

void dfs(int v){
    visited[v] = 1;
    nvec.push_back(v);
    for(auto c : graf[v]) if(!visited[c]) dfs(c);
}

int cnt;
int a[505][505];

int solve(vector <int> vec){
    if(vec.size() == 1){
        val[vec[0]] = a[vec[0]][vec[0]];
        return vec[0];
    }
    int mx = 0;
    for(auto c : vec){
        visited[c] = 0;
        graf[c].clear();
        for(auto d : vec){
            mx = max(mx, a[c][d]);
        }
    }
    val[++cnt] = mx;
    int tn = cnt;
    for(auto c : vec){
        for(auto d : vec){
            if(a[c][d] < mx){
                graf[c].push_back(d);
                graf[d].push_back(c);
            }
        }
    }
    for(auto c : vec){
        if(!visited[c]){
            nvec.clear();
            dfs(c);
            int g = solve(nvec);
            edges.push_back({tn, g});
        }
    }
    return tn;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    cnt = n;
    vector <int> vec;
    for(int i=1; i<=n; i++){
        vec.push_back(i);
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    int k = solve(vec);
    cout << cnt << "\n";
    for(int i=1; i<=cnt; i++) cout << val[i] << " ";
    cout << "\n";
    cout << k << "\n";
    for(auto c : edges) cout << c.second << " " << c.first << "\n";
    return 0;
}