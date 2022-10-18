#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, A, B;
    cin >> n >> k >> A >> B;

    long long best = (n - 1) * A;
    long long cur = 0;
    while (n > 1 && k > 1) {
        long long am = n % k;
        cur += am * A;
        n -= am;
        cur += B;
        n /= k;
        best = min(best, cur + (n-1) * A);
    }

    cout << best << endl;
    
}