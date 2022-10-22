#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double
#define yes cout << "YES\n";
#define no cout << "NO\n";

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        map<int, int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x]++;
        }
        int ans = 0, z = (int) a.size() - 1;
        for (auto el : a) {
            int x = el.second;
            int tmp = min(z, el.second);
            tmp = max(tmp, min(z + 1, el.second - 1));
            ans = max(ans, tmp);
        }
        cout << ans << '\n';
    }
}