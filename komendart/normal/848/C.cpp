#include <bits/stdc++.h>

using namespace std;

#define next osidhofi
#define prev ioakspo

using ll = long long;

const int block_size = 2155; //N ^ (2 / 3);
const int block_cnt = 47;
const int maxn = block_size * block_cnt;
const int maxw = 1e5 + 5;

set<int> pos[maxw];
int next[maxn], prev[maxn];
ll ans_block[block_cnt][block_cnt];
int a[maxn];

void init() {
    for (int i = 0; i < maxn; ++i) {
        a[i] = 0;
        pos[0].insert(i);
        next[i] = i + 1;
        prev[i] = i - 1;
    }
    for (int i = 0; i < block_cnt; ++i) {
        for (int j = i; j < block_cnt; ++j) {
            ans_block[i][j] = (j + 1 - i) * block_size - 1;
        }
    }
}

void update(int p, int x) {
    for (int i = 0; i < block_cnt; ++i) {
        for (int j = i; j < block_cnt; ++j) {
            int L = i * block_size;
            int R = (j + 1) * block_size - 1;
            if (p < L || p > R) continue;
            if (prev[p] < L && next[p] <= R) {
                ans_block[i][j] += p - next[p];
            }
            if (prev[p] >= L && next[p] > R) {
                ans_block[i][j] += prev[p] - p;
            }
        }
    }

    if (prev[p] >= 0) next[prev[p]] = next[p];
    if (next[p] < maxn) prev[next[p]] = prev[p];
    pos[a[p]].erase(p);
    auto it = pos[x].upper_bound(p);
    if (it == pos[x].end()) {
        next[p] = maxn;
    } else {
        next[p] = *it;
        prev[*it] = p;
    }
    if (it == pos[x].begin()) {
        prev[p] = -1;
    } else {
        --it;
        prev[p] = *it;
        next[*it] = p;
    }
    a[p] = x;
    pos[x].insert(p);

    for (int i = 0; i < block_cnt; ++i) {
        for (int j = i; j < block_cnt; ++j) {
            int L = i * block_size;
            int R = (j + 1) * block_size - 1;
            if (p < L || p > R) continue;
            if (prev[p] < L && next[p] <= R) {
                ans_block[i][j] -= p - next[p];
            }
            if (prev[p] >= L && next[p] > R) {
                ans_block[i][j] -= prev[p] - p;
            }
        }
    }
}

ll get(int left, int right) {
    int lb = left / block_size;
    int rb = right / block_size;
    ll ans = ans_block[lb][rb];
    int L = lb * block_size;
    int R = (rb + 1) * block_size - 1;
    for (; L < left; ++L) {
        if (next[L] <= R) {
            ans += L - next[L];
        }
    }
    for (; R > right; --R) {
        if (prev[R] >= L) {
            ans += prev[R] - R;
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        update(i, x);
    }
    for (int i = 0; i < m; ++i) {
        int tp; cin >> tp;
        if (tp == 1) {
            int p, x;
            cin >> p >> x;
            update(p - 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << get(l - 1, r - 1) << '\n';
        }
    }
}