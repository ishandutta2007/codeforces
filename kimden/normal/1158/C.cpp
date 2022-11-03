#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MAXN = 1 << 19;
int N;
int tree[MAXN * 2], psh[MAXN * 2];

void push(int idx, int l, int r) {
    if (psh[idx] != 0) {
        if (l != r) {
            tree[idx << 1] += psh[idx];
            tree[(idx << 1) ^ 1] += psh[idx];
            psh[idx << 1] += psh[idx];
            psh[(idx << 1) ^ 1] += psh[idx];
        }
        psh[idx] = 0;
    }
}

void upd(int idx, int l, int r, int tl, int tr, int val) {
    if (l > tr || tl > r || tl > tr) {
        return;
    }
    push(idx, l, r);
    if (l == tl && r == tr) {
        tree[idx] += val;
        psh[idx] += val;
        return;
    }
    int mid = (l + r + 1) / 2;
    upd((idx << 1), l, mid - 1, tl, min(mid - 1, tr), val);
    upd((idx << 1) ^ 1, mid, r, max(tl, mid), tr, val);
    tree[idx] = min(tree[idx << 1], tree[(idx << 1) ^ 1]);
}

int find_zero(int idx, int l, int r) {
    push(idx, l, r);
    if (tree[idx] != 0) {
        return -1;
    }
    if (l == r) {
        return l;
    }
    int mid = (l + r + 1) / 2;
    int x = find_zero(idx << 1, l, mid - 1);
    if (x != -1) return x;
    x = find_zero((idx << 1) ^ 1, mid, r);
    return x;
}

void solve() {
    int n;
    cin >> n;
//    n = 500000;
    N = 4;
    while (N < n) {
        N <<= 1;
    }
    vector<int> next(n);
//    mt19937 mt(413);
    for (int i = 0; i < n; ++i) {
        cin >> next[i];
//next[i] = (mt() % 5 != 0 ? -1 : i + 2);
        --next[i];
    }
    vector<vector<int>> pressure(n);
    for (int i = 0; i < 2 * N; ++i) {
        tree[i] = 0;
        psh[i] = 0;
    }
    vector<int> perm(n, -1);
    int cnt = n;
    for (int i = 0; i < n; ++i) {
        if (next[i] >= 0) {
            upd(1, 0, N - 1, i + 1, next[i] - 1, 1);
            if (next[i] < n) {
                upd(1, 0, N - 1, i, i, 1);
                pressure[next[i]].push_back(i);
            }
        }
    }
    while (cnt) {
        int where = find_zero(1, 0, N - 1);
        if (where == -1 || where >= n) {
            cout << -1 << "\n";
            return;
        }
        perm[where] = --cnt;
        for (int j: pressure[where]) {
            upd(1, 0, N - 1, j, j, -1);
        }
        if (next[where] >= 0) {
            upd(1, 0, N - 1, where + 1, next[where] - 1, -1);
        }
        upd(1, 0, N - 1, where, where, 12345678);
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << " ";
        }
        cout << perm[i] + 1;
    }
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}