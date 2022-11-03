#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 0;
    int cur = 1;
    for (int i = n; i >= 2; --i) {
        cur = (cur * ll(i)) % mod;
        ans = (ans + mod - cur) % mod;
    }
    cur = (cur * ll(n)) % mod;
    ans = (ans + cur) % mod;
    cout << ans << endl;
}