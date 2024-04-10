#include <bits/stdc++.h>
using namespace std;

int digits(long long x) {
    int c = 0;
    while (x) {
        x /= 10;
        c++;
    }
    return c;
}

int divisions(long long x, int d) {
    int c = 0;
    while (x % d == 0) {
        c++;
        x /= d;
    }
    return c;
}

string form_expression(int d, int C, string y) {
    stringstream ss;
    ss << d;
    if (C > 1)
        ss << "^" << C;
    if (!y.empty())
        ss << "*" << y;
    return ss.str();
}

string expr1(long long x) {
    stringstream ss;
    ss << x;
    return ss.str();
}

std::vector<int> primes;

std::vector<long long> divisors(long long x) {
    std::vector<long long> d;
    d.push_back(1);

    for (long long p : primes) {
        if (p * p > x)
            break;

        int c = 0;
        while (x % p == 0) {
            c++;
            x /= p;
        }
        if (c) {
            int n = d.size();
            long long b = 1;
            for (int j = 1; j <= c / 2; j++) {
                b *= p;
                for (int i = 0; i < n; i++) {
                    d.push_back(d[i] * b);
                }
            }
        }
    }
    if (x > 1) {
        int n = d.size();
        for (int i = 0; i < n; i++) {
            d.push_back(d[i] * x);
        }
    }

    return d;
}

std::vector<int> compute_primes(int n)
{
    std::vector<bool> m(n + 1, false);

    int root = std::sqrt(n) + 1;
    for (int i = 1; i <= root; i++) {
        for (int j = 1; j <= root; j++) {
            int a = 4 * i * i + j * j;
            int b = 3 * i * i + j * j;
            int c = 3 * i * i - j * j;

            if (a <= n && (a % 12 == 1 || a % 12 == 5))
                m[a].flip();
            if (b <= n && b % 12 == 7)
                m[b].flip();
            if (i > j && c <= n && c % 12 == 11)
                m[c].flip();
        }
    }

    for (int i = 5; i * i <= n; i++) {
        if (m[i]) {
            for (int j = 1; j * i * i <= n; j++)
                m[j * i * i] = false;
        }
    }

    std::vector<int> primes = {2, 3};
    for (int i = 5; i < n; i++) {
        if (m[i])
            primes.push_back(i);
    }
    return primes;
}

string mult(long long x, int maxlen) {
    string best = expr1(x);
    if (maxlen < 1)
        return best;
    if (x > 9 && maxlen < 2)
        return best;
    if (x > 99 && maxlen < 3)
        return best;

    vector<pair<long long, int>> factors;
    for (long long d : divisors(x)) {
        if (d == 1 || d == x) continue;
        int c = divisions(x, d);
        int length = digits(d);
        if (length + 2 > min(maxlen, (int)best.size() - 1))
            return best;
        long long X = x / d;
        for (int C = 2; C <= c; C++) {
            X /= d;
            int l = length + 2 + (C > 9);
            string y;
            if (X > 1) {
                l++;
                int rem_maxlen = min(maxlen, (int)best.size() - 1) - l;
                y = mult(X, rem_maxlen);
                l += y.size();
            }
            if (l < (int)best.size())
                best = form_expression(d, C, y);
        }
    }

    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    primes = compute_primes(100'000);
    
    // 0 plus
    auto s = mult(n, digits(n) - 1);

    // 1 plus
    for (int i = 1; i <= 10000; i++) {
        stringstream ss;
        ss << mult(n - i, s.size() - 1 - digits(i) - 1) << "+" << i;
        auto t = ss.str();
        if (t.size() < s.size())
            s = t;
        long long x = i;
        int ma = x < 100 ? (x < 10 ? 100 : 10) : 2;
        for (int c = 2; c < ma; c++) {
            x *= i;
            if (x > n)
                break;
            stringstream ss;
            ss << mult(n - x, s.size() - 1- digits(i) - 1 - 1 - digits(c)) << "+" << i << "^" << c;
            auto t = ss.str();
            if (t.size() < s.size())
                s = t;
        }
    }

    cout << s << '\n';
}