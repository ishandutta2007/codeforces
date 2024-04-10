#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

vector <int> graf[N+5];
int dp[N+5];
int deg[N+5];

bool moze[N+5];

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
        deg[b]++;
    }
    queue <int> q;
    for(int i=1; i<=n; i++){
        if(!deg[i]){
            q.push(i);
        }
    }
    vector <int> vec;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        vec.push_back(v);
        for(auto c : graf[v]){
            deg[c]--;
            if(!deg[c]) q.push(c);
        }
    }
    if(vec.size() != n){
        cout << "-1\n";
        return 0;
    }
    for(int i=1; i<=n; i++) dp[i] = i, moze[i] = 1;
    for(auto v : vec){
        moze[v] &= (dp[v] >= v);
        for(auto c : graf[v]) dp[c] = min(dp[c], dp[v]);
    }
    for(int i=1; i<=n; i++) dp[i] = i;
    reverse(vec.begin(), vec.end());
    for(auto v : vec){
        for(auto c : graf[v]) dp[v] = min(dp[v], dp[c]);
        moze[v] &= (dp[v] >= v);
    }
    int res = 0;
    for(int i=1; i<=n; i++) res += moze[i];
    cout << res << "\n";
    for(int i=1; i<=n; i++){
        if(moze[i]) cout << "A";
        else cout << "E";
    }
    cout << "\n";
    return 0;
}