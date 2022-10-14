#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

typedef long long llint;

int n, ofs = 1;
int x[MAXN], y[MAXN], c[MAXN];
pair <int, int> p;
vector <int> v, u[MAXN];

struct node {
    llint mx, ind, prop;
    node () {}
    node (llint _mx, llint _ind) {
        mx = _mx; ind = _ind;
    }
} t[MAXN * 4];

node spoji (node a, node b) {
    if (a.mx >= b.mx) return a; return b;
}

void propagate (int x) {
    if (t[x].prop == 0) return;
    if (x < ofs) {
        t[2*x].prop += t[x].prop;
        t[2*x+1].prop += t[x].prop;
    }
    t[x].mx += t[x].prop;
    t[x].prop = 0;
}

void update (int x, int from, int to, int low, int high, llint val) {
    propagate(x);
    if (from <= low && high <= to) {
        t[x].prop = val;
        propagate(x);
        return;
    }
    if (to < low || high < from) return;
    update(2*x, from, to, low, (low + high) / 2, val);
    update(2*x + 1, from, to, (low + high) / 2 + 1, high, val);
    t[x] = spoji(t[2*x], t[2*x+1]);
}

node upit (int x, int from, int to, int low, int high) {
    propagate(x);
    if (from <= low && high <= to) return t[x];
    if (to < low || high < from) return node(-1, -1);
    return spoji(upit(2*x, from, to, low, (low + high) / 2), upit(2*x + 1, from, to, (low + high) / 2 + 1, high));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i] >> c[i];
        if (x[i] > y[i]) swap(x[i], y[i]);
        v.push_back(x[i]);
        v.push_back(y[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i=0; i<n; i++) {
        x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
        y[i] = lower_bound(v.begin(), v.end(), y[i]) - v.begin();
        u[y[i]].push_back(i);
    }
    while (ofs < v.size()) ofs *= 2;
    for (int i=0; i<ofs; i++) {
        t[ofs + i].ind = i;
    }
    for (int i=ofs-1; i>0; i--) {
        t[i].ind = t[i*2].ind;
    }
    llint sol = 0, ll = v.size(), rr = v.size();
    for (int i=0; i<v.size(); i++) {
        update(1, i, i, 0, ofs-1, v[i]);
        for (auto r : u[i]) {
            update(1, 0, x[r], 0, ofs-1, c[r]);
        }
        node par = upit(1, 0, i, 0, ofs-1);
        llint val = par.mx - v[i], ind = par.ind;
        if (val > sol) {
            sol = val;
            ll = v[ind];
            rr = v[i];
        }
    }
    cout << sol << endl << ll << " " << ll << " " << rr << " " << rr;
    return 0;
}