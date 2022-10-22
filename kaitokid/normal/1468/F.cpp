#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int main () {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        map <pair <long long, long long>, long long> mp;
        while (n--) {
            long long x, y, u, v;
            cin >> x >> y >> u >> v;
            long long v_x = u - x, v_y = v - y;
            long long g = __gcd(abs(v_x), abs(v_y));
            mp[{v_x / g, v_y / g}]++;
        }
        long long res = 0;
        for (auto u: mp) {
            long long xx = u.first.first, yy = u.first.second;
            if (mp.count({-xx, -yy}))
                res += mp[{xx, yy}] * mp[{-xx, -yy}];
        }
        cout << res / 2 << endl;
    }
    return 0;
}