#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    int t;
    cin >> t;

    ull modV = (ull)(1LL << 32);

    for(int p = 0; p < t; ++p) {
        int n;
        ll l, r;
        ull x, y, z;

        cin >> n >> l >> r >> x >> y >> z;

        ull b[n];
        cin >> b[0] >> b[1];

        for(int i = 2; i < n; ++i) {
            b[i] = ((b[i - 2] * x % modV + b[i - 1] * y % modV) % modV + z) % modV;
        }

        ll a[n];
        ll modValue = r - l + 1LL;
        for(int i = 0; i < n; ++i)
            a[i] = (ll)b[i] % modValue + l;

        ll ans = LLONG_MAX;

        ll minV = LLONG_MAX;
        for(int i = 0; i < n; ++i) {
            if(a[i] >= 0 && a[i] > minV) {
                ans = min(ans, a[i] * minV);
            }

            minV = min(minV, a[i]);
        }

        ll maxV = LLONG_MIN;
        for(int i = n - 1; i >= 0; --i) {
            if(a[i] <= 0 && a[i] < maxV) {
                ans = min(ans, a[i] * maxV);
            }

            maxV = max(maxV, a[i]);
        }

        if(ans == LLONG_MAX)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << "\n";
    }


    return 0;
}