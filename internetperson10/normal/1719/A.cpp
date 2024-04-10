#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if((n + m) % 2) cout << "Burenka\n";
    else cout << "Tonya\n";
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