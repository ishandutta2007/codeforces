#include <bits/stdc++.h>
using namespace std;

using BITSET = bitset<100'001>;

class SegmentTree {
public:
    SegmentTree(int count) {
        n = count;
        data.resize(2 * n);
    }

    void add_query(int elem, int left, int right) { // interval [left, right)
        left += n;
        right += n;

        while (left < right) {
            if (left & 1) data[left++].push_back(elem);
            if (right & 1) data[--right].push_back(elem);
            left >>= 1;
            right >>= 1;
        }
    }

    BITSET push_down() {
        vector<BITSET> bs(2*n, 0);
        BITSET result;
        bs[1][0] = 1;
        for (int i = 1; i < 2*n; i++) {
            for (int x : data[i])
                bs[i] |= bs[i] << x;
            if (i < n) {
                bs[i << 1] = bs[i];
                bs[i << 1 | 1] = bs[i];
            } else {
                result |= bs[i];
            }
        }
        return result;
    }

private:
    int n;
    vector<vector<int>> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int q;
    cin >> q;

    SegmentTree st(n);
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        st.add_query(x, l-1, r);
    }
    auto result = st.push_down();

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += result[i];
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        if (result[i])
            cout << i << ' ';
    }
    cout << '\n';
}