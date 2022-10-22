#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 200000;

vector <int> graf[MAXN+5];

bool bip;
int color[MAXN+5];
int val[MAXN+5];

void dfs(int v){
    for(auto c : graf[v]){
        if(color[c] == color[v]){
            bip = 0;
            continue;
        }
        if(color[c] == -1){
            color[c] = 1^color[v];
            dfs(c);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> val[i];
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        val[i] = x - val[i];
        graf[i].clear();
    }
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=n; i++) color[i] = -1;
    bip = 1;
    color[1] = 0;
    dfs(1);
    int pr = 0;
    for(int i=1; i<=n; i++){
        pr = (pr+val[i])%2;
    }
    if(pr){
        cout << "NO\n";
        return;
    }
    if(!bip){
        cout << "YES\n";
        return;
    }
    ll sum = 0;
    for(int i=1; i<=n; i++){
        if(color[i]) sum += val[i];
        else sum -= val[i];
    }
    if(sum == 0) cout << "YES\n";
    else cout << "NO\n";
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