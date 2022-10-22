#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> s(n);
    ll maxSum = -1;
    for(int i = 0; i < n; i++) {
        ll sum = 0;
        for(int j = 0; j < m; j++) {
            ll x;
            cin >> x;
            sum += x;
            s[i] += sum;
        }
        maxSum = max(maxSum, s[i]);
    }
    for(int i = 0; i < n; i++) {
        if(maxSum != s[i]) {
            cout << i+1 << ' ' << maxSum - s[i] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}