#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;
    if(n > m) {
        cout << "No\n";
        return;
    }
    if(n % 2 == 0) {
        if(m % 2 == 1) {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        for(int i = 0; i < n-2; i++) {
            cout << 1 << ' ';
        }
        cout << (m-n+2)/2 << ' ' << (m-n+2)/2 << '\n';
        return;
    }
    else {
        cout << "Yes\n";
        for(int i = 0; i < n-1; i++) {
            cout << 1 << ' ';
        }
        cout << m-n+1 << '\n';
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