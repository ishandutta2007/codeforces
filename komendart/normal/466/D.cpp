#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);

    int n, h;
    cin >> n >> h;
    long long result = 1;
    int inc = 0;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        if (v > h) {
            result = 0;
        } else if (v + inc == h - 1) {
            inc++;
        } else if (v + inc == h + 1) {
            result = result * inc % MOD;
            inc--;
        } else if (v + inc == h) {
            result = result * (inc + 1) % MOD;
        } else {
            result = 0;
        }
    }
    if (inc > 1) result = 0;
    cout << result << '\n';
}