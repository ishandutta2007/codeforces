#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;

int deg[N+5];
int g[N+5];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) deg[i] = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        g[i] = i - x;
        deg[i - x]++;
    }
    queue <int> q;
    for(int i=1; i<=n; i++){
        if(deg[i] == 0) q.push(i);
    }
    int cnt = n;
    while(!q.empty()){
        cnt--;
        int v = q.front();
        q.pop();
        int c = g[v];
        deg[c]--;
        if(!deg[c]) q.push(c);
    }
    cout << cnt << "\n";
    for(int i=1; i<=n; i++) if(deg[i]) cout << i << " ";
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