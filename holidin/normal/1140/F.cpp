#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 6e6 + 1;
const int MXN = 3e5;

map <pair<int, int>, int> m;
map <pair<int, int>, bool> st;
long long pos[N], cntx[N], cnty[N], t[N], ans[N], n, top = 0, v;
vector <pair<int, int> > dv[N];
long long cnt = 0;

void add(int v, int vl, int vr, int l, int r, int x, int y) {
    if (l <= vl && vr <= r)
        dv[v].push_back({x, y});
    else if (l >= vr || vl >= r)
            return;
        else {
            add(2*v + 1, vl, (vl + vr) / 2, l, r, x, y);
            add(2*v + 2, (vl + vr) / 2, vr, l, r, x, y);
        }
}

int get(int u) {
    if (t[u] != u)
        return get(t[u]);
    else
        return u;
}

void uni(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b)
        return;
    if (cntx[b] + cnty[b] > cntx[a] + cnty[a])
        swap(a, b);
    ++top;
    pos[top] = b;
    cnt -= cntx[b] * cnty[b] + cntx[a] * cnty[a];
    cntx[a] += cntx[b];
    cnty[a] += cnty[b];
    cnt += cntx[a] * cnty[a];
    t[b] = a;
    return;
}

void dfs(int v, int vl, int vr) {
    if (vl > n)
        return;
    int base = top;
    for (int i = 0; i < dv[v].size(); ++i) {
        uni(dv[v][i].fi, dv[v][i].se);
    }
    if (vr - vl == 1)
        ans[vl] = cnt;
    else {
        dfs(2 * v + 1, vl, (vl + vr) / 2);
        dfs(2 * v + 2, (vl + vr) / 2, vr);
    }
    while (top > base) {
        int a = t[pos[top]], b = pos[top];
        cnt -= cntx[a] * cnty[a];
        cntx[a] -= cntx[b];
        cnty[a] -= cnty[b];
        cnt += cntx[a] * cnty[a] + cntx[b] * cnty[b];
        t[b] = b;
        --top;
    }
}

int main() {
    int i, j, k, x, y;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    v = 1;
    while (v < n)
        v *= 2;
    for (i = 1; i <= n; ++i) {
        cin >> x >> y;
        if (st[{x, y}] == 1) {
            add(0, 1, v + 1, m[{x, y}], i, x, y + MXN);
        }
        st[{x, y}] = !st[{x, y}];
        m[{x, y}] = i;
    }
    for (map <pair<int, int> , int> :: iterator it = m.begin(); it != m.end(); ++it)
    if (st[(*it).fi])
        add(0, 1, v + 1, (*it).se, n + 1, (*it).fi.fi, (*it).fi.se + MXN);
    for (i = 1; i <= 2 * MXN; ++i) {
        t[i] = i;
        if (i <= MXN)
            cntx[i] = 1;
        else
            cnty[i] = 1;
    }
    dfs(0, 1, v + 1);
    for (i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}