#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        long long sum = 0;
        long long k = (n + 1) / 2;
        long long line = 0;
        for (ll i = 1; i < k; i++) {
            line += i;
        }
        for (ll i = 0; i < k; i++) {
            ll x = max(i - 1, (ll)0);
            sum = sum + line + x * (x + 1) / 2;
        }
        cout << 4 * sum << "\n";
    }
    return 0;
}