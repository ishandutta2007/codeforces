#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 2e5 + 12;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxN = 2e7 + 1;


int f(int x) {
    return x * (x + 1) / 2;
}

void run() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (k >= n) {
        ans += 1;
        ans += f(n - 1);
    } else {
        ans += f(k);
    }
    cout << ans << "\n";
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--)
        run();
}