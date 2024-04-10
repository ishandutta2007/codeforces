#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 400000;

int a[MAXN+5];
int b[MAXN+5];
bool visited[MAXN+5];
vector <int> graf[MAXN+5];

void dfs(int v){
    visited[v] = 1;
    for(auto c : graf[v]) if(!visited[c]) dfs(c);
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }
    for(int i=1; i<=n; i++){
        graf[i].clear();
        visited[i] = 0;
    }
    for(int i=1; i<=n; i++){
        graf[a[i]].push_back(b[i]);
        graf[b[i]].push_back(a[i]);
    }
    int comps = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            comps++;
        }
    }
    int res = 1;
    for(int i=1; i<=comps; i++){
        res = (res*2LL)%1000000007;
    }
    cout << res << "\n";
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