#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 4e5 + 1;
const long long mod = 1e9 + 7;

struct dek {
    int l, r, cnt, sz, key, pr;
};

dek m[N];
int top = 0;

int nod(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

void recalc(int v) {
    m[v].sz = m[v].cnt + m[m[v].l].sz + m[m[v].r].sz;
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

int newv(int x) {
    ++top;
    m[top].pr = rand();
    m[top].key = x;
    m[top].sz = 1;
    m[top].cnt = 1;
    return top;
}

int ins(int root, int x) {
    int a, b, c;
    split(root, b, c, x);
    split(b, a, b, x - 1);
    if (b == 0)
        b = newv(x);
    else {
        m[b].sz++;
        m[b].cnt++;
    }
    return merg(a, merg(b, c));
}

int del(int root, int x) {
    int a, b, c;
    split(root, b, c, x);
    split(b, a, b, x - 1);
    if (m[b].cnt == 1)
        return merg(a, c);
    else {
        m[b].sz--;
        m[b].cnt--;
        return merg(a, merg(b, c));
    }
}

vector <pair<int, int> > v, v1, v2;
int p[N], s[N], b[N], inc[N], ans[N], pref[N];

int main() {
    int i, j, n, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i)
        cin >> p[i];
    for (i = 1; i <= n; ++i)
        cin >> s[i];
    for (i = 1; i <= n; ++i)
        cin >> b[i];
    for (i = 1; i <= k; ++i)
        cin >> inc[i];
    for (i = 1; i <= k; ++i) {
        cin >> pref[i];
        v.push_back({inc[i], i});
    }
    for (i = 1; i <= n; ++i) {
        v1.push_back({p[i], i});
        v2.push_back({s[i], i});
    }
    int l1 = 0, l2 = 0, root1 = 0, root2 = 0;
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (i = 0; i < k; ++i) {
        while (l1 < v1.size() && v1[l1].fi <= v[i].fi) {
            if (p[v1[l1].se] <= s[v1[l1].se]) {
                root1 = ins(root1, b[v1[l1].se] + p[v1[l1].se]);
                root2 = ins(root2, b[v1[l1].se] - p[v1[l1].se]);
            }
            ++l1;
        }
        while (l2 < v2.size() && v2[l2].fi < v[i].fi) {
            if (p[v2[l2].se] <= s[v2[l2].se]) {
                root1 = del(root1, b[v2[l2].se] + p[v2[l2].se]);
                root2 = del(root2, b[v2[l2].se] - p[v2[l2].se]);
            }
            ++l2;
        }
        int a, b;
        split(root1, a, b, pref[v[i].se] + inc[v[i].se]);
        int x = m[a].sz;
        root1 = merg(a, b);
        split(root2, a, b, pref[v[i].se] - inc[v[i].se] - 1);
        x -= m[a].sz;
        root2 = merg(a, b);
        ans[v[i].se] = x;
    }
    for (i = 1; i <= k; ++i)
        cout << ans[i] << ' ';
}