#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    bool ok = false;
    while(n--) {
        int x;
        cin >> x;
        if(x == 1) ok = true;
    }
    cout << (ok ? "YES" : "NO") << '\n';
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