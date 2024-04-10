#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int MAXM = 1000005;

int n, m;
int a[MAXM], b[MAXM], w[MAXM];
vector < pair <int, int> > p;
int par[MAXN], lo[MAXM], hi[MAXM], mid[MAXM];
bool treba[MAXM], res[MAXM];
vector <int> in, out;

int nadi (int x) {
    if (par[x] == x) return x;
    return par[x] = nadi(par[x]);
}

bool spoji (int x, int y, bool flg) {
    x = nadi(x); y = nadi(y);
    if (x == y) return 0;
    if (flg) par[y] = x;
    return 1;
}

void prvi_mst () {
    for (int i=1; i<=n; i++) {
        par[i] = i;
    }
    p.clear();
    for (int i=1; i<=m; i++) {
        p.push_back(make_pair(w[i], i));
    }
    sort(p.begin(), p.end());
    for (int i=0; i<p.size(); i++) {
        int ind = p[i].second;
        if (spoji(a[ind], b[ind], 1)) {
            in.push_back(ind);
        } else {
            out.push_back(ind);
        }
    }
}

bool upiti () {
    for (int i=1; i<=n; i++) {
        par[i] = i;
    }
    p.clear();
    for (int i=1; i<=m; i++) {
        p.push_back(make_pair(w[i], i));
    }
    for (auto e : out) {
        p.push_back(make_pair(mid[e], -e));
    }
    sort(p.begin(), p.end());
    for (int i=0; i<p.size(); i++) {
        int ind = p[i].second;
        if (ind > 0) {
            spoji(a[ind], b[ind], 1);
        } else {
            ind = -ind;
            res[ind] = spoji(a[ind], b[ind], 0);
        }
    }
}

int bs () {
    for (auto e : out) {
        lo[e] = 0; hi[e] = w[e] - 1;
    }
    for (int i=0; i<=30; i++) {
        for (auto e : out) {
            mid[e] = (lo[e] + hi[e] + 1) / 2;
        }
        upiti();
        for (auto e : out) {
            if (res[e]) {
                lo[e] = mid[e];
            } else {
                hi[e] = mid[e] - 1;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> a[i] >> b[i] >> w[i];
    }
    prvi_mst();
    for (auto x : out) treba[x] = 1;
    bs();
    for (int i=1; i<=m; i++) {
        if (treba[i]) cout << lo[i] << '\n';
    }
    return 0;
}