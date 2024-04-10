#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 150005;
const int MOD = 998244353;

int n, q, cnt = 1, tim = 0, ofs, inv;
int par[MAXN], siz[MAXN], lo[MAXN], hi[MAXN], ch[MAXN], col[MAXN], head[MAXN], fen[MAXN], sol[MAXN];
vector <int> v[MAXN];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int pot (int a, int e) {
    int res = 1;
    while (e > 0) {
        if (e & 1) res = mul(res, a);
        a = mul(a, a);
        e /= 2;
    }
    return res;
}

void dfs (int x, int rod) {
    par[x] = rod;
    siz[x] = 1;
    lo[x] = hi[x] = ++tim;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        dfs(sus, x);
        siz[x] += siz[sus];
        if (siz[sus] > siz[ch[x]]) ch[x] = sus;
        hi[x] = hi[sus];
    }
}

void decompose (int x, bool top) {
    col[x] = cnt;
    if (top) head[cnt] = x;
    if (ch[x] != 0) decompose(ch[x], 0);
    for (auto sus : v[x]) {
        if (sus == ch[x] || sus == par[x]) continue;
        cnt++;
        decompose(sus, 1);
    }
}

void ubaci (int x, int k) {
    for (; x < MAXN; x += x&-x) fen[x] = add(fen[x], k);
}

int upit (int x) {
    int res = 0;
    for (; x > 0; x -= x&-x) res = add(res, fen[x]);
    return res;
}

void update (int x, int d) {
    sol[x] = add(sol[x], d);
    int val = mul(siz[x], d);
    ofs = add(ofs, val);
    ubaci(lo[x], sub(0, val));
    ubaci(hi[x] + 1, val);
    if (ch[x] != 0) {
        val = mul(n - siz[ch[x]], d);
        ubaci(lo[ch[x]], val);
        ubaci(hi[ch[x]] + 1, sub(0, val));
    }
}

int rjesi (int x) {
    int res = add(add(ofs, upit(lo[x])), mul(sol[x], n));
    while (x > 0) {
        x = head[col[x]];
        if (x == 1) break;
        res = add(res, mul(n - siz[x], sol[par[x]]));
        x = par[x];
    }
    return mul(res, inv);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    inv = pot(n, MOD - 2);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    decompose(1, 0);
    for (int i = 0; i < q; i++) {
        int tip; cin >> tip;
        if (tip == 1) {
            int x, d;
            cin >> x >> d;
            update(x, d);
        } else {
            int x; cin >> x;
            cout << rjesi(x) << '\n';
        }
    }
    return 0;
}