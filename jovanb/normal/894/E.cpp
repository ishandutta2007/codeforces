#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool visited[1000005];
vector <pair <ll, ll>> graf1[1000005];
vector <pair <ll, ll>> graf2[1000005];
vector <pair <ll, ll>> dag[1000005];
vector <ll> rdag[1000005];

stack <ll> stek;

void dfs1(ll v){
    visited[v] = 1;
    for(auto par : graf1[v]){
        ll c = par.first;
        if(!visited[c]) dfs1(c);
    }
    stek.push(v);
}

ll cnt;
ll comp[1000005];
ll indeg[1000005];

void dfs2(ll v){
    visited[v] = 1;
    comp[v] = cnt;
    for(auto par : graf2[v]){
        ll c = par.first;
        if(!visited[c]) dfs2(c);
    }
}

struct edge{
    ll a, b, c;
};

ll val[1000005];
ll psum[1000005];
ll nsum[1000005];
ll res[1000005];

ll resi(ll x){
    ll l = 0, r = 15000, g = 0;
    while(l <= r){
        ll mid = (l+r)/2;
        if(psum[mid] <= x){
            g = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    ll sum = (g+1) * x;
    sum -= nsum[g];
    return sum;
}

vector <edge> edges;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll n, m;
    cin >> n >> m;
    for(ll i=1; i<=m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        graf1[a].push_back({b, c});
        graf2[b].push_back({a, c});
        edges.push_back({a, b, c});
    }
    for(ll i=1; i<=100000; i++){
        psum[i] = psum[i-1] + i;
        nsum[i] = nsum[i-1] + psum[i];
    }
    ll s;
    cin >> s;
    /*for(ll i=0; i<=10; i++){
        cout << resi(i) << " ";
    }*/
    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    for(ll i=1; i<=n; i++) visited[i] = 0;
    while(!stek.empty()){
        ll x = stek.top();
        stek.pop();
        if(!visited[x]){
            ++cnt;
            dfs2(x);
        }
    }
    for(auto c : edges){
        if(comp[c.a] == comp[c.b]){
            val[comp[c.a]] += resi(c.c);
        }
        else{
            dag[comp[c.a]].push_back({comp[c.b], c.c});
            indeg[comp[c.b]]++;
        }
    }
    queue <ll> q;
    for(ll i=1; i<=cnt; i++){
        if(indeg[i] == 0) q.push(i);
        res[i] = val[i];
    }
    stack <int> h;
    while(!q.empty()){
        ll x = q.front();
        h.push(x);
        q.pop();
        for(auto c : dag[x]){
            indeg[c.first]--;
            if(!indeg[c.first]) q.push(c.first);
        }
    }
    while(!h.empty()){
        int x = h.top();
        h.pop();
        res[x] = val[x];
        for(auto par : dag[x]){
            res[x] = max(res[x], val[x] + res[par.first] + par.second);
        }
    }
    cout << res[comp[s]] << "\n";
    return 0;
}