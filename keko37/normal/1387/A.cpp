#include<bits/stdc++.h>

using namespace std;

typedef pair <int, int> pi;
typedef long double ld;

const int MAXN = 200005;

int n, m, ok = 1;
int a[MAXN], b[MAXN], c[MAXN];
int val[MAXN], bio[MAXN], sign[MAXN];
ld sol[MAXN];
vector <pi> v[MAXN];
vector <int> e, nodes, comp;
set <ld> st;

void obradi (int x, int tip) {
    bio[x] = 1;
    sign[x] = tip;
    if (sign[x] == 1) nodes.push_back(val[x]); else nodes.push_back(-val[x]);
    comp.push_back(x);
    for (auto par : v[x]) {
        int sus = par.first, ind = par.second;
        if (bio[sus] == 0) {
            val[sus] = c[ind] - val[x];
            obradi(sus, !tip);
        } else {
            e.push_back(ind);
        }
    }
}

void solve (int x) {
    e.clear(); nodes.clear(); comp.clear(); st.clear();
    obradi(x, 0);

    bool moze = 1;
    for (auto i : e) {
        if (sign[a[i]] != sign[b[i]]) {
            if (val[a[i]] + val[b[i]] != c[i]) moze = 0;
        } else {
            ld res = ((ld) c[i] - (val[a[i]] + val[b[i]])) / 2;
            if (sign[a[i]] == 1) res = -res;
            st.insert(res);
        }
    }

    if (moze == 0 || st.size() >= 2) {
        ok = 0;
        return;
    }
    ld res;
    if (st.size() == 1) {
        res = *st.begin();
    } else {
        sort(nodes.begin(), nodes.end());
        res = nodes[nodes.size() / 2];
    }
    for (auto i : comp) {
        if (sign[i] == 0) sol[i] = val[i] + res; else sol[i] = val[i] - res;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        v[a[i]].push_back({b[i], i});
        v[b[i]].push_back({a[i], i});
    }
    for (int i = 1; i <= n; i++) {
        if (bio[i] == 0) solve(i);
    }
    if (ok == 1) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << sol[i] << " ";
        }
    } else {
        cout << "NO";
    }
    return 0;
}