#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(k);
    for(int i = 0; i < k; i++) {
        cin >> v[i];
    }
    if(k == 1) {
        cout << "Yes\n";
        return;
    }
    for(int i = 2; i < k; i++) {
        if(v[i-1] - v[i-2] > v[i] - v[i-1]) {
            cout << "No\n";
            return;
        }
    }
    ll a = v[1] - v[0];
    if(v[0] > (n + 1 - k) * a) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
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