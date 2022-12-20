#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const long long mod = 998244353;


int gcd(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

long long a[N], t[N];

int main() {
    vector <pair<int, int> > v;
    long long i, j, n, q, top, l, r, k, x, d;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    long long ans = 0;
    t[0] = 1;
    for (i = 1; i <= n; ++i)
        t[i] = (t[i - 1] * 2) % mod;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        ans = (ans + a[i] * (((n - i) * t[n - i] + t[n - i + 1]) % mod)) % mod;
    }
    if (ans % 2 == 1)
        ans += mod;
    ans /= 2;
    cout << ans;
}