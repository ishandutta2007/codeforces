using namespace std;

#include "bits/stdc++.h"

struct PrefixSum {
    long long sum, prefix_sum;

    PrefixSum operator+(PrefixSum const& other) {
        return {sum + other.sum,
                std::max(prefix_sum, sum + other.prefix_sum)};
    }
};

class MaxPrefixSegmentTree {
public:
    MaxPrefixSegmentTree(int count) {
        n = count;
        prefix_sums.assign(2 * count, {0, 0});
    }

    void update(int idx, int add) {
        idx += n;
        int old_value = prefix_sums[idx].sum;
        int new_value = old_value + add;
        prefix_sums[idx] = {new_value, std::max(0, new_value)};
        while (idx > 1) {
            idx /= 2;
            prefix_sums[idx] = prefix_sums[2 * idx] + prefix_sums[2 * idx + 1];
        }
    }

    long long maximum(int left, int right) {  // interval [left, right)
        left += n;
        right += n;

        vector<PrefixSum> from_left, from_right;
        while (left < right) {
            if (left & 1)
                from_left.push_back(prefix_sums[left++]);
            if (right & 1)
                from_right.push_back(prefix_sums[--right]);
            left >>= 1;
            right >>= 1;
        }

        while (!from_right.empty()) {
            from_left.push_back(from_right.back());
            from_right.pop_back();
        }
        long long best = 0;
        PrefixSum cur{0, 0};
        for (auto const& ps : from_left) {
            cur = cur + ps;
            best = max(best, cur.prefix_sum);
        }
        return best;
    }

private:
    int n;
    std::vector<PrefixSum> prefix_sums;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    auto st = MaxPrefixSegmentTree(2*n);
    for (int i = 0; i < 2*n; i++) {
        st.update(i, -1);
    }

    set<pair<int, int>> s;
    map<int, int> rows;
    for (int i = 0; i < m; i++) {
        int col, row;
        cin >> col >> row;
        int idx = row + abs(col - k);
        auto pr = pair(col, row);
        if (s.count(pr)) {
            st.update(2*n-idx, -1);
            s.erase(pr);
            rows[idx]--;
            if (rows[idx] == 0)
                rows.erase(idx);
        } else {
            st.update(2*n-idx, 1);
            s.insert(pr);
            rows[idx]++;
        }
        int fixed_rows = rows.empty() ? n : max(n, rows.rbegin()->first);
        int start = 2*n - fixed_rows;
        cout << fixed_rows - n + st.maximum(start, 2*n) << '\n';
    }
}