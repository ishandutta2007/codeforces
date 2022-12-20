#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;

int a[N];

int main() {
    int i, j, k, n, m;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    int l = 0, r = m;
    while (r - l > 1) {
        int mid = (l + r) / 2 - 1;
        int mx = 0;
        bool can = 1;
        for (i = 0; i < n; ++i) {
            if (a[i] + mid < mx)
                can = 0;
            if (!(m - a[i] + mx <= mid))
                mx = max(a[i], mx);
        }
        if (can)
            r = mid + 1;
        else
            l = mid + 1;
    }
    cout << l;
}