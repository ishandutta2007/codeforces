#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    if(x < y) swap(x, y);
    cout << x + y + max(0, x - y - 1) << '\n';
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