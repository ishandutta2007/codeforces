#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;
int a[N], b[N];

void solve() {
    string s;
    int i, j, k, n;
    cin >> n >> k;
    cin >> s;
    for (i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
        b[i] = a[i % k];
    }
    cout << n << endl;
    i = 0;
    while (i < n && a[i] == b[i])
        ++i;
    if (i == n || b[i] >= a[i]) {
        for (i = 0; i < n; ++i)
            cout << b[i];
    } else {
        i = k - 1;
        while (a[i] == 9) {
            a[i] = 0;
            --i;
        }
        ++a[i];
        for (i = 0; i < n; ++i)
            cout << a[i % k];
    }

}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    int i, j, test;

    solve();
}