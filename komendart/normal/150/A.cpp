#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> primes;
    int t = n;
    for (int i = 2; i * i <= t; ++i) {
        while (t % i == 0) {
            t /= i;
            primes.push_back(i);
        }
    }
    if (t > 1) {
        primes.push_back(t);
    }

    if (primes.size() <= 1) {
        cout << "1\n0\n";
        return 0;
    }
    if (primes.size() == 2) {
        cout << "2\n";
        return 0;
    }
    cout << "1\n";
    cout << primes[0] * primes[1] << '\n';
}