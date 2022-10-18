#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    long long n;
    cin >> n;
    
    long long res = 0;
    for (int i = 0; i < 41; i++) {
        res += (n / 2) << i;
        if (n % 2) {
            auto x = n - 1;
            for (int j = 0; j < 41; j++) {
                if ((x >> j) & 1) {
                    res += 1LL << (i + j);
                    break;
                }
            }
        }
        n /= 2;
    }
    cout << res;
}