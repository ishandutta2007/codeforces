#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 1) {
        cout << "NO";
        return 0;
    }
    sort(a.begin(), a.end());
    if (a[n - 1] > sum / 2) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
}