#include <bits/stdc++.h>
using namespace std;

long long power(long long base, int e, int M)
{
    long long result = 1;
    base %= M;
    while (e) {
        if (e & 1)
            result = (result * base) % M;
        base = (base * base) % M;
        e >>= 1;
    }
    return result;
}

auto inverse(long long x, int prime) {
    return power(x, prime - 2, prime);
}

struct Congruence
{
    long long a, m, totient_m;
    Congruence(long long a, long long m, long long t) : a(a), m(m), totient_m(t) {}
};

class CRT
{
public:
    void add_congruence(long long a, long long m, long long totient_m) {
        congruences.emplace_back(a, m, totient_m);
    }

    long long get_unique_solution() {
        long long M = 1;
        for (const auto& c : congruences) {
            M *= c.m;
        }

        long long solution = 0;
        for (const auto& c : congruences) {
            auto b = M / c.m;
            solution = (solution + c.a * b % M * power(b, c.totient_m - 1, c.m)) % M;
        }
        return solution;
    }

    std::vector<Congruence> congruences;
};


int totient(int num)
{
    int res = num;
    for (int div = 2; div * div <= num; div++) {
        if (num % div == 0) {
            res /= div;
            res *= div - 1;
            while (num % div == 0) {
                num /= div;
            }
        }
    }
    if (num > 1) {
        res /= num;
        res *= num - 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, p, x;
    cin >> a >> b >> p >> x;
    long long ans = 0;

    long long ainv = inverse(a, p);
    long long p_1totient = totient(p - 1);
    long long q = p * (p - 1);
    for (int i = 0; i < p - 1; i++) {
        // n % (p-1) == i;
        //n % p == b;
        CRT crt;
        crt.add_congruence(i, p-1, p_1totient);
        crt.add_congruence(b, p, p-1);
        long long u = crt.get_unique_solution();
        // u + q * times <= x
        // (x - u) / q;
        if (u <= x) {
            ans += 1 + (x - u) / q;
        }

        b = (b * ainv) % p;
    }

    cout << ans << '\n';
}