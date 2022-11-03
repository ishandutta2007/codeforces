#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<ll> c;
vector<pair<ll, pll>> e;
vector<ll> dsu;
vector<ll> mkd;
vector<ll> mkd2;
set<ll> s;
const ll mod = 1000000007;
const ll rev2 = 500000004;
ll n, m, k;
ll comps;

ll binpow(ll x, ll p){
    ll ans = 1;
    while(p){
        if(p & 1LL){
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        p >>= 1LL;
    }
    return ans;
}

ll clean(){
    for(auto x: mkd2){
        mkd[x] = 0;
        dsu[x] = -1;
    }
    comps = n;
    mkd2.clear();
}

ll getp(ll x){
    if(dsu[x] < 0){
        return x;
    }
    return dsu[x] = getp(dsu[x]);
}

ll unite(ll u, ll v){
    if(!mkd[u]){
        mkd[u] = 1;
        mkd2.push_back(u);
    }
    if(!mkd[v]){
        mkd[v] = 1;
        mkd2.push_back(v);
    }
    u = getp(u);
    v = getp(v);
    if(u == v){
        return 0;
    }
    if(dsu[u] > dsu[v]){
        swap(u, v);
    }
    dsu[u] += dsu[v];
    dsu[v] = u;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    c.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    for(int i = 0; i < m; ++i){
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        e.push_back({c[u] ^ c[v], {u, v}});
        s.insert(c[u] ^ c[v]);
    }
    ll sum = binpow(2, k);
    sum -= s.size() % mod;
    if(sum < 0){
        sum += mod;
    }
    sum = (sum * binpow(2, n)) % mod;
    sort(all(e));
    mkd.resize(n, 0);
    mkd2.clear();
    dsu.resize(n, -1);
  //  cout << sum << endl;
    for(int i = 0; i <= (int)e.size(); ++i){
        if(i == 0 || i == (int)e.size() || e[i].first != e[i - 1].first){
            if(i){
                sum = (sum + binpow(2, comps)) % mod;
            }
            clean();
            if(i == (int)e.size()){
                break;
            }
        }
        comps -= unite(e[i].second.first, e[i].second.second);
    }
    cout << sum << endl;



    return 0;
}