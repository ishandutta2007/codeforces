#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

template <typename T>
class Vector;

template<class IterT>
class StrideIter
{
public:
  using value_type = typename std::iterator_traits<IterT>::value_type;
  using reference = typename std::iterator_traits<IterT>::reference;
  using difference_type = typename std::iterator_traits<IterT>::difference_type;
  StrideIter(IterT x, int step) : m(x), step(step) { }

  reference operator[](const difference_type n) { return m[n * step]; }

private:
  IterT m;
  difference_type step;
};

template <typename IterT>
class VecView {
public:
    using T = typename IterT::value_type;
    VecView(IterT begin_, IterT end_) : begin_(begin_), end_(end_) {}
    T& operator[](int idx) { return begin_[idx]; }

private:
    IterT begin_, end_;

};

template <typename T>
class Vector : public std::vector<T> {
public:
    Vector(int n  = 0, T init = 0) : std::vector<T>(n, init) {}

};

template <typename T>
class Matrix {
public:
    Matrix(int rows, int columns, T init = 0)
        : rows(rows), columns(columns), data(rows * columns, init) { }

    using IterForView = StrideIter<typename std::vector<T>::iterator>;

    VecView<IterForView> row(int row_idx) {
        auto beg = IterForView(data.begin() + row_idx * columns, 1);
        auto end = IterForView(data.begin() + (row_idx + 1) * columns, 1);
        return {beg, end};
    }

    VecView<IterForView> operator[](int row_idx) {
        return row(row_idx);
    }

    int rows, columns;
    Vector<T> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;

    // dp[i..j] =
    auto INF = std::numeric_limits<long long>::max() / 2;
    int people = accumulate(v.begin(), v.end(), 0LL);
    Matrix<long long> dp(n+1, 2 * people + 1, INF);
    int offset = people;
    dp[0][0 + offset] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = -people; j <= people; j++) {
            auto& res = dp[i+1][j+offset];
            if (v[i] == 0) {
                // don't fill it
                res = min(res, dp[i][j+offset] + abs(j));
                // fill it
                res = min(res, dp[i][j+1+offset] + abs(j+1));
            } else {
                res = min(res, dp[i][j-1+offset] + abs(j-1));
            }
        }
    }
    cout << dp[n][0 + offset] << endl;
}