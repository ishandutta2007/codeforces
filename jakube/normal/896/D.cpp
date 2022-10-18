#include <bits/stdc++.h>
using namespace std;

long long power(long long base, int e, long long MOD)
{
    long long result = 1;
    base %= MOD;
    while (e) {
        if (e & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return result;
}

class CRT
{
public:
    void add_congruence(long long a, long long m, long long mi) {
        congruences.emplace_back(a, m, mi);
    }

    long long get_unique_solution() {
        long long M = 1;
        for (const auto& p : congruences) {
            M *= get<1>(p);
        }

        long long solution = 0;
        for (const auto& p : congruences) {
            auto a = get<0>(p);
            auto m = get<1>(p);
            auto mi = get<2>(p);
            auto b = M / m;
            solution = (solution + a * b % M * power(b, mi - 1, m)) % M;
        }
        return solution;
    }

    std::vector<std::tuple<long long, long long, long long>> congruences;
};

vector<pair<int, int>> primes;
vector<vector<long long>> product;
vector<vector<int>> cnts;

tuple<long long, long long, long long> C(int n, int k, int i) {
    long long MOD = power(primes[i].first, primes[i].second, std::numeric_limits<long long>::max());
    auto mi = MOD;
    mi /= primes[i].first;
    mi *= primes[i].first - 1;
    long long prod = product[i][n];
    prod = (prod * power(product[i][k], mi - 1, MOD)) % MOD;
    prod = (prod * power(product[i][n - k], mi - 1, MOD)) % MOD;
    int cnt = cnts[i][n] - cnts[i][k] - cnts[i][n-k];
    prod = (prod * power(primes[i].first, cnt, MOD)) % MOD;
    return {prod, MOD, mi};
}

long long C_normal(int n, int k) {
    if (k < 0 || k > n)
        return 0;

    if (k == n || k == 0)
        return 1;
    return C_normal(n-1, k-1) + C_normal(n-1, k);
}

long long C_total(int n, int k) {
    if (k < 0 || k > n)
        return 0;

    CRT crt;
    for (int i = 0; i < (int)primes.size(); i++) {
        auto p = C(n, k, i);
        crt.add_congruence(get<0>(p), get<1>(p), get<2>(p));
    }
    auto res = crt.get_unique_solution();
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p, l, r;
    cin >> n >> p >> l >> r;

    long long P = p;
    for (long long i = 2; i*i <= p; i++) {
        if (P % i == 0) {
            int cnt = 0;
            while (P % i == 0) {
                cnt++;
                P /= i;
            }
            primes.push_back({i, cnt});
        }
    }
    if (P > 1)
        primes.push_back({P, 1});

    product.assign(primes.size(), vector<long long>(n + 1, 1));
    cnts.assign(primes.size(), vector<int>(n + 1, 0));
    for (int i = 0; i < (int)primes.size(); i++) {
        int MOD = 1;
        for (int j = 0; j < primes[i].second; j++) {
            MOD *= primes[i].first;
        }
        long long prod = 1;
        int cnt = 0;
        for (int j = 1; j < n + 1; j++) {
            int g = j;
            while (g % primes[i].first == 0) {
                g /= primes[i].first;
                cnt++;
            }
            prod = (prod * g) % MOD;
            product[i][j] = prod;
            cnts[i][j] = cnt;
        }
    }

    long long res = 0;
    for (int i = 0; i <= n; i++) {
        auto N = n - i;
        auto R = r;
        auto L = l;
        if (N % 2 != L % 2)
            L++;
        if (N % 2 != R % 2)
            R--;
        if (L > R)
            continue;
        auto a = C_total(N, N/2 - L/2);
        auto b = C_total(N, N/2 - R/2 - 1);
        auto c = C_total(n, i);
        res = (res + (a - b + p) % p * c) % p;
    }
    cout << res << endl;
}
// gerade: n
// gerade: r
//              C(n, r) 
//              x + x + r = n
//              x = (n - r) / 2 // negatives
//              C(n, (n - r) / 2) - C(n, (n - r) / 2 - 1) 
// gerade: r - 2
//              C(n, (n - r) / 2 + 1) - C(n, (n - r) / 2)
// ...
//
// gerade l:
//              C(n, (n - l) / 2) - C(n, (n - l) / 2 - 1) 
//
// total:
//              C(n, (n - l) / 2) - C(n, (n - r) / 2 - 1)

// ungerade: r
//              C(n, r) 
//              x + x + r = n
//              x = n/2 - r/2 // negatives
//              p = (n - r) / 2 + + r
//              C(n, (n - r) / 2) - C(n, (n - r) / 2 - 1) 
//              => r-1
//              
// ungerade: n
// 5   1 => 2/3
//