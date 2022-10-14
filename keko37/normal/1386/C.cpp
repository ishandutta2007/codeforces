#include<bits/stdc++.h>

using namespace std;

typedef pair <int, int> pi;

const int MAXN = 200005;

int n, m, q, rip, moze = 1;
int a[MAXN], b[MAXN], ans[MAXN];
int par[MAXN], col[MAXN];
vector <int> siz[MAXN];
vector <pi> e;

void dsu_init () {
    rip = 0;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        siz[i].clear();
        siz[i].push_back(1);
    }
}

pi nadi (int x) {
    if (x == par[x]) return {par[x], 0};
    pi res = nadi(par[x]);
    return {res.first, res.second ^ col[x]};
}

void spoji (int a, int b) {
    pi resa = nadi(a), resb = nadi(b);
    a = resa.first, b = resb.first;

    if (a == b) {
        e.push_back({-a, rip});
        rip += resa.second == resb.second;
        return;
    }

    if (siz[a].back() < siz[b].size()) swap(a, b);
    par[b] = a;
    col[b] = resa.second == resb.second;
    siz[a].push_back(siz[a].back() + siz[b].back());
    e.push_back({a, b});
}

void makni () {
    int a = e.back().first, b = e.back().second;
    e.pop_back();
    if (a < 0) {
        rip = b;
        return;
    }
    par[b] = b;
    col[b] = 0;
    siz[a].pop_back();
}

void calc (int lef, int rig, int lo, int hi) {
    if (lef > rig) return;
    int mid = (lef + rig) / 2;

    int poc = e.size();
    for (int i = lef; i < mid; i++) spoji(a[i], b[i]);

    if (rip > 0) {
        ans[mid] = hi;
    } else {
        int prije = e.size();
        for (int i = hi - 1; i >= max(lo, mid); i--) {
            spoji(a[i], b[i]);
            if (rip > 0) {
                ans[mid] = i;
                break;
            }
        }
        while (e.size() > prije) makni();
    }

    spoji(a[mid], b[mid]);
    calc(mid + 1, rig, ans[mid], hi);
    while (e.size() > poc) makni();

    for (int i = hi - 1; i >= ans[mid]; i--) spoji(a[i], b[i]);
    calc(lef, mid - 1, lo, ans[mid]);
    while (e.size() > poc) makni();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    dsu_init();
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        spoji(a[i], b[i]);
    }
    if (rip == 0) {
        moze = 0;
    } else {
        dsu_init();
        calc(1, m, 1, m + 1);
    }
    for (int i = 0; i < q; i++) {
        int lo, hi;
        cin >> lo >> hi;
        if (moze == 0) {
            cout << "NO\n";
        } else {
            if (hi < ans[lo]) cout << "YES\n"; else cout << "NO\n";
        }
    }
    return 0;
}