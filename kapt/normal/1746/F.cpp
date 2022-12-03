#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 100, MAXP = 30;
int arr[MAXN];

mt19937 rnd;

int tree[MAXP][MAXN];

void update(int id, int i, int val) {
    for (int j = i + 1; j < MAXN; j += (j & (-j))) {
        /// cout << j << endl;
        tree[id][j] += val;
    }
}

int get(int id, int i) {
    int res = 0;
    for (int j = i + 1; j > 0; j -= (j & (-j))) {
        /// cout << j << endl;
        res += tree[id][j];
    }
    return res;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> val;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        val.push_back(arr[i]);
    }
    vector<array<int, 3>> qu(q);
    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int j, x;
            cin >> j >> x;
            j--;
            val.push_back(x);
            qu[i] = {-1, j, x};
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            qu[i] = {l, r, k};
        }
    }
    sort(val.begin(), val.end());
    int k = unique(val.begin(), val.end()) - val.begin();
    /// shuffle(val.begin(), val.begin() + k, rnd);
    map<int, int> mp;
    for (int i = 0; i < k; ++i) {
        mp[val[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = mp[arr[i]];
    }
    /// cerr << "arr done" << endl;
    for (int i = 0; i < q; ++i) {
        if (qu[i][0] == -1) {
            qu[i][2] = mp[qu[i][2]];
        }
    }
    vector<int> mask(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < MAXP; ++j) {
            if (rnd() % 2) {
                mask[i] |= (1 << j);
            }
        }
    }
    /// cerr << "pstart" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < MAXP; ++j) {
            if (mask[arr[i]] & (1 << j)) {
                update(j, i, 1);
            }
        }
    }
    /// cerr << "start" << endl;
    for (auto elem : qu) {
        if (elem[0] == -1) {
            int i = elem[1], x = elem[2];
            for (int j = 0; j < MAXP; ++j) {
                if (mask[arr[i]] & (1 << j)) {
                    update(j, i, -1);
                }
            }
            arr[i] = x;
            for (int j = 0; j < MAXP; ++j) {
                if (mask[arr[i]] & (1 << j)) {
                    update(j, i, 1);
                }
            }
        } else {
            int l = elem[0], r = elem[1];
            int k = elem[2];
            bool f = true;
            for (int j = 0; j < MAXP && f; ++j) {
                if ((get(j, r - 1) - get(j, l - 1)) % k != 0) f = false;
            }
            if (f) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}