#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;

struct dek {
    int l, r, pr, mxcnt, d, key, cnt;
};

dek m[N];
int top = 0;

void recalc(int v) {
    m[v].mxcnt = max(max(m[m[v].l].mxcnt, m[m[v].r].mxcnt), m[v].cnt) + m[v].d;
}

void push(int v) {
    if (m[v].d != 0) {
        if (m[v].l != 0) {
            m[m[v].l].key += m[v].d;
            m[m[v].l].mxcnt += m[v].d;
            m[m[v].l].cnt += m[v].d;
            m[m[v].l].d += m[v].d;
        }
        if (m[v].r != 0) {
            m[m[v].r].key += m[v].d;
            m[m[v].r].mxcnt += m[v].d;
            m[m[v].r].cnt += m[v].d;
            m[m[v].r].d += m[v].d;
        }
        m[v].d = 0;
    }
}

int merg(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (m[a].pr > m[b].pr) {
        push(a);
        m[a].r = merg(m[a].r, b);
        recalc(a);
        return a;
    } else {
        push(b);
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
    push(root);
    if (m[root].key <= x) {
        split(m[root].r, m[root].r, b, x);
        a = root;
    } else {
        split(m[root].l, a, m[root].l, x);
        b = root;
    }
    recalc(root);
}

void add(int v, int x) {
    m[v].d += x;
    m[v].mxcnt += x;
    m[v].key += x;
    m[v].cnt += x;
}

int ins(int root, int u) {
    int a, b, c;
    split(root, b, c, m[u].key);
    split(b, a, b, m[u].key - 1);
    if (b == 0)
        b = u;
    else {
        m[b].cnt = max(m[b].cnt, m[u].cnt);
        m[b].mxcnt = m[b].cnt;
    }
    return merg(a, merg(b, c));
}

int newv(int time, int cnt) {
    ++top;
    m[top].cnt = cnt;
    m[top].mxcnt = cnt;
    m[top].key = time;
    m[top].pr = rand();
    return top;
}

int main() {
    int i, j, n, k, l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int root = newv(0, 0);
    for (i = 0; i < n; ++i) {
        cin >> l >> r;
        int a, b, c, d;
        split(root, a, b, l - 1);
        split(b, b, c, r - 1);
        split(c, c, d, r);
        if (b != 0)
            add(b, 1);
        b = ins(b, newv(l, m[a].mxcnt + 1));
        b = ins(b, c);
        root = merg(a, merg(b, d));
    }
    cout << m[root].mxcnt;
}