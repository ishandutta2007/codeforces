#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "1";
        for(int j = 2; j <= i; j++) {
            cout << " 0";
        }
        if(i > 0) cout << " 1";
        cout << '\n';
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