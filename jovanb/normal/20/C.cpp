#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <pair <ll, ll>> graf[100005];
ll dist[100005];
ll doso[100005];

const ll INF = 1000000000000000000;

void dij(ll v){
    set <pair <ll, ll>> s;
    s.insert({0, v});
    while(!s.empty()){
        auto x = s.begin()->second;
        s.erase(s.begin());
        for(auto par : graf[x]){
            ll c = par.first;
            ll d = par.second;
            if(dist[x]+d < dist[c]){
                s.erase({dist[c], c});
                dist[c] = dist[x]+d;
                s.insert({dist[c], c});
                doso[c] = x;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll n, m;
    cin >> n >> m;
    while(m--){
        ll a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }
    for(ll i=2; i<=n; i++){
        doso[i] = -1;
        dist[i] = INF;
    }
    dij(1);
    if(dist[n] == INF){cout << -1; return 0;}
    ll x = n;
    stack <ll> stek;
    while(1){
        stek.push(x);
        if(x == 1) break;
        x = doso[x];
    }
    while(!stek.empty()){
        cout << stek.top() << " ";
        stek.pop();
    }
    return 0;
}