#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct rect {
    int xl, yl, xr, yr;
    int z;
    int id;
    bool operator<(const rect& other) const {
        return z < other.z;
    }
};

struct pt {
    int x, y;
    int id;
    bool operator<(const pt& other) const {
        return x < other.x;
    }
};

vector<vector<vector<int> > > t;
vector<vector<int> > ys;
vector<int> xs;
vector<vector<int> > ptr;
vector<pt> p;

void build(int vx, int vy, int tl, int tr, const vector<int>& id) {
    for (int i = 0; i < sz(id); ++i) {
        t[vx][vy].pb(id[i]);
    }
    if (tl == tr) {
        return;
    }
    int tm = (tl + tr) >> 1;
    vector<int> lf, rg;
    for (int i = 0; i < sz(id); ++i) {
        if (p[id[i]].y <= ys[vx][tm]) {
            lf.pb(id[i]);
        } else {
            rg.pb(id[i]);
        }
    }
    build(vx, vy * 2, tl, tm, lf);
    build(vx, vy * 2 + 1, tm + 1, tr, rg);
}

void build(int v, int tl, int tr, const vector<int>& id) {
    for (int i = 0; i < sz(id); ++i) {
        ys[v].pb(p[id[i]].y);
    }
    sort(all(ys[v]));
    ys[v].resize(unique(all(ys[v])) - ys[v].begin());
    t[v].resize(4 * sz(ys[v]));
    ptr[v].assign(4 * sz(ys[v]), 0);
    build(v, 1, 0, sz(ys[v]) - 1, id);
    if (tl == tr) {
        return;
    }
    int tm = (tl + tr) >> 1;
    vector<int> lf, rg;
    for (int i = 0; i < sz(id); ++i) {
        if (p[id[i]].x <= xs[tm]) {
            lf.pb(id[i]);
        } else {
            rg.pb(id[i]);
        }
    }
    build(v * 2, tl, tm, lf);
    build(v * 2 + 1, tm + 1, tr, rg);
}

void upd(int& x, int y) {
    if (y == -1) {
        return;
    }
    if (x == -1) {
        x = y;
    } else {
        x = min(x, y);
    }
}

vector<bool> alive;

int getY(int vx, int vy, int tl, int tr, int l, int r) {
    if (l > r) {
        return -1;
    }
    if (tl == l && tr == r) {
        while (ptr[vx][vy] < sz(t[vx][vy]) && !alive[t[vx][vy][ptr[vx][vy]]]) {
            ++ptr[vx][vy];
        }
        if (ptr[vx][vy] == sz(t[vx][vy])) {
            return -1;
        }
        return t[vx][vy][ptr[vx][vy]];
    }
    int ans = -1;
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        int val = getY(vx, vy * 2, tl, tm, l, min(r, tm));
        upd(ans, val);
    }
    if (r > tm) {
        int val = getY(vx, vy * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        upd(ans, val);
    }
    return ans;
}

int getX(int v, int tl, int tr, int xl, int xr, int yl, int yr) {
    if (xl > xr) {
        return -1;
    }
    if (tl == xl && tr == xr) {
        yl = lower_bound(all(ys[v]), yl) - ys[v].begin();
        yr = upper_bound(all(ys[v]), yr) - ys[v].begin() - 1;
        //cout << "!" << v << " " << sz(ys[v]) << " " << yl << " " << yr << endl;
        return getY(v, 1, 0, sz(ys[v]) - 1, yl, yr);
    }
    int tm = (tl + tr) >> 1;
    int ans = -1;
    if (xl <= tm) {
        int val = getX(v * 2, tl, tm, xl, min(xr, tm), yl, yr);
        upd(ans, val);
    }
    if (xr > tm) {
        int val = getX(v * 2 + 1, tm + 1, tr, max(xl, tm + 1), xr, yl, yr);
        upd(ans, val);
    }
    return ans;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    vector<rect> rects(q);
    for (int i = 0; i < q; ++i) {
        cin >> rects[i].xl >> rects[i].xr >> rects[i].yl >> rects[i].yr >> rects[i].z;
        rects[i].id = i;
    }
    sort(all(rects));

    int n;
    cin >> n;
    p.resize(n);
    vector<int> id;
    for (int i = 0; i < n; ++i) {
        id.pb(i);
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
        xs.pb(p[i].x);
    }

    sort(all(xs));
    xs.resize(unique(all(xs)) - xs.begin());
    t.resize(4 * sz(xs));
    ptr.resize(4 * sz(xs));
    ys.resize(4 * sz(xs));
    alive.assign(n, true);

    build(1, 0, sz(xs) - 1, id);

    vector<int> ans(n, -1);
    for (int i = 0; i < q; ++i) {
        int xl = rects[i].xl, xr = rects[i].xr;
        int yl = rects[i].yl, yr = rects[i].yr;
        xl = lower_bound(all(xs), xl) - xs.begin();
        xr = upper_bound(all(xs), xr) - xs.begin() - 1;
        int g = getX(1, 0, sz(xs) - 1, xl, xr, yl, yr);
        if (g != -1) {
            ans[g] = rects[i].id;
            alive[g] = false;
        }

    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << "\n";
    }

}