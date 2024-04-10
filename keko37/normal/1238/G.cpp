#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 500005;
const int INF = 1000000007;

llint q, n, m, c, c0, ofs;
llint t[MAXN], ost[MAXN], p[MAXN], r[MAXN];
llint tr[MAXN * 4], prop[MAXN * 4];
set < pair <llint, int> > st;
vector < pair <int, pair <int, int> > > v;
vector <int> saz;

void propagate (int x) {
    if (prop[x] == 0) return;
    if (x < ofs) {
        prop[2*x] += prop[x];
        prop[2*x+1] += prop[x];
    }
    tr[x] += prop[x];
    prop[x] = 0;
}

void update (int x, int from, int to, int lo, int hi, llint val) {
    propagate(x);
    if (from <= lo && hi <= to) {
        prop[x] += val;
        propagate(x);
        return;
    }
    if (to < lo || hi < from) return;
    update(2*x, from, to, lo, (lo + hi) / 2, val);
    update(2*x+1, from, to, (lo + hi) / 2 + 1, hi, val);
    tr[x] = max(tr[2*x], tr[2*x+1]);
}

llint upit (int x, int from, int to, int lo, int hi) {
    propagate(x);
    if (from <= lo && hi <= to) return tr[x];
    if (to < lo || hi < from) return -INF;
    return max(upit(2*x, from, to, lo, (lo + hi) / 2), upit(2*x+1, from, to, (lo + hi) / 2 + 1, hi));
}

void init () {
    st.clear(); v.clear(); saz.clear();
    for (int i = 0; i <= n + 1; i++) {
        t[i] = ost[i] = p[i] = r[i] = 0;
    }
}

void t_init () {
    ofs = 1;
    while (ofs < saz.size()) ofs *= 2;
    for (int i=0; i<2*ofs; i++) {
        prop[i] = 0;
        tr[i] = -INF;
    }
    for (int i = 0; i < saz.size(); i++) {
        tr[i + ofs] = c0 - saz[i];
    }
    for (int i = ofs - 1; i > 0; i--) {
        tr[i] = max(tr[2*i], tr[2*i+1]);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n >> m >> c >> c0;
        init();

        for (int i=1; i<=n; i++) {
            int t, ost, p;
            cin >> t >> ost >> p;
            saz.push_back(t);
            v.push_back({t, {ost, p}});
        }

        sort(saz.begin(), saz.end());
        saz.erase(unique(saz.begin(), saz.end()), saz.end());
        sort(v.begin(), v.end());
        for (int i=0; i<v.size(); i++) {
            t[i + 1] = v[i].first;
            ost[i + 1] = v[i].second.first;
            p[i + 1] = v[i].second.second;
            r[i + 1] = lower_bound(saz.begin(), saz.end(), t[i + 1]) - saz.begin();
        }
        t[n + 1] = m;
        t_init();

        llint pos = c0, curr = 1, sol = 0;
        while (curr <= n + 1) {
            if (t[curr] <= pos) {
                st.insert({p[curr], curr});
                curr++;
                continue;
            }
            if (st.empty()) break;
            int ind = st.begin() -> second;
            llint d = t[curr] - pos, cap = c - upit(1, r[ind], ofs - 1, 0, ofs - 1);
            llint val = min(ost[ind], min(d, cap));
            update(1, r[ind], ofs - 1, 0, ofs - 1, val);
            ost[ind] -= val;
            sol += p[ind] * val;
            pos += val;
            if (ost[ind] == 0 || val == cap) st.erase({p[ind], ind});
        }
        if (curr == n + 2) cout << sol << '\n'; else cout << -1 << '\n';
    }
    return 0;
}