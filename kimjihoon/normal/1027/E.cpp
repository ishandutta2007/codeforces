#include <iostream>
#include <algorithm>
using namespace std;

long long d[509][509], s[509], p[509];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, r; cin >> n >> r; r--;
    for (int i = 1; i <= n; i++) {
        s[0] = 1;
        for (int j = 1; j <= n; j++) {
            s[j] = 0;
            for (int k = 1; k <= i; k++) {
                if (k == 1) d[j][k] = s[j - 1];
                else d[j][k] = d[j - 1][k - 1];
                s[j] = (s[j] + d[j][k]) % 998244353LL;
            }
        }
        p[i] = s[n];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + (p[i] - p[i - 1]) * 2 * p[min(n, r / i)]) % 998244353LL;
    cout << ans << '\n';
    return 0;
}