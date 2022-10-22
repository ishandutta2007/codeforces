#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int j = 0;
        while (j + 1 < n && abs(a[j] - a[j + 1]) < 2) {
            j++;
        }
        if (j + 1 == n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << j + 1 << " " << j + 2 << '\n';
        }
    }
}