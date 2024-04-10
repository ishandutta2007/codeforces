#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

vector <int> graf[N+5];
vector <int> vec[2];
vector <int> use[20];

void dfs(int v, int p, int d){
    vec[d].push_back(v);
    for(auto c : graf[v]) if(c != p) dfs(c, v, d ^ 1);
}

int p[N+5];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) graf[i].clear();
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    vec[0].clear(), vec[1].clear();
    dfs(1, 0, 0);
    for(int i=0; i<=19; i++){
        for(int j=(1<<i); j<(1<<(i+1)); j++){
            if(j > n) break;
            use[i].push_back(j);
        }
    }
    if(vec[0].size() > vec[1].size()) swap(vec[0], vec[1]);
    for(int i=0; i<=20; i++){
        if((1 << i) & vec[0].size()){
            for(auto c : use[i]){
                p[vec[0].back()] = c;
                vec[0].pop_back();
            }
            use[i].clear();
        }
    }
    for(int i=0; i<20; i++){
        for(auto c : use[i]){
            p[vec[1].back()] = c;
            vec[1].pop_back();
        }
        use[i].clear();
    }
    for(int i=1; i<=n; i++) cout << p[i] << " ";
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