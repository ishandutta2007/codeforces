#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    for (int i = 0; i < n; i++) {
        int j = min(i, n - 1 - i);
        if (j % 2 == 0) {
            cout << v[n - i - 1] << ' ';
        } else {
            cout << v[i] << ' ';
        }
    }

    return 0;
}