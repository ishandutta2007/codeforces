#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    LL total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }
    LL ans = -1;
    LL y = total;
    auto solve = [&](LL x) {
        auto b = a;
        int l = 0;
        LL sum = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            sum += b[i];
            if (sum >= x) {
                b[i] = b[i] - sum + x;
                LL tmp = 0;
                int p;
                for (p = l; ; ++p) {
                    tmp += b[p];
                    if (2 * tmp >= x)
                        break;
                }
                for (int j = l; j <= i; ++j)
                    res += 1LL * b[j] * abs(j - p);
                l = i;
                sum %= x;
                b[i] = sum;
            }
        }
        if (ans == -1 || ans > res)
            ans = res;
    };
    for (LL x = 2; x * x <= y; ++x) {
        if (y % x == 0) {
            while (y % x == 0)
                y /= x;
            solve(x);
        }
    }
    if (y > 1)
        solve(y);
    cout << ans << endl;
    return 0;
}