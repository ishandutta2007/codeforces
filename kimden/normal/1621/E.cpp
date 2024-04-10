#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int MAXN = (1 << 17);
int tree[2 * MAXN + 5];
ll suff[2 * MAXN + 5];

ll query() {
    return suff[1];
}

void upd(int idx, int val) {
    idx += MAXN;
    while (idx > 0) {
        tree[idx] += val;
        if (idx >= MAXN) {
            suff[idx] = min<ll>(tree[idx], 0);
        } else {
            suff[idx] = min<ll>(suff[idx * 2 + 1], tree[idx * 2 + 1] + suff[idx * 2]);
        }
        idx /= 2;
    }
}

inline ll get(ll x, int y) {
    return (x + y - 1) / y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < 2 * MAXN; ++i) {
        tree[i] = 0;
    }
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> tutors(n);
        for (int& i: tutors) {
            cin >> i;
            upd(i, 1);
        }
        vector<int> sz(m);
        vector<vector<int>> students(m);
        for (int i = 0; i < m; ++i) {
            cin >> sz[i];
            students[i].resize(sz[i]);
            ll sum = 0;
            for (int& j: students[i]) {
                cin >> j;
                sum += j;
            }
            upd(get(sum, sz[i]), -1);
        }
        // end of init
        for (int i = 0; i < m; ++i) {
            ll sum = 0;
            for (int& j: students[i]) {
                sum += j;
            }
            for (int& j: students[i]) {
                upd(get(sum, sz[i]), 1);
                upd(get(sum - j, sz[i] - 1), -1);
                ll minsum = query();
                if (minsum < 0) {
                    cout << '0';
                } else {
                    cout << '1';
                }
                upd(get(sum - j, sz[i] - 1), 1);
                upd(get(sum, sz[i]), -1);
            }
        }
        cout << "\n";
        // finish
        for (int& i: tutors) {
            upd(i, -1);
        }
        for (int i = 0; i < m; ++i) {
            ll sum = 0;
            for (int& j: students[i]) {
                sum += j;
            }
            upd(get(sum, sz[i]), 1);
        }
    }


}