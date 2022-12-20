#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long mod = 1e9 + 9;
const int N = 3e5 + 1;

int a[N], x[N];

int main() {
    int i, j, k, n, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int y = 0;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        y = max(y, a[i]);
    }
    for (i = y; i <= 300; ++i) {
        int bl = 0;
        for (j = 1; j <= n; ++j)
            bl += a[j] - (i - a[j]);
        if (bl < 0) {
            cout << i;
            return 0;
        }
    }
}