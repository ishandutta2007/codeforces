#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const int MOD = 1000000007;

int n, root, ofs = 1 << 17, sol, tot = 1;
int ll[MAXN], rr[MAXN], len[MAXN], inv[MAXN];
int cen[MAXN], par[MAXN], siz[MAXN], dub[MAXN];
int fen[4][MAXN];
vector <int> v[MAXN];

inline int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
inline int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
inline int mul (int x, int y) {return (llint) x * y % MOD;}

int pot (int a, int e) {
    int res = 1;
    while (e > 0) {
        if (e & 1) res = mul(res, a);
        a = mul(a, a);
        e /= 2;
    }
    return res;
}

void fen_update (int tip, int x, int k) {
    for (; x < MAXN; x += x&-x) fen[tip][x] = add(fen[tip][x], k);
}

int fen_upit (int tip, int x) {
    int res = 0;
    for (; x > 0; x -= x&-x) res = add(res, fen[tip][x]);
    return res;
}

void update (int tip, int from, int to, int dif) {
    fen_update(tip, from, dif);
    fen_update(tip, to + 1, sub(0, dif));
    fen_update(tip + 2, from, mul(dif, from - 1));
    fen_update(tip + 2, to + 1, mul(sub(0, dif), to));
}

int pref (int tip, int ind) {
    return sub(mul(fen_upit(tip, ind), ind), fen_upit(tip + 2, ind));
}

int upit (int tip, int from, int to) {
    return sub(pref(tip, to), pref(tip, from - 1));
}

void dfs (int x, int rod) {
    par[x] = rod;
    siz[x] = 1;
    for (auto sus : v[x]) {
        if (sus == rod || cen[sus]) continue;
        dfs(sus, x);
        siz[x] += siz[sus];
    }
}

int nadi_centroid (int x) {
    int mx = 0, ch = -1;
    for (auto sus : v[x]) {
        if (sus == par[x] || cen[sus]) continue;
        if (siz[sus] > mx) {
            mx = siz[sus];
            ch = sus;
        }
    }
    if (mx * 2 <= siz[root]) return x;
    return nadi_centroid(ch);
}

void obradi (int x, int rod, int flg) {
    dub[x] = dub[rod] + 1;
    if (flg == 0) {
        int cnt = upit(0, ll[x], rr[x]);
        int dist = upit(1, ll[x], rr[x]);
        sol = add(sol, mul(add(mul(cnt, dub[x]), dist), inv[x]));
    } else {
        update(0, ll[x], rr[x], mul(flg, inv[x]));
        update(1, ll[x], rr[x], mul(flg, mul(dub[x], inv[x])));
    }
    for (auto sus : v[x]) {
        if (sus == rod || cen[sus]) continue;
        obradi(sus, x, flg);
    }
}

void decompose (int x) {
    root = x;
    dfs(root, 0);
    int c = nadi_centroid(root);
    cen[c] = 1; dub[c] = 0;
    update(0, ll[c], rr[c], inv[c]);
    for (auto sus : v[c]) {
        if (cen[sus]) continue;
        obradi(sus, c, 0);
        obradi(sus, c, 1);
    }
    for (auto sus : v[c]) {
        if (cen[sus]) continue;
        obradi(sus, c, MOD - 1);
    }
    update(0, ll[c], rr[c], sub(0, inv[c]));
    for (auto sus : v[c]) {
        if (cen[sus]) continue;
        decompose(sus);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ll[i] >> rr[i];
        len[i] = (rr[i] - ll[i] + 1);
        inv[i] = pot(len[i], MOD - 2);
        tot = mul(tot, len[i]);
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    decompose(1);
    cout << mul(sol, tot);
    return 0;
}