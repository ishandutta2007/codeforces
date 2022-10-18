#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    if (n % 2) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << (i ^ 1) + 1 << " ";
    }
    cout << endl;

    return 0;
}