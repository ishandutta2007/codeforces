#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    int n;
    ll h, k;
    cin >> n >> h >> k;

    ll ans = 0;
    ll occ = 0;

    while (n--) {
        ll a;
        cin >> a;
        if (a + occ <= h) {
            occ += a;
            continue;
        } else {
            ll dt = (a - h + occ + k - 1) / k;
            ans += dt;
            occ -= dt * k;
            if (occ < 0) {
                occ = 0;
            }
            occ += a;
        }
    }

    if (occ >= 0) {
        ll dt = (occ + k - 1) / k;
        ans += dt;
    }

    cout << ans << "\n";

}