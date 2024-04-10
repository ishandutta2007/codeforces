#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;
    int cola = 0;
    while (n >= 0) {
        if (n % b == 0) {
            cout << "YES" << '\n';
            cout << cola << " " << n / b << '\n';
            return 0;
        }
        n -= a;
        cola++;
    }
    cout << "NO" << '\n';
}