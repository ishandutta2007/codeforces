#include <bits/stdc++.h>
using namespace std;


int MOD = 1e9 + 7;

long long power(long long base, int e, int M=MOD)
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

long long inverse(long long x) {
    return power(x, MOD - 2);
}

long long k, pa, pb;
long long pma;
long long pmb;
long long pmai;
long long pmbi;

map<pair<int, int>, long long> dp;

long long f(int cur_as, int cur_pairs) {
    auto pa = make_pair(cur_as, cur_pairs);
    if (dp.count(pa)) {
        return dp[pa];
    }

    if (cur_pairs + cur_as >= k) {
         // one more b and this is enough
         return dp[pa] = ((cur_pairs + cur_as + pma * pmbi) % MOD);
    } else {
        long long sum = 0;
        sum += pma * f(cur_as + 1, cur_pairs);
        sum += pmb * f(cur_as, cur_pairs + cur_as);
        return dp[pa] = (sum % MOD);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> pa >> pb;
    pma = (pa * inverse(pa + pb)) % MOD;
    pmb = (pb * inverse(pa + pb)) % MOD;
    pmai = inverse(pma);
    pmbi = inverse(pmb);

    long long x = pma * f(1, 0) % MOD;
    x = x * pmai % MOD;
    cout << x << endl;
}