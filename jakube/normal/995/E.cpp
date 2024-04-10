#include <bits/stdc++.h>
using namespace std;

int MOD;

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

    friend bool operator<(Modular const& a, Modular const& b) {
        return a.value < b.value;
    }
    int value;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int u, v;
    cin >> u >> v >> MOD;
    map<Modular, int> m;
    m[v] = 0;
    for (int i = 0; i < 1'000; i++) {
        Modular cur = v;
        for (int j = 0; j < 100; j++) {
            int op = rand() % 3 + 1;
            auto old = cur;
            if (op == 1)
                cur -= 1;
            if (op == 2)
                cur += 1;
            if (op == 3)
                cur = inverse(cur);
            if (cur != old) {
                if (!m.count(cur))
                    m[cur] = op;
            }
        }
    }

    vector<int> tmp(200);
    while (true) {
        Modular cur = u;
        for (int j = 0; j < 100; j++) {
            int op = rand() % 3 + 1;
            if (op == 1)
                cur += 1;
            if (op == 2)
                cur -= 1;
            if (op == 3)
                cur = inverse(cur);
            tmp[j] = op;
            if (m.count(cur)) {
                while (m[cur]) {
                    j++;
                    op = tmp[j] = m[cur];
                    if (op == 1)
                        cur += 1;
                    if (op == 2)
                        cur -= 1;
                    if (op == 3)
                        cur = inverse(cur);
                }
                cout << j + 1 << '\n';
                for (int i = 0; i <= j; i++) {
                    cout << tmp[i] << ' ';
                }
                cout << endl;
                return 0;
            }
        }
    }
}