#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

long long power(long long base, long long e)
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

    long long n, m, k;
    cin >> n >> m >> k;
    if (k == -1 && n % 2 != m % 2) {
        cout << 0 << endl;
        return 0;
    }
    cout << power(power(2, n-1), m-1) << endl;
}