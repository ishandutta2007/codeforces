#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 8e5 + 1;
const int LN = 1e7;

struct dek {
    int l, r, key, sz;
    unsigned short int pr;
};

dek m[LN];
int root[N], a[N], top = 0, v;

void recalc(int v) {
    m[v].sz = m[m[v].l].sz + m[m[v].r].sz + 1;
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

int ins(int root, int u) {
    int a, b;
    split(root, a, b, m[u].key);
    return merg(a, merg(u, b));
}

int cct = 0;

int dele(int root, int x) {
    int a, b, c;
    split(root, a, c, x);
    split(a, a, b, x - 1);
    return merg(a, c);
}

int newv(int key) {
    ++top;
    m[top].key = key;
    m[top].pr = rand();
    m[top].sz = 1;
    return top;
}

bool flag = 0;

void add(int i, int j) {
    i = i + v - 2;
    root[i] = ins(root[i], newv(j));
    while (i > 0) {
        i = (i - 1) / 2;
        root[i] = ins(root[i], newv(j));
    }
}

void del(int i, int j) {
    i = i + v - 2;
    root[i] = dele(root[i], j);
    while (i > 0) {
        i = (i - 1) / 2;
        root[i] = dele(root[i], j);
    }
}

int cnt(int v, int vl, int vr, int l, int r, int lx, int rx) {
    if (l <= vl && vr <= r) {
        int a, b, c;
        split(root[v], b, c, rx);
        split(b, a, b, lx - 1);
        int f = m[b].sz;
        root[v] =  merg(a, merg(b, c));
        return f;
    } else if (l >= vr || vl >= r)
            return 0;
        else
            return cnt(2*v + 1, vl, (vl + vr) / 2, l, r, lx, rx) + cnt(2*v + 2, (vl + vr) / 2, vr, l, r, lx, rx);
}

int main() {
    int i, j, n, k, l, r, q;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    v = 1;
    while (v < n)
        v *= 2;
    long long inv = 0;
    for (i = 1; i <= n; ++i) {
        a[i] = i;
        if (i == 2)
            flag = 1;
        add(i, a[i]);
        //inv += cnt(0, 1, v + 1, 1, i, a[i], n);
    }
    for (i = 0; i < q; ++i) {
        cin >> l >> r;
        if (l > r)
            swap(l, r);
        if (l == r) {
            cout << inv << "\n";
            continue;
        }
        if (a[l] < a[r])
            ++inv;
        else
            --inv;
        int x1, y1, x2, y2;
        flag = 0;
        y1 = cnt(0, 1, v + 1, l + 1, r, a[l], n);
        y2 = cnt(0, 1, v + 1, l + 1, r, a[r], n);
        x1 = (r - l - 1 - y1);
        x2 = (r - l - 1 - y2);
        inv += (y1 - x1 + x2 - y2);
        del(l, a[l]);
        del(r, a[r]);
        add(l, a[r]);
        add(r, a[l]);
        swap(a[l], a[r]);
        cout << inv << "\n";
    }
}