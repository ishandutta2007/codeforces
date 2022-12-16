#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] *= -1;
        }
        sort(a, a+n);
        for (int i = 0; i < n-1; i++) {
            cout << -a[i] << ' ';
        }
        cout << -a[n-1] << endl;
    }
}