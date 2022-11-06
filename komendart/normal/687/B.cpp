#include <bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    int ans = 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ans = ans * t / gcd(ans, t);
        ans = gcd(k, ans);
    }

    if (ans == k) cout << "Yes\n";
    else cout << "No\n";
}