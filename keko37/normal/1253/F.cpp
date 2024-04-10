#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const llint INF = 1000000000000000000;

int n, m, k, q;
int qa[MAXN * 3], qb[MAXN * 3], ok[MAXN * 3];
llint sol[MAXN * 3];
int best[MAXN], par[MAXN];
llint dist[MAXN];
set < pair <llint, int> > dst;
vector <int> comp[MAXN], upit[MAXN];
vector < pair <int, int> > v[MAXN];

int nadi (int x) {
    if (x == par[x]) return x;
    return par[x] = nadi(par[x]);
}

void precalc () {
    for (int i = 1; i <= k; i++) {
        par[i] = i;
        comp[i].push_back(i);
    }
    for (int i = 0; i < q; i++) {
        upit[qa[i]].push_back(i);
        upit[qb[i]].push_back(i);
    }
}

void spoji (int a, int b, llint ans) {
    //cout << "bla " << a << " " << b << " " << ans << endl;
    a = nadi(a); b = nadi(b);
    if (a == b) return;
    if (upit[a].size() > upit[b].size()) swap(a, b);
    for (auto i : upit[a]) {
        //cout << "upit " << i << endl;
        if (ok[i]) continue;
        if (nadi(qa[i]) == a && nadi(qb[i]) == b || nadi(qa[i]) == b && nadi(qb[i]) == a) {
            ok[i] = 1;
            sol[i] = ans;
            //cout << "sol " << i << " " << ans << endl;
            continue;
        }
        upit[b].push_back(i);
    }
    if (comp[a].size() < comp[b].size()) {
        for (auto x : comp[a]) {
            comp[b].push_back(x);
        }
        par[a] = b;
    } else {
        for (auto x : comp[b]) {
            comp[a].push_back(x);
        }
        par[b] = a;
        swap(upit[a], upit[b]);
    }
}

void dijkstra () {
    //cout << "dijkstra" << endl;
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    for (int i = 1; i <= k; i++) {
        dist[i] = 0;
        dst.insert({0, i});
        best[i] = i;
    }
    while (!dst.empty()) {
        int x = dst.begin() -> second;
        dst.erase(dst.begin());
        for (auto pp : v[x]) {
            int sus = pp.first, d = pp.second;
            llint val = dist[x] + d;
            if (val < dist[sus]) {
                if (dst.find({dist[sus], sus}) != dst.end()) dst.erase({dist[sus], sus});
                dist[sus] = val;
                dst.insert({dist[sus], sus});
                best[sus] = best[x];
            }
        }
    }
    vector < pair <llint, pair <int, int> > > tmp;
    for (int i = 1; i <= n; i++) {
        //cout << "bla " << i << " " << dist[i] << " " << best[i] << endl;
        for (auto pp : v[i]) {
            int sus = pp.first, d = pp.second;
            if (best[sus] != best[i]) {
                llint val = dist[i] + dist[sus] + d;
                tmp.push_back({val, {best[i], best[sus]}});
            }
        }
    }
    sort(tmp.begin(), tmp.end());
    for (auto pp : tmp) {
        llint val = pp.first;
        int a = pp.second.first, b = pp.second.second;
        spoji(a, b, val);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> q;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 0; i < q; i++) {
        cin >> qa[i] >> qb[i];
    }
    precalc();
    dijkstra();
    for (int i = 0; i < q; i++) {
        cout << sol[i] << '\n';
    }
    return 0;
}