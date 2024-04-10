#include <bits/stdc++.h>
using namespace std;
const int N = 8e5 + 10;
const int inf = 1e9;

int mx[N], mn[N], ptl[N], ptr[N], d[N], dp[N], h[N];


void recalc(int v) {
    mx[v] = max(mx[2*v + 1], mx[2*v + 2]);
    mn[v] = min(mn[2*v + 1], mn[2*v + 2]);
    ptl[v] = max(max(ptl[2*v + 1], ptl[2*v + 2]), mx[2*v + 1] - 2 * mn[2*v + 2]);
    ptr[v] = max(max(ptr[2*v + 1], ptr[2*v + 2]), mx[2*v + 2] - 2 * mn[2*v + 1]);
    dp[v] = max(max(dp[2*v + 1], dp[2*v + 2]), max(ptl[2*v + 1] + mx[2*v + 2], mx[2*v + 1] + ptr[2*v + 2]));
}

void add_vertex(int v, int x) {
    mx[v] += x;
    mn[v] += x;
    d[v] += x;
    ptl[v] -= x;
    ptr[v] -= x;
}

void push(int v) {
    if (d[v] != 0) {
        add_vertex(2*v + 1, d[v]);
        add_vertex(2*v + 2, d[v]);
        d[v] = 0;
    }
}

void add(int v, int vl, int vr, int l, int r, int x) {
    if (l <= vl && vr <= r)
        add_vertex(v, x);
    else if (l >= vr || vl >= r)
            return;
        else {
            push(v);
            add(2*v + 1, vl, (vl + vr) / 2, l, r, x);
            add(2*v + 2, (vl + vr) / 2, vr, l ,r, x);
            recalc(v);
        }
}

void build(int v, int vl, int vr) {
    d[v] = 0;
    if (vl + 1 == vr) {
        mx[v] = h[vl];
        mn[v] = h[vl];
        ptr[v] = -h[vl];
        ptl[v] = -h[vl];
        dp[v] = 0;
    } else {
        build(2*v + 1, vl, (vl + vr) / 2);
        build(2*v + 2, (vl + vr) / 2, vr);
        recalc(v);
    }
}

string s;

int main() {
    int i, j, k, n, l, q, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    cin >> s;
    int len = 2 * (n - 1);
    int hh = 0;
    for (i = 1; i <= len; ++i) {
        if (s[i - 1] == '(')
            ++hh;
        else
            --hh;
        h[i] = hh;
    }
    build(0, 1, len + 1);
    cout << dp[0] << endl;
    for (int y = 0; y < q; ++y) {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (s[a - 1] == ')')
            add(0, 1, len + 1, a, b, 2);
        else
            add(0, 1, len + 1, a, b, -2);
        swap(s[a - 1], s[b - 1]);
        cout << dp[0] << endl;
    }
}