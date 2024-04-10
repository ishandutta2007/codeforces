#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N  = 4e5 + 1;
const int LN = 1e6 + 1;

struct dek {
    int l, r, pr;
    long long cnt, scnt, sum, key;
};

dek m[LN];
long long stats[N], dp0[N], dp1[N];
int rt[N], cnt[N], top = 0;
vector <pair<int, pair<int, int> > > e[N];
vector <int> vert;

void recalc(int v) {
    m[v].sum = m[v].cnt * m[v].key + m[m[v].l].sum + m[m[v].r].sum;
    m[v].scnt = m[v].cnt + m[m[v].l].scnt + m[m[v].r].scnt;
}

int merg(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (m[a].pr > m[b].pr) {
        m[a].r = merg(m[a].r, b);
        recalc(a);
        return a;
    } else {
        m[b].l = merg(a, m[b].l);
        recalc(b);
        return b;
    }
}

void split(int root, int &a, int &b, int x) {
    if (root == 0) {
        a = 0;
        b = 0;
        return;
    }
    if (m[root].key <= x) {
        split(m[root].r, m[root].r, b, x);
        a = root;
    } else {
        split(m[root].l, a, m[root].l, x);
        b = root;
    }
    recalc(root);
}

long long cntmaxk(int root, long long cnt) {
    if (root == 0 || cnt == 0)
        return 0;
    if (m[m[root].l].scnt  >= cnt)
        return cntmaxk(m[root].l, cnt);
    else if (m[m[root].l].scnt + m[root].cnt < cnt)
            return m[m[root].l].sum + m[root].cnt * m[root].key + cntmaxk(m[root].r, cnt - m[m[root].l].scnt - m[root].cnt);
        else
            return m[m[root].l].sum + (cnt - m[m[root].l].scnt) * m[root].key;
}

int ins(int root, int u) {
    int a, b, c;
    split(root, b, c, m[u].key);
    split(b, a, b, m[u].key - 1);
    if (b == 0)
        b = u;
    else {
        ++m[b].cnt;
        recalc(b);
    }
    return merg(a, merg(b, c));
}

int del_one(int root, int x) {
    int a, b, c;
    split(root, b, c, x);
    split(b, a, b, x - 1);
    if (m[b].cnt <= 1)
        return merg(a, c);
    else {
        --m[b].cnt;
        recalc(b);
        return merg(a, merg(b, c));
    }
}

int newv(int x) {
    ++top;
    m[top].pr = rand();
    m[top].key = x;
    m[top].sum = x;
    m[top].cnt = 1;
    m[top].scnt = 1;
    return top;
}

void dfs(int u, int pr, int k) {
    long long fsum = 0;
    vector <long long> v;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].se.fi != pr) {
        dfs(e[u][i].se.fi, u, k);
        fsum += dp1[e[u][i].se.fi] + e[u][i].se.se;
        v.push_back(min((long long)0, dp0[e[u][i].se.fi] - dp1[e[u][i].se.fi] - e[u][i].se.se));
    }
    long long y = m[rt[u]].sum;
    for (int i = 0; i < v.size(); ++i) {
        rt[u] = ins(rt[u], newv(v[i]));
    }
    dp0[u] = stats[u] + fsum + cntmaxk(rt[u], k - 1);
    dp1[u] = stats[u] + fsum + cntmaxk(rt[u], k);
    for (int i = 0; i < v.size(); ++i)
        rt[u] = del_one(rt[u], v[i]);
}

void dfs1(int u, int pr, int k) {
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].se.fi != pr)
        dfs1(e[u][i].se.fi, u, k);
    if (cnt[u] <= k) {
        for (int i = 0; i < e[u].size(); ++i)
        if (e[u][i].se.fi == pr) {
            stats[pr] += e[u][i].se.se;
            rt[pr] = ins(rt[pr], newv(-e[u][i].se.se));
        } else if (cnt[e[u][i].se.fi] > k) {
                vert.push_back(e[u][i].se.fi);
                stats[e[u][i].se.fi] += e[u][i].se.se;
                rt[e[u][i].se.fi] = ins(rt[e[u][i].se.fi], newv(-e[u][i].se.se));
            }
    }
    int j = e[u].size() - 1;
    while (j >= 0 && -e[u][j].fi <= k)
        --j;
    e[u].resize(j + 1);
}
int a[N], b[N], c[N];

int main() {
    int i, j, k, n, q;
    long long pp = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        ++cnt[a[i]];
        ++cnt[b[i]];
        pp += c[i];
    }
    for (i = 1; i < n; ++i) {
        e[a[i]].push_back({-cnt[b[i]], {b[i], c[i]}});
        e[b[i]].push_back({-cnt[a[i]], {a[i], c[i]}});
    }
    for (i = 1; i <= n; ++i)
        sort(e[i].begin(), e[i].end());
    vert.push_back(1);
    cout << pp;
    for (i = 1; i < n; ++i) {
        long long ans = 0;
        for (j = 0; j < vert.size(); ++j) {
            dfs(vert[j], 0, i);
            ans += dp1[vert[j]];
        }
        for (j = 0; j < vert.size(); ++j)
            dfs1(vert[j], 0, i);
        j = 0;
        while (j < vert.size())
        if (cnt[vert[j]] <= i) {
            swap(vert[j], vert[vert.size() - 1]);
            vert.resize(vert.size() - 1);
        } else
            ++j;
        cout << ' ' << ans;
    }
}