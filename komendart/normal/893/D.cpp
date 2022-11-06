#include <bits/stdc++.h>

using namespace std;

#define int long long

void fail() {
    cout << -1 << '\n';
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, d;
    cin >> n >> d;
    int balance = 0;
    int maxbalance = d;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 0) {
            if (balance < 0) {
                if (maxbalance - balance <= d) {
                    maxbalance -= balance;
                } else {
                    maxbalance = 0;
                    ++ans;
                }
                balance = 0;
            }
        } else {
            balance += x;
            if (balance > d) fail();
            maxbalance = max(maxbalance, balance);
        }
    }
    cout << ans << '\n';
}