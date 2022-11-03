#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n;
vector<pll> g[201005];
vector<char> mkd;
vector<ll> cyc;
vector<ll> hei;
vector<ll> w;
vector<ll> preffar, prefdiam, prefsth, sufffar, suffdiam, suffsth;
ll one = -1, two = -1;

ll dfs1(ll v, ll p){
    ll cycle = -1;
    for(auto pr: g[v]){
        ll u = pr.first;
        ll l = pr.second;
        if(u == p){
            continue;
        }
        if(mkd[u]){
            if(mkd[u] == 1) {
                cycle = u;
                cyc.push_back(v);
            }
        }else{
            mkd[u] = 1;
            ll tmp = dfs1(u, v);
            if(tmp > -1){
                cyc.push_back(v);
                if(tmp == v){
                    cycle = -1;
                }else{
                    cycle = tmp;
                }
            }
        }
    }
    mkd[v] = 2;
    return cycle;
}

ll dfs2(ll v, ll h0) {
    ll h = max(0LL, h0);
    for(auto pr: g[v]){
        ll u = pr.first;
        ll l = pr.second;
        if(h0 < 0 && mkd[u] && -u - 1 == h0){
            w.push_back(l);
        }
        if(mkd[u]){
            continue;
        }
        mkd[u] = 1;
        if(h0 < 0){
            h = max(h, dfs2(u, l));
        }else {
            h = max(h, dfs2(u, h0 + l));
        }
    }
    return h;
}

pll dfs3(ll v){
    pll ans = {v, 0};
    for(auto pr: g[v]){
        ll u = pr.first;
        ll l = pr.second;
        if(mkd[u] || (one * two == v * u && one + two == v + u)){
            continue;
        }
        mkd[u] = 1;
        pll x = dfs3(u);
        if(ans.second < l + x.second){
            ans = {x.first, l + x.second};
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    ll u, v, l;
    for(int i = 0; i < n; ++i){
        cin >> u >> v >> l;
        --u;
        --v;
        g[u].push_back({v, l});
        g[v].push_back({u, l});
    }
    mkd.resize(n, 0);
    mkd[0] = 1;
    dfs1(0, -1);
    int c = cyc.size();
    mkd.clear();
    mkd.resize(n, 0);
    hei.resize(c);
    for(int i = 0; i < c; ++i){
        mkd[cyc[i]] = 1;
    }
    for(int i = 0; i < c; ++i){
        hei[i] = dfs2(cyc[i], -1 - cyc[(i + 1) % c]);
    }
    preffar.resize(c, 0);
    prefdiam.resize(c, 0);
    prefsth.resize(c, 0);
    sufffar.resize(c, 0);
    suffdiam.resize(c, 0);
    suffsth.resize(c, 0);
    preffar[0] = hei[0];
    prefdiam[0] = 0;
    prefsth[0] = hei[0];
    ll cur = 0;
    for(int i = 1; i < c; ++i){
        cur += w[i - 1];
        preffar[i] = max(preffar[i - 1], hei[i] + cur);
        prefsth[i] = max(prefsth[i - 1] + w[i - 1], hei[i]);
        prefdiam[i] = max(prefdiam[i - 1], hei[i] + w[i - 1] + prefsth[i - 1]);
    }
    sufffar[c - 1] = hei[c - 1];
    suffdiam[c - 1] = 0;
    suffsth[c - 1] = hei[c - 1];
    cur = 0;
    for(int i = c - 2; i >= 0; --i){
        cur += w[i];
        sufffar[i] = max(sufffar[i + 1], hei[i] + cur);
        suffsth[i] = max(suffsth[i + 1] + w[i], hei[i]);
        suffdiam[i] = max(suffdiam[i + 1], hei[i] + w[i] + suffsth[i + 1]);
    }
    for(int i = 0; i < c; ++i){
        sufffar[i] += w[c - 1];
    }
    ll idx = c - 1;
    ll val = prefdiam[c - 1];
    for(int i = 0; i < c - 1; ++i){
        ll tmp = max(preffar[i] + sufffar[i + 1], max(prefdiam[i], suffdiam[i + 1]));
        if(tmp < val){
            idx = i;
            val = tmp;
        }
    }
    one = cyc[idx];
    two = cyc[(idx + 1) % c];
    mkd.clear();
    mkd.resize(n, 0);
    mkd[0] = 1;
    auto p1 = dfs3(0);
    mkd.clear();
    mkd.resize(n, 0);
    mkd[p1.first] = 1;
    auto p2 = dfs3(p1.first);
    cout << p2.second << endl;
    return 0;
}