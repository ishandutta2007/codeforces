#include <bits/stdc++.h>
using namespace std;

template <int MOD>
class Modular {
public:
    Modular(long long v=0) {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }

    Modular(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular& operator+=(Modular const& b) {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }

    Modular& operator-=(Modular const& b) {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }

    Modular& operator*=(Modular const& b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular power(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }

    friend Modular inverse(Modular a) {
        return power(a, MOD - 2);
    }

    Modular& operator/=(Modular const& b) {
        return *this *= inverse(b);
    }

    friend Modular operator+(Modular a, Modular const b) {
        return a += b;
    }

    friend Modular operator-(Modular a, Modular const b) {
        return a -= b;
    }

    friend Modular operator-(Modular const a) {
        return 0 - a;
    }

    friend Modular operator*(Modular a, Modular const b) {
        return a *= b;
    }

    friend Modular operator/(Modular a, Modular const b) {
        return a /= b;
    }

    friend std::ostream& operator<<(std::ostream &os, Modular const& a) {
        return os << a.value;
    }

    friend bool operator==(Modular const& a, Modular const& b) {
        return a.value == b.value;
    }

    friend bool operator!=(Modular const& a, Modular const& b) {
        return a.value != b.value;
    }

    int value;
    static const int MOD_value = MOD;
};

using ModInt = Modular<998244353>;

std::vector<ModInt> inv;

void precompute_inv(int n) {
    int m = ModInt::MOD_value;
    inv.resize(n+1, 1);
    for (int i = 2; i <= n; i++) {
        inv[i] = -(m / i) * inv[m % i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    precompute_inv(n*m);
    vector<int> all;
    all.reserve(n*m);
    vector<vector<int>> board(n, vector<int>(m));
    for (auto& row : board) {
        for (auto& elem : row) {
            cin >> elem;
            all.push_back(elem);
        }
    }

    sort(all.begin(), all.end());
    auto end = unique(all.begin(), all.end());

    vector<vector<pair<int, int>>> ma(n*m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = board[i][j];
            x = lower_bound(all.begin(), end, x) - all.begin();
            ma[x].push_back({i, j});
        }
    }

    ModInt sq = 0, sum_x = 0, sum_y = 0, total = 0;
    int cnt = 0;

    vector<vector<ModInt>> res(n, vector<ModInt>(m, 0));
    for (auto v : ma) {
        ModInt invv = inv[cnt];
        ModInt sq2 = 0, sum_x2 = 0, sum_y2 = 0, total2 = 0;
        for (auto [i, j] : v) {
            ModInt mi = i;
            ModInt mj = j;
            auto sq3 = mi*mi + mj*mj;
            sq2 += sq3;
            sum_x2 += mi;
            sum_y2 += mj;
            res[i][j] = sq + cnt*sq3 - 2*sum_x*mi - 2*sum_y*mj + total;
            res[i][j] *= invv;
            total2 += res[i][j];
        }
        sq += sq2;
        sum_x += sum_x2;
        sum_y += sum_y2;
        cnt += v.size();
        total += total2;
    }

    int x, y;
    cin >> x >> y;
    cout << res[x-1][y-1] << endl;
}