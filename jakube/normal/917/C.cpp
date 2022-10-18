#include <bits/stdc++.h>
using namespace std;

auto INF = std::numeric_limits<long long>::max() / 3;

template <typename T>
class Matrix : public vector<vector<T>> {
public:
    Matrix(int n, int m, T init) 
        : vector<vector<T>>(n, vector<T>(m, init)) {}
};

template <typename T>
vector<T> operator*(vector<T> const& v, Matrix<T> const& M) {
    auto res = v;
    for (int i = 0; i < (int)res.size(); i++) {
        auto cost = INF;
        for (int j = 0; j < (int)res.size(); j++)
            cost = min(cost, v[j] + M[j][i]);
        res[i] = cost;
    }
    return res;
}

template <typename T>
Matrix<T> operator*(Matrix<T> const& A, Matrix<T> const& B) {
    auto res = A;
    for (int i = 0; i < (int)res.size(); i++)
        res[i] = A[i] * B;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, k, n, q;
    cin >> x >> k >> n >> q;
    vector<int> c(k);
    for (int i = 0; i < k; i++)
        cin >> c[i];
    vector<pair<int, int>> special(q);
    for (int i = 0; i < q; i++)
        cin >> special[i].first >> special[i].second;
    sort(special.begin(), special.end());

    // precomputation
    vector<int> possible_patterns;
    vector<int> to_index(1 << k);
    for (int i = 0; i < (1<<k); i++) {
        if (__builtin_popcount(i) == x) {
            possible_patterns.push_back(i);
            to_index[i] = possible_patterns.size() - 1;
        }
    }

    int m = possible_patterns.size();
    Matrix transition(m, m, INF);
    Matrix last_bit(m, m, -1);
    auto store = [&](int p, int q, int c, int lb=-1) {
        p = to_index[p];
        q = to_index[q];
        transition[p][q] = c;
        last_bit[p][q] = lb;
    };
    for (int pattern : possible_patterns) {
        if ((pattern & 1) == 0)
            store(pattern, pattern >> 1, 0);
        int smallest = 0;
        while ((pattern & (1 << smallest)) == 0)
            smallest++;
        for (int i = 1; i + smallest <= k; i++) {
            if ((pattern & (1 << (i + smallest))) == 0) {
                int new_p = (pattern ^ (1 << (i + smallest)) ^ (1 << smallest)) >> 1;
                store(pattern, new_p, c[i-1], i + smallest - 1);
            }
        }
    }

    // functions for applying moves
    auto apply_once = [&](int i, auto dp) {
        vector dp2(m, INF);
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {
                auto cost = dp[a] + transition[a][b];
                for (auto [p, w] : special) {
                    if (last_bit[a][b] >= 0 && last_bit[a][b] + i == p)
                        cost += w;
                }
                dp2[b] = min(dp2[b], cost);
            }
        }
        return dp2;
    };
    auto apply_slow = [&](int from, int to, auto dp) {
        for (int i = from; i <= to; i++)
            dp = apply_once(i, dp);
        return dp;
    };
    auto apply_fast = [transition](int from, int to, auto dp) {
        int how_often = to - from + 1;
        auto matrix = transition;
        while (how_often > 0) {
            if (how_often & 1)
                dp = dp * matrix;
            matrix = matrix * matrix;
            how_often >>= 1;
        }
        return dp;
    };

    // solve
    vector dp(m, INF);
    dp[to_index[(1 << x) - 1]] = 0;
    int index = 1;
    for (auto [p, _] : special) {
        dp = apply_fast(index + 1, p - k, dp);
        index = max(index, p - k);
        int to = min(p, n - x + 1);
        dp = apply_slow(index + 1, to, dp);
        index = to;
    }
    dp = apply_fast(index + 1, n - x + 1, dp);
    cout << dp[0] << endl;
}