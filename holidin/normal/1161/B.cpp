#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long N = 1e6 + 1;
const long long mod = 1e9 + 7;
const long long div1 = 37;
long long tp[N], z[N];
long long t[N];

int main() {
    int i, j, k, n, l, r, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    t[0] = 1;
    for (i = 1; i <= n; ++i)
        t[i] = (t[i - 1] * div1) % mod;
    for (i = 0; i < k; ++i) {
        cin >> a >> b;
        if (a > b) {
            tp[b] = (tp[b] + t[a - b]) % mod;
            tp[a] = (tp[a] + t[n + b - a]) % mod;
        } else {
            tp[a] = (tp[a] + t[b - a]) % mod;
            tp[b] = (tp[b] + t[n + a - b]) % mod;
        }
    }
    for (i = n + 1; i <= 2 * n; ++i)
        tp[i] = tp[i - n];
    l = 1;
    r = 1;
    z[1] = 2 * n;
    for (i = 2; i <= n; ++i) {
        if (i > r) {
            l = i;
            r = i - 1;
            z[i] = 0;
        } else
            z[i] = min((long long)r - i, z[i - l + 1]);
        while (i + z[i] <= 2 * n && tp[i + z[i]] == tp[z[i] + 1]) {
            ++z[i];
            r = max((long long)r, i + z[i] - 1);
        }
        if (z[i] >= n) {
            cout << "Yes";
            exit(0);
        }
    }
    cout << "No";
}