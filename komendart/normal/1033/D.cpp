#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
#define int long long

const int mod = 998244353;

int get_root(int x) {
    int a = sqrtl(x);
    while (a * a <= x) ++a;
    while (a * a > x) --a;
    if (a * a == x) return a;
    return 0;
}

int get_cubic(int x) {
    int a = pow(x, 1.0 / 3);
    while (a * a * a <= x) ++a;
    while (a * a * a > x) --a;
    if (a * a * a == x) return a;
    return 0;
}

int gcd(int a, int b) {
    while (a && b) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    map<int, int> d;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++d[x];
    }
    map<int, int> degree;
    int ans = 1;
    for (auto it: d) {
        int x, cnt;
        tie(x, cnt) = it;
        int r = get_root(x);
        if (r) {
            int t = get_root(r);
            if (t) {
                degree[t] += 4 * cnt;
            } else {
                degree[r] += 2 * cnt;
            }
        } else if ((r = get_cubic(x))) {
            degree[r] += 3 * cnt;
        } else {
            int g = 1;
            for (auto j: d) {
                g = gcd(x, j.first);
                if (g != x && g != 1) {
                    break;
                }
            }
            if (g != x && g != 1) {
                int p = g;
                int q = x / g;
                degree[p] += cnt;
                degree[q] += cnt;
            } else {
                ans *= cnt + 1; ans %= mod;
                ans *= cnt + 1;
                ans %= mod;
            }
        }
    }
    for (auto i: degree) {
        ans *= (i.second + 1);
        ans %= mod;
    }
    cout << ans << '\n';
}