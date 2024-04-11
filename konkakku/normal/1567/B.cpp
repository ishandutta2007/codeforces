#include <bits/stdc++.h>
using namespace std;

const int MX = 300005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> pre(MX);
    for (int i = 1; i < MX; i++) {
        pre[i] = pre[i - 1] ^ i;
    }
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if (pre[a - 1] == b) {
            cout << a << '\n';
        } else if (pre[a] == b) {
            cout << a + 2 << '\n';
        } else {
            cout << a + 1 << '\n';
        }
    }
}