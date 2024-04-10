#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;
typedef vector <int> vi;

const int MAXN = 300005;
const int LOG = 19;

llint n, q, sol;
int U[MAXN], V[MAXN];
int cen[MAXN], par[MAXN][LOG], dub[MAXN], siz[MAXN], dp[MAXN];
vector <int> v[MAXN], add[MAXN], sub[MAXN], nodes, r;

int cnt;
int bio[MAXN];

void ubaci (int x) {
    bio[x]++;
    if (bio[x] == 1) cnt++;
}

void izbaci (int x) {
    bio[x]--;
    if (bio[x] == 0) cnt--;
}

void dfs (int x, int rod, bool flg) {
    par[x][0] = rod;
    dub[x] = 1 + dub[rod];
    siz[x] = 1;
    if (flg) {
        nodes.push_back(x);
        for (auto e : add[x]) r.push_back(e);
    }
    for (auto sus : v[x]) {
        if (sus == rod || cen[sus]) continue;
        dfs(sus, x, flg);
        siz[x] += siz[sus];
    }
}

int nadi_cen (int x, int root) {
    int mx = 0, ind = -1;
    for (auto sus : v[x]) {
        if (sus == par[x][0] || cen[sus]) continue;
        if (siz[sus] > mx) {
            mx = siz[sus];
            ind = sus;
        }
    }
    if (mx * 2 <= siz[root]) return x;
    return nadi_cen(ind, root);
}

void precompute_lca () {
    for (int i = 1; i < LOG; i++) {
        for (auto x : nodes) {
            par[x][i] = par[par[x][i - 1]][i - 1];
        }
    }
}

int kth (int x, int k) {
    int pot = 0;
    while (k > 0) {
        if (k & 1) x = par[x][pot];
        k /= 2;
        pot++;
    }
    return x;
}

pair <int, pi> lca (int a, int b) {
    if (a == b) return {a, {-1, -1}};
    if (dub[a] < dub[b]) swap(a, b);
    if (dub[a] != dub[b]) {
        a = kth(a, dub[a] - dub[b] - 1);
        if (par[a][0] == b) return {b, {a, -1}};
        a = par[a][0];
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return {par[a][0], {a, b}};
}

void calc (int x) {
    for (auto e : add[x]) ubaci(e);
    for (auto e : sub[x]) izbaci(e);
    dp[x] = cnt;
    for (auto sus : v[x]) {
        if (sus == par[x][0] || cen[sus]) continue;
        calc(sus);
    }
    for (auto e : add[x]) izbaci(e);
    for (auto e : sub[x]) ubaci(e);
}

void decompose (int x) {
    dfs(x, 0, 0);
    x = nadi_cen(x, x);
    nodes.clear(); r.clear();
    dfs(x, 0, 1);
    precompute_lca();
    for (auto x : nodes) add[x].clear(), sub[x].clear();

    vector <pi> curr;
    vector <int> p;
    for (auto e : r) {
        pair <int, pi> res = lca(U[e], V[e]);
        int d = res.first, a = res.second.first, b = res.second.second;
        if (a > b) swap(a, b);
        if (d != x) {
            add[d].push_back(e);
            if (a != -1) sub[a].push_back(e);
            if (b != -1) sub[b].push_back(e);
        } else {
            if (a != -1) ubaci(a);
            if (b != -1) ubaci(b);
            curr.push_back({a, b});
            p.push_back(e);
        }
    }

    sort(curr.begin(), curr.end());
    for (int i = 0; i < curr.size(); i++) {
        int j = i;
        while (j < curr.size() && curr[j] == curr[i]) j++;
        int a = curr[i].first, b = curr[i].second;
        int val = curr.size();
        if (a != -1) val -= bio[a];
        if (b != -1) val -= bio[b];
        if (a != -1 && b != -1) val += j - i;
        if (a == -1 && b == -1) val--;
        sol += (llint) val * (j - i);
        i = j - 1;
    }
    cnt = 0;
    for (auto pp : curr) {
        if (pp.first != -1) bio[pp.first] = 0;
        if (pp.second != -1) bio[pp.second] = 0;
    }

    calc(x);
    for (auto e : p) {
        sol += 2 * (dp[U[e]] + dp[V[e]]);
    }

    cen[x] = 1;
    for (auto sus : v[x]) {
        if (cen[sus]) continue;
        decompose(sus);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> U[i] >> V[i];
        add[1].push_back(i);
    }
    decompose(1);
    cout << sol / 2;
    return 0;
}