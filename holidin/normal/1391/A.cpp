#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    while (n > 0) {
        cout << (n--) << ' ';
    }
    cout << "\n";
}

int main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}