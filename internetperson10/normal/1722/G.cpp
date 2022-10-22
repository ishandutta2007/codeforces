#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int x = 999999999;
    cout << x << ' ';
    for(int i = 2; i < n; i++) {
        cout << i + (1 << 21) - 3 << ' ';
        x ^= (i + (1 << 21) - 3);
    }
    cout << x << '\n';
}

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}