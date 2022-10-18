#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n, m, k;
    cin >> n >> m >> k;
    
    long long left = 0; 
    long long right = n*m;

    while (left + 1 < right) {
        long long M = (left + right) / 2;

        long long cnt = 0;
        for (long long d = 1; d <= M && d <= m; d++) {
            // d * (d / M)
            cnt += min(M / d, n);
        }

        if (cnt >= k)
            right = M;
        else 
            left = M;
    }

    cout << right << endl;

    return 0;
}