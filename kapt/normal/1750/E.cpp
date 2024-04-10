#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int get(string s) {
    int bal = 0, minbal = 0;
    for (auto ch : s) {
        if (ch == '(') {
            bal++;
        } else {
            bal--;
            minbal = min(minbal, bal);
        }
    }
    return abs(bal) + max((int64_t)0, min(bal, (int64_t)0) - minbal);
}

const int MAXN = 2e5 + 100;

array<int, 2> tree[MAXN * 8];

array<int, 2> operator+(array<int, 2> a, array<int, 2> b) {
    a[0] += b[0];
    a[1] += b[1];
    return a;
}

void pull(int v) {
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

void update(int v, int vl, int vr, int ind, int val) {
    if (ind >= vr || ind < vl) return;
    if (vr - vl == 1) {
        tree[v][0] += val;
        tree[v][1]++;
        return;
    }
    int vm = (vl + vr) / 2;
    update(v * 2, vl, vm, ind, val);
    update(v * 2 + 1, vm, vr, ind, val);
    pull(v);
}

array<int, 2> sum(int v, int vl, int vr, int l, int r) {
    if (l >= vr || r <= vl) {
        return {0, 0};
    }
    if (l <= vl && r >= vr) {
        return tree[v];
    }
    int vm = (vl + vr) / 2;
    auto res1 = sum(v * 2, vl, vm, l, r);
    auto res2 = sum(v * 2 + 1, vm, vr, l, r);
    return res1 + res2;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        array<int, 2> elem = {0, 0};
        int mn = n + 10;
        fill(tree, tree + 8 * mn, elem);
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                pref[i + 1] = pref[i] + 1;
            } else {
                pref[i + 1] = pref[i] - 1;
            }
        }
        for (int l = n; l >= 0; --l) {
            auto res1 = sum(1, 0, mn * 2, pref[l] + mn, mn * 2);
            auto res2 = sum(1, 0, mn * 2, 0, pref[l] + mn);
            ans += res1[0];
            ans += res2[1] * pref[l];
            // cout << res1[0] << " " << res2[1] << endl;
            update(1, 0, mn * 2, pref[l] + mn, pref[l]);
        }
        /// cout << ans << endl;
        vector<int> rgh(n + 1, n + 1), lft(n + 1, -1);
        vector<int> st;
        st.push_back(n + 1);
        for (int i = n; i >= 0; --i) {
            while (st.back() != n + 1 && pref[st.back()] >= pref[i]) {
                st.pop_back();
            }
            rgh[i] = st.back();
            st.push_back(i);
        }
        st.clear();
        st.push_back(-1);
        for (int i = 0; i <= n; ++i) {
            while (st.back() != -1 && pref[st.back()] > pref[i]) {
                st.pop_back();
            }
            lft[i] = st.back();
            st.push_back(i);
        }
        for (int i = 0; i <= n; ++i) {
            int cnt = (rgh[i] - i) * (i - lft[i]) - 1;
            ans -= pref[i] * cnt;
        }
        cout << ans << '\n';
    }
    return 0;
}