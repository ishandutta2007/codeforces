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
        long long sum = 0, x = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            x ^= a[i];
        }
        cout << 2 << '\n' << x << " " << sum + x << '\n';
    }
}