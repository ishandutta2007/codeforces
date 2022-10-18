#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long a, int e, int mod) {
    long long result = 1;
    while (e) {
        if (e & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        e >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    long long prod = 1;
    long long count = 0;
    long long nr = 1;


    for (int i = 0; i < n; i++) {
        count++;
        if (i == n-1 || v[i] != v[i+1]) {
            prod = power(prod, count + 1, MOD);
            long long p = ((1 + count) * count / 2) % (MOD - 1);
            p = (p * nr) % (MOD - 1);
            long long t = power(v[i], p, MOD);
            prod = (prod * t) % MOD;
            nr = (nr * (count + 1)) % (MOD - 1);
            count = 0;
        }
    }

    cout << prod << endl;

    return 0;
}