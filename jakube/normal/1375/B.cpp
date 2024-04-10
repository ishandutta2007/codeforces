#include "bits/stdc++.h"
using namespace std;

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v)
        is >> x;
    return is;
}

// using ModInt = Modular<1'000'000'007>;

template <typename T>
class Matrix : public std::vector<T> {
public:
    Matrix(int rows, int columns, T init = 0)
        : std::vector<T>(rows * columns, init), rows(rows), columns(columns) { }
    
    
    int get_idx(int row, int column) const {
        return row * columns + column;
    }
    T& get(int row, int column) {
        return (*this)[get_idx(row, column)];
    }
    
    int rows, columns;
};

void solve() {
    int n, m;
    cin >> n >> m;
    Matrix<int> M(n, m);
    cin >> M;

    bool possible = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int neighbors = 0;
            if (i > 0)
                neighbors++;
            if (j > 0)
                neighbors++;
            if (i < n - 1)
                neighbors++;
            if (j < m - 1)
                neighbors++;
            possible &= M.get(i, j) <= neighbors;
            M.get(i, j) = neighbors;
        }
    }
    if (possible) {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << M.get(i, j) << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}