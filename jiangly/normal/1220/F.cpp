#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 4E5;
struct Node { int mx, lazy; };
Node t[4 * MAX_N];
void pushDown(int p) {
    t[2 * p].mx+= t[p].lazy;
    t[2 * p].lazy += t[p].lazy;
    t[2 * p + 1].mx+= t[p].lazy;
    t[2 * p + 1].lazy += t[p].lazy;
    t[p].lazy = 0;
}
void rangeAdd(int p, int l, int r, int x, int y, int v) {
    if (l >= y || r <= x) return;
    if (l >= x && r <= y) {
        t[p].mx += v;
        t[p].lazy += v;
        return;
    }
    int mid = (l + r) / 2;
    pushDown(p);
    rangeAdd(2 * p, l, mid, x, y, v);
    rangeAdd(2 * p + 1, mid, r, x, y, v);
    t[p].mx = max(t[2 * p].mx, t[2 * p + 1].mx);
}
void modify(int p, int l, int r, int x, int v) {
    if (r - l == 1) {
        t[p].mx = v;
        return;
    }
    int mid = (l + r) / 2;
    pushDown(p);
    if (x < mid) modify(2 * p, l, mid, x, v);
    else modify(2 * p + 1, mid, r, x, v);
    t[p].mx = max(t[2 * p].mx, t[2 * p + 1].mx);
}
int getVal(int p, int l, int r, int x) {
    if (r - l == 1) return t[p].mx;
    int mid = (l + r) / 2;
    pushDown(p);
    if (x < mid) return getVal(2 * p, l, mid, x);
    return getVal(2 * p + 1, mid, r, x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    a.insert(a.end(), a.begin(), a.end());
    vector<int> l(2 * n), r(2 * n);
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < 2 * n; ++i) {
        while (stk.size() >= 2 && a[stk.top()] > a[i]) stk.pop();
        l[i] = stk.top();
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    stk.push(2 * n);
    for (int i = 2 * n - 1; i >= 0; --i) {
        while (stk.size() >= 2 && a[stk.top()] > a[i]) stk.pop();
        r[i] = stk.top();
        stk.push(i);
    }
    int ans = 1E9, pos = -1;
    for (int i = 0; i < 2 * n; ++i) {
        if (i >= n) {
            if (t[1].mx < ans) {
                ans = t[1].mx;
                pos = i - n;
            }
            rangeAdd(1, 0, 2 * n, i - n, r[i - n], -1);
            modify(1, 0, 2 * n, i - n, 0);
        }
        modify(1, 0, 2 * n, i, l[i] == -1 ? 1 : getVal(1, 0, 2 * n, l[i]) + 1);
        rangeAdd(1, 0, 2 * n, l[i] + 1, i, 1);
    }
    assert(pos != -1);
    cout << ans << " " << pos << "\n";
    return 0;
}