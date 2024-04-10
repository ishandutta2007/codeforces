#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    
    vector<int> c(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> c[idx];
    
    map<int, int> primes;

    int div = 2;
    if (k % div == 0) {
        primes[div] = 1;
        while(k % div == 0) {
            k /= div;
            primes[div] *= div;
        }
    }

    for (div = 3; div*div <= k; div += 2) {
        if (k % div == 0) {
            primes[div] = 1;
            while(k % div == 0) {
                k /= div;
                primes[div] *= div;
            }
        }
    }

    if (k > 1) {
        primes[k] = k;
    }

    for (int ci : c) {
        vector<int> remove;
        for (auto p : primes) {
            if (ci % p.second == 0) {
                remove.push_back(p.first);
            }
        }
        for (auto t : remove)
                primes.erase(t);
    }

    if (primes.size()) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}