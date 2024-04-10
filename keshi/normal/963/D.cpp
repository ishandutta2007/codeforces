//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 67867967;
const ll md = 32452843;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, k[maxn], ans[maxn];
long long h[maxn], hs[maxn], p[maxn];
string s, st[maxn];
vector<int> g[maxn], vec[maxn];
int mp[mod];

ll get(ll l, ll r){
    ll x = h[r] - (h[l] * p[r - l] % mod);
    if(x < 0) x += mod;
    return x;
}

int main(){
    fast_io;

    p[0] = 1;
    for(ll i = 1; i < maxn; i++){
        p[i] = (p[i - 1] * 31) % mod;
    }

    cin >> s;
    n = s.size();
    s = ' ' + s;

    for(ll i = 1; i <= n; i++){
        h[i] = (h[i - 1] * 31 + (s[i] - 'a')) % mod;
    }
    cin >> m;
    for(ll i = 1; i <= m; i++){
        cin >> k[i] >> st[i];
        ans[i] = inf;
        vec[i].reserve(10);
        if((ll)st[i].size() + k[i] - 1 <= n) g[(ll)st[i].size()].pb(i);
        for(ll j = 0; j < (ll)st[i].size(); j++){
            hs[i] = (hs[i] * 31 + (st[i][j] - 'a')) % mod;
        }
    }
    for(ll i = 1; i <= n; i++){
        if(g[i].empty()) continue;
        for(ll j = 0; j < (ll)g[i].size(); j++){
            mp[hs[g[i][j]]] = g[i][j];
        }
        for(ll j = 1; j + i - 1 <= n; j++){
            ll x = mp[get(j - 1, j + i - 1)];
            if(x) vec[x].pb(j);
        }
        for(ll o : g[i]){
            for(ll j = 0; j + k[o] - 1 < (ll)vec[o].size(); j++){
                ans[o] = min(ans[o], vec[o][j + k[o] - 1] - vec[o][j] + (ll)st[o].size());
            }
            vec[o].clear();
            vec[o].resize(0);
            vec[o].shrink_to_fit();
        }
        for(ll j = 0; j < (ll)g[i].size(); j++){
            mp[hs[g[i][j]]] = 0;
        }
    }
    for(ll i = 1; i <= m; i++){
        if(ans[i] == inf) ans[i] = -1;
        cout << ans[i] << '\n';
    }

    return 0;
}