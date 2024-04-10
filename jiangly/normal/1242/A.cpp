#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n;
    cin >> n;
    for (LL i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            if (n == 1) {
                cout << i << endl;
            } else {
                cout << 1 << endl;
            }
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}