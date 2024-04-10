#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m = 4e6;
    cin >> n;
    vector<int> a(n), go(m, n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        go[a[i]] = min(go[a[i]], i);
    }
    for (int i = m - 2; i >= 0; i--) {
        go[i] = min(go[i], go[i + 1]);
    }
    for (int x = 1; ; x++) {
        if (a[0] > x * 1ll * x + x) {
            continue;
        }
        long long minadd = max(0ll, x * 1ll * x - a[0]), maxadd = x * 1ll * x + x - a[0];
        int i = 0;
        while (i < n && minadd <= maxadd) {
            int tx = (int) sqrt(a[i] + maxadd);
            int val = a[i] + tx + 1;
            int j = (val < m ? go[val] : n);
            minadd = max(minadd, tx * 1ll * tx - a[i]);
            maxadd = min(maxadd, tx * 1ll * tx + tx - a[j - 1]);
            i = j;
        }
        if (minadd <= maxadd) {
            cout << minadd;
            return 0;
        }
    }
}