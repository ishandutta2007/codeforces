#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 100000;

int sz[MAXN+5];
int par[MAXN+5];
vector <int> graf[MAXN+5];

void dfs(int v, int p){
    par[v] = p;
    sz[v] = 1;
    for(auto c : graf[v]){
        if(c == p) continue;
        dfs(c, v);
        sz[v] += sz[c];
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        sz[i] = 0;
        par[i] = 0;
        graf[i].clear();
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0);
    int mnr = n;
    for(int i=1; i<=n; i++){
        int tr = n - sz[i];
        for(auto c : graf[i]){
            if(c == par[i]) continue;
            tr = max(tr, sz[c]);
        }
        mnr = min(mnr, tr);
    }
    vector <int> vec;
    for(int i=1; i<=n; i++){
        int tr = n - sz[i];
        for(auto c : graf[i]){
            if(c == par[i]) continue;
            tr = max(tr, sz[c]);
        }
        if(tr < 0) tr = max(tr, sz[i]);
        if(mnr == tr) vec.push_back(i);
    }
    if(vec.size() == 1){
        cout << "1 " << graf[1][0] << "\n" << "1 " << graf[1][0] << "\n";
        return;
    }
    int pr = vec[0];
    int dr = vec[1];
    if(par[pr] == dr) swap(pr, dr);
    for(auto c : graf[dr]){
        if(c == pr) continue;
        cout << dr << " " << c << "\n" << pr << " " << c << "\n";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}