#include <bits/stdc++.h>
using namespace std;

int MOD = 1'000'000'007;

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

auto inverse(long long x) {
    return power(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    long long f = 1;
    for (int i = 1; i <= n; i++) {
        f = (f * i) % MOD;
    }

    long long result = 0;
    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] > a[i-1])
            p[i] = n - i - 1;
        else
            p[i] = p[i-1];

        if (a[i] != a.back())
            result += f * inverse(p[i] + 1) % MOD * a[i] % MOD;
    }

    cout << (result % MOD) << endl;

}