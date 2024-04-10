#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    SegmentTree(int count) {
        n = count;
        data.assign(2 * n, 0);
    }

    void update(int idx, int value) {
        idx += n;
        data[idx] = value;

        while (idx > 1) {
            idx /= 2;
            data[idx] = std::max(data[2 * idx], data[2 * idx + 1]);
        }
    }

    int maximum(int left, int right) { // interval [left, right)
        int ret = 0;
        left += n;
        right += n;

        while (left < right) {
            if (left & 1) ret = std::max(ret, data[left++]);
            if (right & 1) ret = std::max(ret, data[--right]);
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

private:
    int n;
    std::vector<int> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    SegmentTree st(n + 1);
    st.update(0, 1);
    for (int i = 0; i < n; i++) {
        int l_idx = lower_bound(a.begin(), a.end(), a[i] - d) - a.begin();
        int r = st.maximum(l_idx, i + 1 - k + 1);
        st.update(i + 1, r);
    }
    cout << (st.maximum(n, n+1) ? "YES" : "NO") << '\n';
    
}