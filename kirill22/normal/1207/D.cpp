#include <bits/stdc++.h>

using namespace std;

#define int long long

int MOD = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<pair<int, int>> b(n);
    for (int i = 0 ;i < n; i++) {
        cin >> a[i].first >> a[i].second;
        b[i].first = a[i].second;
        b[i].second = a[i].first;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    int A = 1, B = 1;
    int tmp = a[0].first, k = 1;
    for (int i = 1; i< n; i++) {
        if (a[i].first == tmp) {
            k++;
        }
        else {
            for (int j = 2; j <= k; j++) {
                A = (A * j) % MOD;
            }
            tmp = a[i].first;
            k = 1;
        }
    }
    for (int j = 2; j <= k; j++) {
        A = (A * j) % MOD;
    }
    tmp = b[0].first, k = 1;
    for (int i = 1; i< n; i++) {
        if (b[i].first == tmp) {
            k++;
        }
        else {
            for (int j = 2; j <= k; j++) {
                B = (B * j) % MOD;
            }
            tmp = b[i].first;
            k = 1;
        }
    }
    for (int j = 2; j <= k; j++) {
        B = (B * j) % MOD;
    }
    ans = (ans - A - B + MOD * 10) % MOD;
    for (int i = 1; i < n; i++) {
        if (a[i].second < a[i - 1].second) {
            cout << ans;
            return 0;
        }
    }
    int ans2 = 1;
    k = 1;
    pair<int, int> tmp2 = a[0];
    for (int i = 1; i< n; i++) {
        if (a[i] == tmp2) {
            k++;
        }
        else {
            for (int j = 2; j <= k; j++) {
                ans2 = (ans2 * j) % MOD;
            }
            tmp2 = a[i];
            k = 1;
        }
    }
    for (int j = 2; j <= k; j++) {
        ans2 = (ans2 * j) % MOD;
    }
    ans  = (ans + ans2) % MOD;
    cout << ans;
}