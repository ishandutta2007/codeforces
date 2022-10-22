#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'z') {
            ans++;
        }
    }
    int k = (n - (ans * 4)) / 3;
    for (int i = 0; i < k; i++) {
        cout << 1 << " ";
    }
    for (int i = 0; i < ans; i++) {
        cout << 0 << " ";
    }
}