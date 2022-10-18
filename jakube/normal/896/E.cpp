#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1e4;
const int BLK_SZ = sqrt(MAXN) + 1;
// const int MAXN = 150;
// const int BLK_SZ = 4;

vector<int> max_value(BLK_SZ, 0);
vector<int> lower(BLK_SZ, 0);
vector<int> pre(MAXN, -1);
int n;
vector<int> a(BLK_SZ* BLK_SZ, 0);
vector<int> root_values(MAXN, 0);

struct S {
    int first_idx = -1;
    int cnt = 0;
};

vector<vector<S>> dsu(BLK_SZ, vector<S>(MAXN));

void rebuild(int blk)
{
    for (int i = 0; i < BLK_SZ; i++) {
        int idx = blk * BLK_SZ + i;
        int value = a[idx];
        max_value[blk] = max(max_value[blk], value);
        lower[blk] = 0;
        auto& entry = dsu[blk][value];
        if (entry.first_idx == -1) {
            entry = {idx, 1};
            pre[idx] = idx;
            root_values[idx] = value;
        } else {
            entry.cnt++;
            pre[idx] = entry.first_idx;
        }
    }
}

int find_root(int idx)
{
    if (pre[idx] == -1)
        exit(0);
    return pre[idx] = pre[idx] == idx ? idx : find_root(pre[idx]);
}

void push_down(int blk)
{
    for (int i = 0; i < BLK_SZ; i++) {
        int idx = blk * BLK_SZ + i;
        int root = find_root(idx);
        int value = root_values[root];
        a[idx] = value - lower[blk];
        dsu[blk][value] = {-1, 0};
    }
    max_value[blk] = 0;
    lower[blk] = 0;
}

int count_slow(int blk, int l, int r, int x) {
    int cnt = 0;
    for (int idx = l; idx < r; idx++) {
        int root = find_root(idx);
        int value = root_values[root];
        if (value - lower[blk] == x)
            cnt++;
    }
    return cnt;
}

int answer(int l, int r, int x)
{
    int p = l / BLK_SZ;
    int q = r / BLK_SZ;

    if (p == q)
        return count_slow(p, l, r, x);

    int cnt = 0;
    cnt += count_slow(p, l, (p + 1) * BLK_SZ, x);
    cnt += count_slow(q, q * BLK_SZ, r, x);
    for (int blk = p + 1; blk < q; blk++) {
        if (x + lower[blk] <= max_value[blk])
            cnt += dsu[blk][x + lower[blk]].cnt;
    }
    return cnt;
}

void merge(int blk, int from, int to) {
    auto& f = dsu[blk][from];
    auto& t = dsu[blk][to];
    if (f.first_idx == -1)
        return;

    if (t.first_idx != -1) {
        pre[f.first_idx] = t.first_idx;
        t.cnt += f.cnt;
        f = {-1, 0};
    } else {
        t = {f.first_idx, f.cnt};
        f = {-1, 0};
        root_values[t.first_idx] = to;
    }
}

void operation_fast(int blk, int x)
{
    if (2 * x <= max_value[blk] - lower[blk]) {
        for (int value = lower[blk] + 1; value <= lower[blk] + x; value++) {
            merge(blk, value, value + x);
        }
        lower[blk] += x;
    } else {
        for (int value = lower[blk] + x + 1; value <= max_value[blk]; value++) {
            merge(blk, value, value - x);
        }
        max_value[blk] = min(max_value[blk], x + lower[blk]);
    }
}

void operation_slow(int blk, int l, int r, int x) {
    push_down(blk);
    for (int idx = l; idx < r; idx++) {
        if (a[idx] > x)
            a[idx] -= x;
    }
    rebuild(blk);
}

void operation(int l, int r, int x)
{
    int p = l / BLK_SZ;
    int q = r / BLK_SZ;

    if (p == q) {
        operation_slow(p, l, r, x);
    } else {
        operation_slow(p, l, (p + 1) * BLK_SZ, x);
        operation_slow(q, q * BLK_SZ, r, x);
        for (int blk = p + 1; blk < q; blk++) {
            operation_fast(blk, x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= (n - 1) / BLK_SZ; i++)
        rebuild(i);

    for (int i = 0; i < m; i++) {
        int type, l, r, x;
        cin >> type >> l >> r >> x;
        l--;
        if (type == 2) {
            cout << answer(l, r, x) << '\n';
            // cout << answer(l, r, x) << endl;
        } else {
            operation(l, r, x);
        }
    }
}