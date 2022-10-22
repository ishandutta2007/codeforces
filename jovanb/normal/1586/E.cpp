#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300000;

vector <int> graf[N+5];
int qa[N+5], qb[N+5];
int dg[N+5];
int par[N+5];
int in[N+5], out[N+5];
bool visited[N+5];

int tjm;

void dfs(int v, int p){
    in[v] = ++tjm;
    par[v] = p;
    visited[v] = 1;
    for(auto c : graf[v]) if(!visited[c]) dfs(c, v);
    out[v] = ++tjm;
}

bool is_parent(int a, int b){
    return (a == 0) || (in[a] <= in[b] && out[b] <= out[a]);
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
    int qrs;
    cin >> qrs;
    for(int i=1; i<=qrs; i++){
        cin >> qa[i] >> qb[i];
        dg[qa[i]]++;
        dg[qb[i]]++;
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(dg[i]%2) cnt++;
    }
    if(cnt){
        cout << "NO\n" << cnt/2 << "\n";
        return 0;
    }
    cout << "YES\n";
    dfs(1, 0);
    for(int i=1; i<=qrs; i++){
        int a = qa[i], b = qb[i];
        vector <int> v1;
        int v = a;
        while(!is_parent(v, b)){
            v1.push_back(v);
            v = par[v];
        }
        vector <int> v2;
        v = b;
        while(!is_parent(v, a)){
            v2.push_back(v);
            v = par[v];
        }
        reverse(v2.begin(), v2.end());
        cout << v1.size() + 1 + v2.size() << "\n";
        for(auto c : v1) cout << c << " ";
        cout << v << " ";
        for(auto c : v2) cout << c << " ";
        cout << "\n";
    }
    return 0;
}