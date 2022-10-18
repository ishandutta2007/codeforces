#include <bits/stdc++.h>
using namespace std;


class SegmentTree {
public:
    SegmentTree(std::vector<int> const &values) {
        n = values.size();
        data.resize(2 * n);
        std::copy(values.begin(), values.end(), &data[0] + n);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = std::max(data[idx * 2], data[idx * 2 + 1]);
    }

    int maximum(int left, int right) { // interval [left, right)
        if (left >= right)
            return 0;

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
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> animals(n, vector<int>(m, 0));
    for (auto& row : animals) {
        for (auto& elem : row) {
            cin >> elem;
        }
    }
    animals.push_back(vector<int>(m, 0));
    n++;
    // animals.insert(animals.begin(), vector<int>(m, 0));
    // animals.insert(animals.begin(), vector<int>(m, 0));
    // n += 2;

    int num_pos = m - k + 1;

    vector<vector<int>> animals_sums(n, vector<int>(num_pos, 0));
    for (int i = 0; i < n; i++) {
        auto& cur = animals[i];
        auto& cur_sums = animals_sums[i];

        int sum = accumulate(cur.begin(), cur.begin() + k, 0);
        cur_sums[0] = sum;
        for (int j = k; j < m; j++) {
            sum += cur[j] - cur[j-k];
            cur_sums[j-k+1] = sum;
        }
    }

    vector<int> dp(num_pos, 0);
    // row 0
    for (int j = 0; j < num_pos; j++) {
        dp[j] = animals_sums[0][j] + animals_sums[1][j];
    }

    for (int i = 1; i < n - 1; i++) {
        // choose camera in row i
        vector<int> dp2(num_pos, 0);

        SegmentTree st(dp);
        for (int cur = 0; cur < num_pos; cur++) {
            int cur_block = animals_sums[i][cur] + animals_sums[i+1][cur];
            int& best = dp2[cur];
            // no overlap, before
            best = max(best, cur_block + st.maximum(0, cur - k + 1));
            // no overlap, after
            best = max(best, cur_block + st.maximum(cur + k, num_pos));
            // overlap 1
            int overlap = 0;
            for (int prev = cur - k + 1; prev <= cur; prev++) {
                overlap += animals[i][prev+k-1];
                if (prev >= 0)
                    best = max(best, cur_block + dp[prev] - overlap);
            }
            // overlap 2
            for (int prev = cur + 1; prev < min(num_pos, cur + k); prev++) {
                overlap -= animals[i][prev-1];
                best = max(best, cur_block + dp[prev] - overlap);
            }
        }


        dp = dp2;
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}