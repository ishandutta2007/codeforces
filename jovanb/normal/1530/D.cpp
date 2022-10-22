#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

vector <int> u[N+5];
int deg[N+5];
int p[N+5];
int res[N+5];
int taken[N+5];

void dfs(int v){
    if(!taken[p[v]]){
        taken[p[v]] = 1;
        res[v] = p[v];
        dfs(p[v]);
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        deg[i] = 0;
        u[i].clear();
        res[i] = 0;
        taken[i] = 0;
    }
    for(int i=1; i<=n; i++){
        cin >> p[i];
        deg[p[i]]++;
    }
    for(int i=1; i<=n; i++){
        if(!deg[i]) dfs(i);
    }
    for(int i=1; i<=n; i++){
        if(!taken[i]) dfs(i);
    }
    set <int> free;
    for(int i=1; i<=n; i++){
        if(!taken[i]) free.insert(i);
    }
    vector <int> f2;
    vector <int> f1;
    for(int i=1; i<=n; i++){
        if(!res[i]){
            if(free.find(i) != free.end()) f2.push_back(i);
            else f1.push_back(i);
        }
    }
    sort(f2.begin(), f2.end());
    if(f2.size() == 1){
        if(free.size() == 1 && *free.begin() == f2[0]){
            int g = f2[0];
            res[g] = p[g];
            res[p[g]] = g;
            free.erase(g);
            f2.pop_back();
        }
        else{
            int x = *free.begin();
            if(x == f2[0]) x = *free.rbegin();
            res[f2[0]] = x;
            free.erase(x);
            f2.pop_back();
        }
    }
    if(f2.size() > 1){
        for(int i=0; i+1<f2.size(); i++){
            res[f2[i]] = f2[i+1];
        }
        res[f2.back()] = f2[0];
        for(auto c : f2) free.erase(c);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(!res[i]){
            res[i] = *free.begin();
            free.erase(free.begin());
        }
    }
    for(int i=1; i<=n; i++){
        if(res[i] == p[i]) cnt++;
    }
    cout << cnt << "\n";
    for(int i=1; i<=n; i++) cout << res[i] << " ";
    cout << "\n";
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

/*
1
5
2 3 1 3 3
*/

/*
1
4
2 1 4 3
*/