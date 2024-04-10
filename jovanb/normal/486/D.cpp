#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int rut;

ll brn[2005];
ll val[2005];
vector <int> graf[2005];
int d;
bool visited[2005];

const int MOD = 1000000007;

void dfs(int v){
    visited[v] = 1;
    for(auto c : graf[v]){
        if(visited[c]) continue;
        if(val[c] > val[rut]+d || val[c] < val[rut]) continue;
        if(val[c] == val[rut] && c > rut) continue;
        dfs(c);
        brn[v] = (brn[v]*(brn[c]+1))%MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> d >> n;
    for(int i=1; i<=n; i++) cin >> val[i];
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    ll res=0;
    for(rut=1; rut<=n; rut++){
        for(int i=1; i<=n; i++){
            brn[i] = 1;
            visited[i] = 0;
        }
        dfs(rut);
        res = (res+brn[rut])%MOD;
    }
    cout << res;
    return 0;
}