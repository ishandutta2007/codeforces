#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 300;

int main() {
    int i, j, a[N], n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= 2*n; ++i)
        cin >> a[i];
    int ans = 0;
    for (i = 1; i < 2 * n; ++i)
    if (i == 1 || a[i] != a[i - 1]) {
        int j = i + 1;
        while (a[j] != a[i]) ++j;
        while (j > i + 1) {
            ++ans;
            a[j] = a[j - 1];
            --j;
        }
        a[j] = a[i];
    }
    cout << ans;
}