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

using ModInt = Modular<1'000'000'007>;

// class D3 : public vector<vector<vector<ModInt>>> {
// public:
//     D3(int a, int b, int c, int x) :
//         vector<vector<vector<ModInt>>>(a, 
//                 vector<vector<ModInt>>(b, 
//                     vector<ModInt>(c, x)))
//     {}
// };

using VM = vector<ModInt>;
using MM = vector<VM>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int zeros = 0;
    for (auto& x : v) {
        cin >> x;
        zeros += x == 0;
    }
    int ones = n - zeros;

    int g0 = 0;
    for (int i = 0; i < zeros; i++) {
        if (v[i] == 0)
            g0++;
    }

    VM cur(zeros + 1, 0);
    cur[g0] = 1;

    int N = min(zeros, ones);
    MM transition(zeros + 1, VM(zeros + 1, 0));
    ModInt all = ModInt(n * (n-1)) / 2;
    for (int i = 0; i <= zeros; i++) {
        int g0 = i;
        int b0 = zeros - i;
        int g1 = ones - b0;
        int b1 = ones - g1;
        if (b0 < 0 || g1 < 0 || b1 < 0)
            continue;

        ModInt rem = all;
        if (g0) {
            transition[g0][g0 - 1] = g0 * g1;
            rem -= g0 * g1;
        }
        if (g0 < zeros) {
            transition[g0][g0 + 1] = b0 * b1;
            rem -= b0 * b1;
        }
        transition[g0][g0] = rem;
    }
    for (int i = 0; i <= zeros; i++) {
        for (int j = 0; j <= zeros; j++) {
            transition[i][j] /= all;
        }
    }

    while (k) {
        if (k & 1) {
            VM neww(zeros + 1, 0);
            for (int g0 = 0; g0 <= zeros; g0++) {
                for (int g02 = 0; g02 <= zeros; g02++) {
                    neww[g02] += cur[g0] * transition[g0][g02];
                }
            }
            cur = neww;
        }

        // trans * trans
        MM transition2(zeros + 1, VM(zeros + 1, 0));
        for (int i = 0; i <= zeros; i++) {
            for (int j = 0; j <= zeros; j++) {
                for (int l = 0; l <= zeros; l++) {
                    transition2[i][j] += transition[i][l] * transition[l][j];
                }
            }
        }
        transition = transition2;
        k >>= 1;
    }

    
    cout << cur.back() << endl;
}