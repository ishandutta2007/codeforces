#include <bits/stdc++.h>
using namespace std;

void computePrimesLargest(int n, std::vector<int> &largest)
{
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

using Fact = array<int, 7>;
using Res = array<long long, 20>;
map<Fact, Res> m2;

int MOD = 1'000'000'007;
std::vector<long long> factorial;

void precompute_factorial(int ma)
{
    factorial.push_back(1);
    for (int i = 1; i <= ma; i++)
        factorial.push_back((factorial.back() * i) % MOD);
}

long long power(long long base, int e)
{
    long long result = 1;
    while (e) {
        if (e & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_factorial(1'000'000);
    vector<long long> inv = factorial;
    for (auto& x : inv) {
        x = power(x, MOD - 2);
    }
    
    vector<int> largest;
    computePrimesLargest(1'000'000, largest);
    vector<Fact> m1(1'000'000 + 1, {{0}});
    for (int i = 1; i <= 1'000'000; i++) {
        auto& t = m1[i];
        int x = i;
        int last_factor = 0;
        int idx = 0;
        while (x > 1) {
            last_factor = largest[x];
            x /= last_factor;
            t[idx]++;
            if (last_factor != largest[x])
                idx++;
        }
        sort(t.begin(), t.end());
    }

    set<Fact> s(m1.begin(), m1.end());
    
    for (const auto& t : m1) {
        if (m2.count(t))
            continue;

        Res res = {{0}};
        if (accumulate(t.begin(), t.end(), 0) == 0) {
            res[0] = 1;
        }

        for (int a0 = 0; a0 <= t[0]; a0++) {
            for (int a1 = 0; a1 <= t[1]; a1++) {
                for (int a2 = 0; a2 <= t[2]; a2++) {
                    for (int a3 = 0; a3 <= t[3]; a3++) {
                        for (int a4 = 0; a4 <= t[4]; a4++) {
                            for (int a5 = 0; a5 <= t[5]; a5++) {
                                for (int a6 = 0; a6 <= t[6]; a6++) {
                                    Fact xx = {{a0, a1, a2, a3, a4, a5, a6}};
                                    sort(xx.begin(), xx.end());
                                    auto tt = m2[xx];
                                    for (int i = 0; i < 19; i++) {
                                        res[i + 1] += tt[i];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        m2[t] = res;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        auto v = m2[m1[x]]; 

        long long total = 0;
        for (int j = 0; j <= min(y, 19); j++) {
            long long res = (((factorial[y] * inv[j]) % MOD) * inv[y - j]) % MOD;
            total += res * v[j];
        }
        total = ((total % MOD) * power(2, y - 1)) % MOD;
        cout << total << '\n';
    }
}