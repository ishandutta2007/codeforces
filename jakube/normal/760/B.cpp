#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n, m, k;
    cin >> n >> m >> k;
    
    long long L = 1;
    long long R = m + 1;

    while (L + 1 < R) {
        long long M = (L + R) / 2;

        long long cnt = 0;
        
        // left
        if (M >= k) {
            cnt += (M + M - k + 1) * k / 2;
        } else {
            cnt += (M + 1) * M / 2;
            cnt += k - M;
        }

        // right
        long long K = n - k + 1;
        if (M >= K) {
            cnt += (M - 1 + M - K + 1) * (K - 1) / 2;
        } else {
            cnt += (M - 1 + 1) * (M - 1) / 2;
            cnt += K - M;
        }

        if (cnt <= m) {
            L = M;
        } else {
            R = M;
        }
    }

    cout << L << endl;

    return 0;
}