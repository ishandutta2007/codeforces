#include <bits/stdc++.h>
using namespace std;

const int SQRT = 450;

using S = array<int, 101>;

vector<int> v;
array<S, SQRT> blocks;
array<int, SQRT * SQRT> pre;
array<int, SQRT * SQRT> final_val;

void build(int idx) {
    auto& blk = blocks[idx];
    for (int i = idx * SQRT; i < idx * SQRT + SQRT; i++) {
        int val = v[i];
        if (blk[val] < 0) {
            blk[val] = i;
            final_val[i] = v[i];
        }
        pre[i] = blk[val];
    }
}

int find(int x) {
    return pre[x] = pre[x] == x ? x : find(pre[x]);
}

void pushdown(int idx) {
    auto& blk = blocks[idx];
    for (int i = idx * SQRT; i < idx * SQRT + SQRT; i++) {
        v[i] = final_val[find(i)];
    }
    fill(blk.begin(), blk.end(), -1);
}

void manual_query(int idx, int l, int r, int x, int y) {
    pushdown(idx);
    for (int i = l; i < r; i++) {
        if (v[i] == x) 
            v[i] = y;
    }
    build(idx);
}

void query(int l, int r, int x, int y) {
    int p = l / SQRT;
    int q = r / SQRT;
    if (p == q) {
        manual_query(p, l, r, x, y);
    } else {
        manual_query(p, l, p * SQRT + SQRT, x, y);
        manual_query(q, q * SQRT, r, x, y);
        for (int idx = p + 1; idx < q; idx++) {
            auto& blk = blocks[idx];
            if (blk[x] >= 0) {
                if (blk[y] >= 0) {
                    pre[blk[x]] = blk[y];
                    blk[x] = -1;
                } else {
                    blk[y] = blk[x];
                    final_val[blk[y]] = y;
                    blk[x] = -1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    v.assign(SQRT * SQRT, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    fill(pre.begin(), pre.end(), -1);
    for (int i = 0; i < SQRT; i++) {
        fill(blocks[i].begin(), blocks[i].end(), -1);
        build(i);
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        l--;
        if (x != y) 
            query(l, r, x, y);
    }

    for (int i = 0; i < SQRT; i++) {
        pushdown(i);
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
}