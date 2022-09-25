#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<LL> a(n);
        for (LL& ai : a) cin >> ai;
        ranges::sort(a);
        //min((n-1)ai + sum) <= 0
        //max((n-1)ai + sum) >= 0
        LL sum = 0;
        for (LL ai : a) sum += ai;
        if (a[0] * (n - 2) + sum > 0) {
            cout << "INF\n";
            continue;
        }
        if (a[n - 1] * (n - 2) + sum < 0) {
            cout << "INF\n";
            continue;
        }
        vector<LL> s(n);
        for (int i = 0; i < n; i += 1) {
            s[i] = a[i];
            if (i) s[i] += s[i - 1];
        }
        LL ans = LLONG_MIN;
        for (int i = 0; i < n; i += 1) {
            LL pans = 0, t = -a[i];
            if (i) pans += (s[i - 1] + i * t) * (a.back() + t);
            pans += (s.back() - s[i] + (n - i - 1) * t) * (a[0] + t);
            pans -= (a[0] + t) * (a.back() + t);
            pans -= (n - 1) * t * t;
            ans = max(ans, pans);
        }
        cout << ans << "\n";
    }
    return 0;
}