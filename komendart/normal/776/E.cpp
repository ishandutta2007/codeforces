#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxw = 2e6 + 5;
const int MOD = 1e9 + 7;

vector<int> primes;

void precalc() {
    vector<int> good(maxw, true);
    primes.reserve(maxw / 10);
    for (int i = 2; i < maxw; ++i) {
        if (!good[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j < maxw; j += i) {
            good[j] = false;
        }
    }
}

int f(int n) {
    if (n <= 2) return 1;
    int ans = n;
    for (auto p: primes) {
        if (p * p > n) break;
        if (n % p != 0) continue;
        ans /= p;
        ans *= p - 1;
        while (n % p == 0) n /= p;
    }
    if (n > 1) {
        ans /= n;
        ans *= n - 1;
    }
    return ans;
}

int calc(const vector< pair<int, int> > &div, int i, int phi) {
    if (i == div.size()) {
        return phi;
    }
    int ans = calc(div, i + 1, phi);
    int p, k;
    tie(p, k) = div[i];
    phi *= p - 1;
    for (int j = 1; j <= k; ++j) {
        ans += calc(div, i + 1, phi);
        phi *= p;
    }
    return ans;
}

int g(int n) {
    vector< pair<int, int> > div;
    for (auto p: primes) {
        if (p * p > n) break;
        int k = 0;
        while (n % p == 0) {
            n /= p;
            ++k;
        }
        if (k != 0) div.push_back({p, k});
    }
    if (n > 1) div.push_back({n, 1});
    return calc(div, 0, 1);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    precalc();

    int n, k;
    cin >> n >> k;
    int cur = n;
    for (int i = 0; cur != 1 && i <= k; ++i) {
        if (i % 2 == 0) {
            cur = g(cur);
        } else {
            cur = f(cur);
        }
    }
    cout << cur % MOD << '\n';
}