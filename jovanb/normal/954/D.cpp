#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll raz[1005][1005];
ll n;
vector <ll> graf[1005];

void bfs(ll v){
    queue <ll> q;
    q.push(v);
    while(!q.empty()){
        ll x = q.front();
        for(auto i : graf[x]){
            if(raz[v][i] < 0){q.push(i); raz[v][i] = raz[v][x]+1;}
        }
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    ll m, c1, c2, a, b;
    cin >> n >> m >> c1 >> c2;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(i == j) raz[i][j] = 0;
            else raz[i][j] = -1000000000;
        }
    }
    while(m--){
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++) raz[i][j] = -1000000000;
        raz[i][i] = 0;
        bfs(i);
    }
    ll br=0;
    for(ll i=1; i<=n; i++){
        for(ll j=i+1; j<=n; j++){
            if(raz[i][j] == 1) continue;
            if(min(raz[c1][i]+raz[j][c2]+1, raz[c1][j]+raz[i][c2]+1) >= raz[c1][c2]) br++;
        }
    }
    cout << br;
    return 0;
}