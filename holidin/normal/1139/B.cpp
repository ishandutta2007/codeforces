#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;

long long a[N];

int main() {
    int i, j, k, l, r, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    long long ans = 0, lst = 1e12;
    for (i = n; i >= 1; --i) {
        ans += max((long long)0, min(a[i], lst - 1));
        lst = max((long long)0, min(a[i], lst - 1));
    }
    cout << ans;
}