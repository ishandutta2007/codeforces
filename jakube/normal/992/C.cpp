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

using ModInt = Modular<1'000'000'007>;


template <typename T>
class Matrix : public std::vector<std::vector<T>> {
public:
    Matrix(int n, int m, T init=0) 
        : std::vector<std::vector<T>>(n, std::vector<T>(m, init)) {}
};

template <typename T>
std::vector<T> operator*(std::vector<T> const& v, Matrix<T> const& M) {
    std::vector<T> res(v.size(), 0);
    for (int i = 0; i < (int)res.size(); i++) {
        for (int j = 0; j < (int)res.size(); j++)
            res[i] += v[j] * M[j][i];
    }
    return res;
}

template <typename T>
std::vector<T> operator*(Matrix<T> const& M, std::vector<T> const& v) {
    std::vector<T> res(M.size(), 0);
    for (int i = 0; i < (int)res.size(); i++) {
        for (int j = 0; j < (int)v.size(); j++)
            res[i] += M[i][j] * v[j];
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

template <typename T>
Matrix<T> operator+(Matrix<T> const& A, Matrix<T> const& B) {
    auto res = A;
    for (int i = 0; i < (int)res.size(); i++) {
        for (int j = 0; j < (int)res[0].size(); j++) {
            res[i][j] += B[i][j];
        }
    }
    return res;
}

using M = Matrix<ModInt>;

M power(M base, long long e)
{
    M result(2, 2, 0);
    result[0][0] = 1;
    result[1][1] = 1;
    while (e) {
        if (e & 1)
            result = result * base;
        base = base * base;
        e >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, k;
    cin >> x >> k;
    if (x == 0) {
        cout << 0 << endl;
        return 0;
    }

    M m(2, 2, 0);
    m[0][0] = 2;
    m[1][0] = ModInt(-1) / ModInt(2);
    m[1][1] = 1;

    vector<ModInt> v = { x, 1 };
    auto res = v * power(m, k);
    cout << res[0]*2 << endl;
}