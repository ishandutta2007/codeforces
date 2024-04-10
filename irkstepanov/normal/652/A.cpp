#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main()
{
    
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    
    x += a * 8;
    if (x >= y) {
        cout << "0\n";
        return 0;
    }
    
    ll ans = 1;
    for (; ans < 1e7; ++ans) {
        x -= 12 * b;
        x += 12 * a;
        if (x >= y) {
            cout << ans << "\n";
            return 0;
        }
    }
    cout << "-1\n";

}