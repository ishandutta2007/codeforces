#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }
    for (int i = 0; i <= n; i++) {
        if (a[i] < a[0]) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (a[i] > a[n]) {
            cout << -1;
            return 0;
        }
    }
    auto b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    vector<int> ft(n + 1);
    long long ans = 0;
    for (int i = n; i >= 0; i--) {
        int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        for (int j = x - 1; j >= 0; j = (j & (j + 1)) - 1) {
            ans += ft[j];
        }
        for (int j = x; j <= n; j = j | (j + 1)) {
            ft[j]++;
        }
    }
    cout << ans;
}