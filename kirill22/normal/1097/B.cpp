#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int msk = 0; msk < (1 << n); msk++) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (msk >> i & 1) {
                x += a[i];
            } else {
                x -= a[i];
            }
        }
        if (x % 360 == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}