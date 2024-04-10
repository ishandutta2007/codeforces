#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n, k;
    cin >> n >> k;

    if (k-1 < (n + 1) / 2) {
        cout << 2*k - 1 << endl;
    } else {
        cout << 2*(k - (n + 1) / 2) << endl;
    }
    

    return 0;
}