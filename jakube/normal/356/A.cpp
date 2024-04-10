#include <bits/stdc++.h>
using namespace std;

struct Fight {
    int l, r, x;
};

class SegmentTree {
public:
    int n;
    vector<pair<int, int>> data;

    SegmentTree(int n) : n(n) {
        data.assign(2*n, {numeric_limits<int>::max(), 0});
    }

    void update(int left, int right, int fight, int winner) {
        left += n;
        right += n;

        while (left < right) {
            if (left & 1) data[left++] = {fight, winner};
            if (right & 1) data[--right] = {fight, winner};
            left >>= 1;
            right >>= 1;
        }
    }

    int query(int idx) {
        idx += n;
        auto m = data[idx];

        while (idx > 1) {
            idx >>= 1;
            m = min(m, data[idx]);
        }

        return m.second;
    }   
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    vector<Fight> fights(m);
    for (int i = 0; i < m; i++) {
        cin >> fights[i].l >> fights[i].r >> fights[i].x;
    }

    SegmentTree st(n);
    for (int i = m-1; i >= 0; i--) {
        st.update(fights[i].l-1, fights[i].x-1, i, fights[i].x);
        st.update(fights[i].x, fights[i].r, i, fights[i].x);
    }

    for (int i = 0; i < n; i++) {
        cout << st.query(i) << ' ';
    }
    cout << endl;

    return 0;
}