#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

int cnt;
vector <int> graf[N+5];
bool visited[N+5];

void dfs(int v){
    visited[v] = 1;
    cnt++;
    for(auto c : graf[v]) if(!visited[c]) dfs(c);
}

int a[N+5], b[N+5];

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
    }
    for(int i=1; i<=n; i++){
        if(a[i] == b[i]) continue;
        graf[a[i]].push_back(b[i]);
        graf[b[i]].push_back(a[i]);
    }
    int m = 0;
    for(int i=1; i<=n; i++) visited[i] = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cnt = 0;
            dfs(i);
            m += cnt/2;
        }
    }
    ll res = 0;
    for(int i=1; i<=m; i++) res -= 2*i;
    for(int i=n; n-i+1<=m; i--) res += 2*i;
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

/*
1
6
1 5 4 3 2 6
5 3 1 4 6 2
*/