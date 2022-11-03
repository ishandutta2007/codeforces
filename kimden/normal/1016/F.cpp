#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;

vector<vector<pii>> g;
vector<ll> dist;
vector<ll> onpath;
vector<ll> pp, son;

void dfs(ll v, ll pr = -1){
    for(auto p: g[v]){
        ll u = p.first;
        ll w = p.second;
        if(u == pr){
            continue;
        }
        dist[u] = dist[v] + w;
        pp[u] = v;
        dfs(u, v);
        onpath[v] |= onpath[u];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    ll a, b, c;
    dist.resize(n, 0);
    onpath.resize(n, 0);
    pp.resize(n, -1);
    son.resize(n, -1);
    for(ll i = 0; i < n - 1; ++i){
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    onpath[n - 1] = 1;
    dfs(0);
    for(ll i = n - 1; i != 0; i = pp[i]){
        son[pp[i]] = i;
    }
    bool fail = false;
    ll sum = 0;
    vector<pii> arr;
    for(ll i = n - 1; i != -1; i = pp[i]){
        ll z = g[i].size() - (2 - (i == 0 || i == n - 1 ? 1 : 0));
        if(z > 1){
            fail = 1;
            break;
        }
        sum += z + 1;
        ll www = 0;
        for(auto p: g[i]){
            www += p.second;
        }
        if(i != 0){
            www -= dist[i] - dist[pp[i]];
        }
        if(i != n - 1){
            www -= dist[son[i]] - dist[i];
        }
        arr.push_back({www, dist[i]});
    }
    reverse(all(arr));
    if(!fail && sum != n){
        fail = 1;
    }
    ll x;
    ll oooh;
    if(!fail){
        vector<ll> z1(arr.size()), z2(arr.size());
        for(int i = 0; i < arr.size(); ++i){
            z1[i] = arr[i].first + arr[i].second;
            z2[i] = arr[i].first - arr[i].second;
            // cerr << "z1[" << i << "] = " << z1[i] << endl;
            // cerr << "z2[" << i << "] = " << z2[i] << endl;
        }
        for(int i = 1; i < arr.size(); ++i){
            z1[i] = max(z1[i], z1[i - 1]);
        }
        for(int i = (int)arr.size() - 2; i >= 0; --i){
            z2[i] = max(z2[i], z2[i + 1]);
        }
        oooh = -1'000'000'000'000'000'000LL;
        for(int i = 0; i + 2 < arr.size(); ++i){
            oooh = max(oooh, z1[i] + z2[i + 2]);
        }
        for(int i = 0; i + 1 < arr.size(); ++i){
            if(arr[i].first > 0 || arr[i + 1].first > 0)
                oooh = max(oooh, z1[i] + z2[i + 1]);
        }
        if(oooh == -1'000'000'000'000'000'000LL){
            fail = 1;
        }
    }
    for(ll i = 0; i < m; ++i){
        cin >> x;
        if(fail){
            cout << dist[n - 1] << endl;
        }else{
            // cerr << "oooh = " << oooh << endl;
            cout << min(dist[n - 1], dist[n - 1] + oooh + x) << endl;
        }
    }
}