#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t --> 0) {
        long long b, a;
        cin >> b >> a;
        
        if (b - a > 1) {
            cout << "NO" << '\n';
        } else {
            long long p = b + a;
            bool is_prime = true;
            for (long long d = 2; d * d <= p; d++) {
                if (p % d == 0)
                    is_prime = false;
            }
            cout << (is_prime ? "YES" : "NO") << endl;
        }
    }
}