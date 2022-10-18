#include <bits/stdc++.h>
using namespace std;

map<long long, int> cnt;

void factorize(long long n) {
    while ((n & 1) == 0) {
        cnt[2]++;
        n >>= 1;
    }

    for (long long d = 3; d * d <= n; d++) {
        while (n % d == 0) {
            cnt[d]++;
            n /= d;
        }
    }

    if (n > 1)
        cnt[n]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n, k;
    cin >> n >> k;

    factorize(n);

    for (int i = 1; i <= k; i++) {
        if (i & 1) {
            vector<long long> to_factor;
            vector<long long> to_erase;
            for (auto& p : cnt) {
                p.second--;
                to_factor.push_back(p.first - 1);
                if (p.second == 0)
                    to_erase.push_back(p.first);
            }
            for (long long val : to_erase)
                cnt.erase(val);
            for (long long val : to_factor)
                factorize(val);
        }

        if (cnt.size() == 0)
            break;
    }

    const int MOD = 1e9 + 7;
    long long result = 1;
    for (auto& p : cnt) {
        for (int i = 0; i < p.second; i++)
            result = (result * p.first) % MOD;
    }

    cout << result << endl;
}