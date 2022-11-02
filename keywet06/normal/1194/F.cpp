#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;

struct modint {
    int val;

    modint(long long v = 0) {
        if (v < 0) v = v % P + P;
        if (v >= P) v %= P;
        val = v;
    }

    static int inv(int a, int m = P) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r;
            swap(g, r);
            x -= q * y;
            swap(x, y);
        }
        return x < 0 ? x + m : x;
    }

    explicit operator int() const { return val; }

    modint &operator+=(const modint &other) {
        val += other.val;
        if (val >= P) val -= P;
        return *this;
    }

    modint &operator-=(const modint &other) {
        val -= other.val;
        if (val < 0) val += P;
        return *this;
    }

    modint &operator*=(const modint &other) {
        val = (uint64_t)val * other.val % P;
        return *this;
    }

    modint &operator/=(const modint &other) { return *this *= other.inv(); }

    friend modint operator+(const modint &a, const modint &b) {
        return modint(a) += b;
    }

    friend modint operator-(const modint &a, const modint &b) {
        return modint(a) -= b;
    }

    friend modint operator*(const modint &a, const modint &b) {
        return modint(a) *= b;
    }

    friend modint operator/(const modint &a, const modint &b) {
        return modint(a) /= b;
    }

    modint &operator++() {
        val = val == P - 1 ? 0 : val + 1;
        return *this;
    }

    modint operator++(int) {
        modint before = *this;
        ++*this;
        return before;
    }

    modint &operator--() {
        val = val == 0 ? P - 1 : val - 1;
        return *this;
    }

    modint operator--(int) {
        modint before = *this;
        --*this;
        return before;
    }

    modint operator-() const { return val == 0 ? 0 : P - val; }

    bool operator==(const modint &other) const { return val == other.val; }

    bool operator!=(const modint &other) const { return val != other.val; }

    modint inv() const { return inv(val); }

    modint pow(long long p) const {
        assert(p >= 0);
        modint a = *this, result = 1;
        while (p > 0) {
            if (p & 1) result *= a;
            a *= a, p >>= 1;
        }
        return result;
    }
};

vector<modint> factorial, inv_factorial;
vector<modint> inv;

void prepare_factorials(int max) {
    inv.assign(max + 1, 1);
    for (int p = 2; p * p <= P; p++) assert(P % p != 0);
    for (int i = 2; i <= max; i++) inv[i] = inv[P % i] * (P - P / i);
    factorial.resize(max + 1);
    inv_factorial.resize(max + 1);
    factorial[0] = inv_factorial[0] = 1;
    for (int i = 1; i <= max; i++) {
        factorial[i] = i * factorial[i - 1];
        inv_factorial[i] = inv[i] * inv_factorial[i - 1];
    }
}

modint choose(int n, int r) {
    if (r < 0 || r > n) return 0;
    return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}

const modint U = modint(1) / modint(2);

long long N, T;

vector<long long> crosswords;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> T;
    prepare_factorials(N + 5);
    crosswords.resize(N);
    for (long long &cw : crosswords) cin >> cw;
    modint total = 0;
    long long sum = 0;
    modint pow2 = 1;
    for (long long i = 0; i < N; ++i) {
        sum += crosswords[i];
        if (sum > T) break;
        long long max_x = min(T - sum, i + 1);
        long long min_x =
            max(i < N - 1 ? T - sum - crosswords[i + 1] + 1 : 0, 0LL);
        modint here = 0;
        for (long long x = min_x; x <= max_x; ++x) here += choose(i + 1, x);
        if (min_x > 0 && min_x - 1 <= max_x)
            here += U * choose(i + 1, min_x - 1);
        pow2 *= U;
        total += here * pow2 * modint(i + 1);
    }
    cout << (int)total << '\n';
    return 0;
}