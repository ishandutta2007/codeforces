#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;

map <int, int> m0, m1;
int a[N];

int main() {
    int i, j, n, k, b, l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    long long ans = 0, x = 0;
    m0[0] = 1;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        x ^= a[i];
        if (i % 2 == 0) {
            ans += m0[x];
            ++m0[x];
        } else {
            ans += m1[x];
            ++m1[x];
        }
    }
    cout << ans;

}