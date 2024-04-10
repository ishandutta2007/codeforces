//DFS Tree
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define N 100010

vector<ll> graph[N], backIn[N], backOut[N], tree[N];
ll dep[N], par[N];

void dfs(ll i, ll p) {
    par[i] = p;
    dep[i] = dep[p] + 1;
    for(ll j : graph[i]) if(j - p) {
        if(!dep[j]) {
            tree[i].push_back(j);
            dfs(j, i);
        } else if(dep[j] < dep[i]) {
            backIn[j].push_back(i);
            backOut[i].push_back(j);
        }
    }
}

map<pl, ll> idx;

bool bip(ll i, ll c) {
    dep[i] = c;
    bool bipp = true;
    for(ll j : graph[i])
        if(dep[j] == c) bipp = false;
        else if(!dep[j] && !bip(j, 3 - c)) bipp = false;
    return bipp;
}

vector<pl> bad_backedges;
ll badIn[N], badOut[N];
vector<pl> ans_edges;

pl fill_ansedges(ll i) { //returns back[i]
    ll back = (ll)backOut[i].size() - (ll)backIn[i].size();
    ll badback = badOut[i] - badIn[i];
    for(ll j : tree[i]) {
        pl p = fill_ansedges(j);
        back += p.first;
        badback += p.second;
    }
    if(badback == bad_backedges.size() && back == badback)
        ans_edges.emplace_back(i, par[i]);
    return {back, badback};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 1, m + 1) {
        G(u) G(v)
        graph[u].push_back(v);
        graph[v].push_back(u);
        idx[{u, v}] = idx[{v, u}] = i;
    }
    vector<ll> nonbiproots;
    F(i, 1, n + 1) if(!dep[i] && !bip(i, 1)) nonbiproots.push_back(i);
    if(nonbiproots.empty()) {
        cout << m << '\n';
        F(i, 1, m + 1) cout << i << ' ';
        cout << '\n';
    } else if(nonbiproots.size() > 1) cout << "0\n";
    else {
        ll r = nonbiproots[0];
        fill_n(dep, n + 1, 0);
        dfs(r, r);
        
        F(i, 1, n + 1)
            for(ll j : backOut[i])
                if(dep[i] % 2 == dep[j] % 2) {
                    bad_backedges.emplace_back(i, j);
                    badIn[j]++;
                    badOut[i]++;
                }
        if(bad_backedges.size() == 1)
            ans_edges.push_back(bad_backedges[0]);

        fill_ansedges(r);
        vector<ll> inds;
        for(pl p : ans_edges) inds.push_back(idx[p]);
        sort(inds.begin(), inds.end());
        cout << ans_edges.size() << '\n';
        for(ll i : inds) cout << i << ' ';
        cout << '\n';
    }
}