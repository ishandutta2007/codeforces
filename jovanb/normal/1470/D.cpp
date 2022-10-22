#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int col[300005];
vector <int> graf[300005];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        col[i] = -1;
        graf[i].clear();
    }
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    set <int> bcand;
    bcand.insert(1);
    while(!bcand.empty()){
        int v = *bcand.begin();
        bcand.erase(bcand.begin());
        if(col[v] == 1) continue;
        col[v] = 0;
        queue <int> ws;
        for(auto c : graf[v]){
            if(col[c] == -1){
                ws.push(c);
                col[c] = 1;
            }
        }
        while(!ws.empty()){
            int v = ws.front();
            ws.pop();
            for(auto c : graf[v]) if(col[c] == -1) bcand.insert(c);
        }
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(col[i] == -1){
            cout << "NO\n";
            return;
        }
        if(col[i] == 0) cnt++;
    }
    cout << "YES\n";
    cout << cnt << "\n";
    for(int i=1; i<=n; i++){
        if(!col[i]) cout << i << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}