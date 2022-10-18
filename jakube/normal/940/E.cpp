#include <bits/stdc++.h>
using namespace std;

class SparseTable
{
public:
    SparseTable(std::vector<int> v)
    {
        log_table.assign(v.size() + 1, 0);
        for (auto i = 2UL; i < log_table.size(); i++)
            log_table[i] = log_table[i / 2] + 1;

        sparse_table.assign(log_table.back() + 1, std::vector<int>(v.size()));
        sparse_table[0] = v;
        for (auto row = 1UL; row < sparse_table.size(); row++) {
            for (auto i = 0UL; i + (1 << row) <= v.size(); i++) {
                sparse_table[row][i] =
                    std::min(sparse_table[row - 1][i],
                             sparse_table[row - 1][i + (1 << (row - 1))]);
            }
        }
    }

    int minimum(int l, int r)
    {
        int log = log_table[r - l];
        return std::min(sparse_table[log][l],
                        sparse_table[log][r - (1 << log)]);
    }

private:
    std::vector<int> log_table;
    std::vector<std::vector<int>> sparse_table;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (c == 1) {
        cout << 0 << endl;
        return 0;
    }

    SparseTable st(a);
    vector<long long> psum(a.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < a.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + a[psum_idx];
    }

    vector<long long> dp(n+1, 0);
    for (int i = 0; i < n; i++) {
        // pick one
        dp[i+1] = dp[i] + a[i];

        // or c
        if (i >= c - 1) {
            dp[i+1] = min(dp[i+1], dp[i+1-c] + psum[i+1] - psum[i+1-c] - st.minimum(i-c+1, i+1));
        }
    }
    cout << dp.back() << endl;
}