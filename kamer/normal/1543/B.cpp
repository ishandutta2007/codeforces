#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long sum = 0;
        long long a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            sum += a;
        }

        long long rem = sum % n;
        cout << rem * (n - rem) << "\n";
    }
}