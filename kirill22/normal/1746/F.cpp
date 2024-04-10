#include "bits/stdc++.h"

using namespace std;

mt19937 gen(time(0));
const int N = 1e6;
int a[N], b[N], val[N], n, q;
int qu[N][3], ans[N];
long long f[N];
vector<int> num;

int get(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}

void update(int i, int x) {
    while (i < n) {
        f[i] += x;
        i |= (i + 1);
    }
}

long long query(int i) {
    long long res = 0;
    while (i >= 0) {
        res += f[i];
        i = (i & (i + 1)) - 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        num.push_back(a[i]);
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> qu[i][0] >> qu[i][1];
            qu[i][0]--;
            num.push_back(qu[i][1]);
        } else {
            cin >> qu[i][0] >> qu[i][1] >> qu[i][2];
            qu[i][0]--, qu[i][1]--;
        }
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    for (int i = 0; i < n; i++) {
        a[i] = get(a[i]);
    }
    for (int i = 0; i < q; i++) {
        if (qu[i][2] == 0) {
            qu[i][1] = get(qu[i][1]);
        }
    }
    fill(ans, ans + q, 1);
    for (int t = 0; t < 40; t++) {
        for (int i = 0; i < num.size(); i++) {
            val[i] = gen() % n;
        }
        fill(f, f + n, 0);
        for (int i = 0; i < n; i++) {
            update(i, val[a[i]]);
            b[i] = val[a[i]];
        }
        for (int i = 0; i < q; i++) {
            if (qu[i][2] == 0) {
                update(qu[i][0], val[qu[i][1]] - b[qu[i][0]]);
                b[qu[i][0]] = val[qu[i][1]];
            } else {
                auto [l, r, k] = std::tie(qu[i][0], qu[i][1], qu[i][2]);
                if ((r - l + 1) % k != 0) {
                    ans[i] = 0;
                } else if ((query(r) - query(l - 1)) % k != 0) {
                    ans[i] = 0;
                }
            }
        }
    }
    for (int i = 0; i < q; i++) {
        if (qu[i][2] != 0) {
            cout << (ans[i] ? "YES\n" : "NO\n");
        }
    }
}