#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7;
const int depth = 19;

int go[maxn][2];
int size[maxn];
int last = 0;

void add(int x) {
    vector<int> bits(depth);
    for (int i = 0; i < depth; ++i) {
        bits[depth - i - 1] = x & 1;
        x >>= 1;
    }
    int cur = 0;
    for (auto i: bits) {
        if (!go[cur][i]) {
            go[cur][i] = ++last;
        }
        cur = go[cur][i];
    }
    if (size[cur] == 1) return;
    cur = 0;
    for (auto i: bits) {
        cur = go[cur][i];
        ++size[cur];
    }
}

int mex(int x) {
    vector<int> bits(depth);
    for (int i = 0; i < depth; ++i) {
        bits[depth - i - 1] = x & 1;
        x >>= 1;
    }
    int need = 1 << (depth - 1);
    int ans = 0;
    int cur = 0;
    bool flag = false;
    for (auto i: bits) {
        if (flag) {
            ans = ans * 2;
        } else if (size[go[cur][i]] != need) {
            ans = ans * 2;
            if (!go[cur][i]) {
                flag = true;
                continue;
            }
            cur = go[cur][i];
        } else {
            ans = ans * 2 + 1;
            if (!go[cur][i]) {
                flag = true;
                continue;
            }
            cur = go[cur][i ^ 1];
        }
        need >>= 1;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        add(x);
    }
    int acc = 0;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        acc ^= x;
        cout << mex(acc) << '\n';
    }
}