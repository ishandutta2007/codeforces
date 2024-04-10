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
        data[idx] = max(data[idx], value);

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

    int n, k, p;
    cin >> n >> k >> p;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= p;
    }

    if (k * p >= n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, std::numeric_limits<int>::max() / 2));
        dp[0][0] = 0;
        for (int K = 1; K <= k; K++) {
            vector<int> f(p, std::numeric_limits<int>::max() / 2);
            for (int i = 1; i <= n; i++) {
                f[0] = min(f[0], dp[K-1][i-1]);
                rotate(f.begin(), f.begin() + (p - v[i-1]) % p, f.end());
                for (int j = 0; j < p; j++)
                    dp[K][i] = min(dp[K][i], f[j] + j);
            }
        }
        cout << dp[k][n] << endl;
    } else {
        vector<int> psum(v.size() + 1, 0);
        for (auto psum_idx = 0u; psum_idx < v.size(); psum_idx++) {
            psum[psum_idx+1] = (psum[psum_idx] + v[psum_idx]) % p;
        }

        SegmentTree st(p);
        for (int i = 0; i < n; i++) {
            int x = st.maximum(0, psum[i+1]+1);
            st.update(psum[i+1], x + 1);
        }
        if (st.maximum(psum.back(), psum.back() + 1) >= k) {
            cout << psum.back() << '\n';
        } else {
            cout << psum.back() + p << '\n';
        }
    }
}