#include<bits/stdc++.h>

using namespace std;

const int MAXN = 400005 * 5;

int n, p, M, m, cnt, ofs = 1, col, moze = 1;
int lef[MAXN], rig[MAXN];
vector <int> v[MAXN], g[MAXN], st, t, out;
vector <pair <int, int> > r;
int bio[MAXN], comp[MAXN], sol[MAXN], s[MAXN];

pair <int, int> build (int low, int high) {
    if (p <= low) return {0, 0};
    if (low == high) return {r[low].second, r[low].second + ofs};
    int curr = ++cnt;
    pair <int, int> p1 = build(low, (low + high) / 2);
    pair <int, int> p2 = build((low + high) / 2 + 1, high);
    if (p1.first != 0) {
        //cout << "edge " << curr + p << " " << p1.second << endl;
        v[p1.first].push_back(curr);
        v[curr + ofs].push_back(p1.second);
    }
    if (p2.first != 0) {
        //cout << "edge " << curr + p << " " << p2.second << endl;
        v[p2.first].push_back(curr);
        v[curr + ofs].push_back(p2.second);
    }
    return {curr, curr + ofs};
}

void upit (int x, int from, int to, int low, int high, int ind) {
    //cout << "upit " << x << " " << from << " " << to << "  " << low << " " << high << "  " << ind << " " << v[x + p].size() << endl;
    if (from <= low && high <= to) {
        v[x].push_back(ind + ofs);
        v[ind].push_back(x + ofs);
        return;
    }
    if (to < low || high < from) return;
    upit(v[x + ofs][0] - ofs, from, to, low, (low + high)/2, ind);
    if (v[x + ofs].size() >= 2) upit(v[x + ofs][1] - ofs, from, to, (low + high)/2 + 1, high, ind);
}

void dfs1 (int x) {
    if (bio[x]) return;
    bio[x] = 1;
    for (auto sus : v[x]) {
        dfs1(sus);
    }
    st.push_back(x);
}

void dfs2 (int x) {
    comp[x] = col;
    for (auto sus : g[x]) {
        if (comp[sus] == 0) dfs2(sus);
    }
}

void ispis () {
    for (int i=1; i<=p; i++) {
        if (sol[i]) {
            s[lef[i]]++;
            s[rig[i] + 1]--;
            out.push_back(i);
        }
    }
    int f = -1;
    for (int i=1; i<=M; i++) {
        s[i] += s[i-1];
        if (s[i] == out.size()) f = i;
    }
    cout << out.size() << " " << f << endl;
    for (auto x : out) cout << x << " ";
}

void dva_sat () {
    for (int i=1; i<=p; i++) {
        t.push_back(i);
        t.push_back(i + ofs);
    }
    for (int i = p + ofs + 1; i <= cnt; i++) {
        t.push_back(i);
        t.push_back(i + ofs);
    }
    for (auto x : t) {
        if (!bio[x]) dfs1(x);
    }
    for (auto x : t) {
        for (auto sus : v[x]) {
            g[sus].push_back(x);
        }
    }
    reverse(st.begin(), st.end());
    for (auto x : st) {
        if (comp[x] == 0) {
            col++;
            dfs2(x);
        }
    }
    for (int i=1; i<=p; i++) {
        if (comp[i] == comp[i + ofs]) {
            moze = 0;
            break;
        }
        sol[i] = (comp[i] > comp[i + ofs]);
    }
}

int main () {
    cin >> n >> p >> M >> m;
    while (ofs < p) ofs *= 2;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        v[x + ofs].push_back(y);
        v[y + ofs].push_back(x);
    }
    for (int i=1; i<=p; i++) {
        cin >> lef[i] >> rig[i];
        r.push_back({rig[i], i});
    }
    sort(r.begin(), r.end());
    cnt = p + ofs;
    build(0, ofs - 1);
    for (auto par : r) {
        int ind = par.second;
        int pos = lower_bound(r.begin(), r.end(), make_pair(lef[ind], 0)) - r.begin() - 1;
        if (pos < 0) continue;
        upit(p + ofs + 1, 0, pos, 0, ofs-1, ind);
    }
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y + ofs);
        v[y].push_back(x + ofs);
    }
    dva_sat();
    if (!moze) {
        cout << -1;
        return 0;
    }
    ispis();
    return 0;
}