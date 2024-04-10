#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool f = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i != 1 && a[i] != a[i - 1]) f = 1;
        }
        if (f)
            cout << 1 << endl;
        else
            cout << n << endl;
    }
}