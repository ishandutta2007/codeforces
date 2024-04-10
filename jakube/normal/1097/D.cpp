#include <bits/stdc++.h>
using namespace std;

std::vector<int> compute_primes(int n) {
    const int S = 30000;
    int nsqrt = std::round(std::sqrt(n));

    std::vector<char> is_prime(nsqrt + 1, true);
    std::vector<int> primes, sieve_primes, start_indices;
    for (int i = 3; i <= nsqrt; i += 2) {
        if (is_prime[i]) {
            sieve_primes.push_back(i);
            start_indices.push_back((i * i - 1) / 2);
            for (int j = i * i; j <= nsqrt; j += 2 * i)
                is_prime[j] = false;
        }
    }

    primes.push_back(2);
    std::vector<char> block(S);
    int high = (n - 1) / 2;
    for (int low = 0; low <= high; low += S) {
        fill(block.begin(), block.end(), true);
        for (auto i = 0u; i < sieve_primes.size(); i++) {
            int p = sieve_primes[i];
            int idx = start_indices[i];
            for (; idx < S; idx += p)
                block[idx] = false;
            start_indices[i] = idx - S;
        }
        if (low == 0)
            block[0] = false;
        for (int i = 0; i < S && low + i <= high; i++) {
            if (block[i])
                primes.push_back((low + i) * 2 + 1);
        }
    };

    return primes;
}

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

std::vector<int> largest;

void computePrimesLargest(int n) {
    largest.resize(n + 1);
    std::iota(largest.begin(), largest.end(), 0);

    for (int i = 2; i <= n; i++) {
        if (i == largest[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                largest[j] = i;
            }
        }
    }
}

std::vector<long long> divisors(long long x, vector<long long> primes) {
    std::vector<long long> d;
    d.push_back(1);

    for (long long p : primes) {
        int c = 0;
        while (x % p == 0) {
            c++;
            x /= p;
        }
        std::vector<long long> d2;
        long long b = 1;
        for (int j = 0; j <= c; j++) {
            for (long long x : d) {
                d2.push_back(x * b);
            }
            b *= p;
        }
        d.swap(d2);
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto primes = compute_primes(40'000'000);
    long long n;
    long long N;
    int k = 0;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    N = n;
    vector<pair<long long, int>> primes2;
    for (int p : primes) {
        if (n % p == 0) {
            primes2.push_back({p, 1});
            n /= p;
            while (n % p == 0) {
                n /= p;
                primes2.back().second++;
            }
        }
    }
    if (n > 1) {
        primes2.emplace_back(n, 1);
    }

    ModInt result = 1;
    for (auto [p, c] : primes2) {
        vector<vector<ModInt>> dp(k + 1, vector<ModInt>(c + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= c; i++) {
            dp[0][i] = dp[0][i-1] * p;
        }
        for (int K = 1; K <= k; K++) {
            ModInt sum = 0;
            for (int i = 0; i <= c; i++) {
                sum += dp[K-1][i];
                dp[K][i] = sum / (i + 1);
            }
        }
        result *= dp.back().back();
    }
    
    cout << result << '\n';
}