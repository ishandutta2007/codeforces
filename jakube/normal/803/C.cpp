#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    if (k > 1000000 || k*(k+1)/2 > n) {
        cout << -1 << endl;
        return 0;
    }

    long long d = 1;
    long long K = k * (k+1) / 2;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i >= K)
                d = max(d, i);
            if (i >= K)
                d = max(d, n/i);
        }
    }

    for (int i = 1; i < k; i++) {
        cout << i*d << " ";
        n -= i*d;
    }
    cout << n << endl;
}