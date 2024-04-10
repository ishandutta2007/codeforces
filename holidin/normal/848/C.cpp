#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;
vector <long long> m[N];
vector <int> g[N];
int v, x[N], y[N], type[N], a[N], h[N];

int f(int i) {
    return i & (-i);
}

void fenw(int u, int i, int j) {
    while (i < m[u].size()) {
        m[u][i] += j;
        i += f(i);
    }
}

int fa(int u, int i) {
    long long ans = 0;
    while (i > 0) {
        ans += m[u][i];
        i -= f(i);
    }
    return ans;
}

void add_point(int i, int j) {
    i += v - 2;
    g[i].push_back(j);
    while (i > 0) {
        i = (i - 1) / 2;
        g[i].push_back(j);
    }
}

void build_do(int v, int vl, int vr) {
    g[v].push_back(-1);
    sort(g[v].begin(), g[v].end());
    unique(g[v].begin(), g[v].end());
    m[v].resize(g[v].size());
    if (vr - vl > 1) {
        build_do(2*v + 1, vl, (vl + vr) / 2);
        build_do(2*v + 2, (vl + vr) / 2, vr);
    }
}

void add(int u, int pos, int y) {
    int i = u + v - 2, ind;
    ind = lower_bound(g[i].begin(), g[i].end(), pos) - g[i].begin();
    fenw(i, ind, y);
    while (i > 0) {
        i = (i - 1) / 2;
        ind = lower_bound(g[i].begin(), g[i].end(), pos) - g[i].begin();
        fenw(i, ind, y);
    }
}

long long sum(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r) {
        int ind = lower_bound(g[v].begin(), g[v].end(), l) - g[v].begin();
        return fa(v, g[v].size() - 1) - fa(v, ind - 1);
    } else if (l >= vr || vl >= r)
            return 0;
        else
            return sum(2*v + 1, vl, (vl + vr) / 2, l, r) + sum(2*v + 2, (vl + vr) / 2, vr, l, r);
}

set <int> s[N];

int main() {
    int i, j, n, q;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (i = 1; i <= n; ++i)
        s[i].insert(0);
    v = 1;
    while (v < n)
        v *= 2;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        h[i] = a[i];
        s[a[i]].insert(i);
        set <int> :: iterator it = s[a[i]].lower_bound(i);
        --it;
        add_point(i, *it);
    }

    for (i = 0; i < q; ++i) {
        cin >> type[i] >> x[i] >> y[i];
        if (type[i] == 1) {
            set <int> :: iterator it;
            s[a[x[i]]].erase(x[i]);
            it = s[a[x[i]]].lower_bound(x[i]);
            --it;
            int pp = *it;
            ++it;
            if (it != s[a[x[i]]].end()) {
                add_point(*it, x[i]);
                add_point(*it, pp);
            }
            --it;
            add_point(x[i], *it);
            a[x[i]] = y[i];
            it = s[a[x[i]]].lower_bound(x[i]);
            --it;
            pp = *it;
            ++it;
            if (it != s[a[x[i]]].end()) {
                add_point(*it, x[i]);
                add_point(*it, pp);
            }
            --it;
            add_point(x[i], *it);
            s[a[x[i]]].insert(x[i]);
        }
    }
    for (i = 1; i <= n; ++i) {
        s[i].clear();
        a[i] = h[i];
        s[i].insert(0);
    }
    for (i = 1; i <= n; ++i)
        s[a[i]].insert(i);
    build_do(0, 1, v + 1);
    for (i = 1; i <= n; ++i) {
        set <int> :: iterator it = s[a[i]].lower_bound(i);
        --it;
        add(i, *it, i - *it);
    }
    for (i = 0; i < q; ++i)
    if (type[i] == 1) {
        if (y[i] == a[x[i]])
            continue;
        set <int> :: iterator it;
        s[a[x[i]]].erase(x[i]);
        it = s[a[x[i]]].lower_bound(x[i]);
        --it;
        int pp = *it;
        ++it;
        if (it != s[a[x[i]]].end()) {
            add(*it, x[i], x[i] - *it);
            add(*it, pp, *it - pp);
        }
        --it;
        add(x[i], *it, *it - x[i]);
        a[x[i]] = y[i];
        it = s[a[x[i]]].lower_bound(x[i]);
        --it;
        pp = *it;
        ++it;
        if (it != s[a[x[i]]].end()) {
            add(*it, pp, pp - *it);
            add(*it, x[i], -x[i] + *it);
        }
        --it;
        add(x[i], *it, -(*it) + x[i]);
        s[a[x[i]]].insert(x[i]);
    } else {
        cout << sum(0, 1, v + 1, x[i], y[i] + 1) << "\n";
    }
}