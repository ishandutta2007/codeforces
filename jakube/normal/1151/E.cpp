#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i+1];
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        // i-1 i
        //  0  1 
        if (a[i-1] < a[i]) {
            ans += (long long)(a[i] - a[i-1]) * (n - a[i] + 1);
        }
        if (a[i-1] > a[i]) {
            ans += (long long)a[i] * (a[i-1] - a[i]);
        }

    }
    cout << ans << '\n';
}