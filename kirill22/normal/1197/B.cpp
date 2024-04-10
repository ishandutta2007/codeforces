#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == n) {
            j = i;
        }
    }
    for (int i = 0; i < j; i++) {
        if (a[i] > a[i + 1]) {
            cout << "NO";
            return 0;
        }
    }
    for (int i = j; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            cout << "NO";
            return 0;
        }
    }
cout << "YES";
}