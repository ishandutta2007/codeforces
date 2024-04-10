#include <bits/stdc++.h>
using namespace std;

long long f(long long n) {
    long long res = 0;
    for (long long i = 2; i*i*i <= n; i++) {
        res += n / (i * i * i);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long m;
    cin >> m;

    long long L = 1;
    long long R = 1e16;

    while (L + 1 < R) {
        long long M = (L + R) / 2;
        if (f(M) < m) L = M;
        else R = M;
    }

    if (f(R) == m) {
        cout << R << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}