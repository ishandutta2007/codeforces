#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    if (k > 43) {
        cout << "No" << endl;
        return 0;
    }

    vector<bool> remainder(43, false);
    for (int i = 1; i <= k; i++) {
        if (remainder[n % i]) {
            cout << "No" << '\n';
            return 0;
        }
        remainder[n % i] = true;
    }
    cout << "Yes" << '\n';
}