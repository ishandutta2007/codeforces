#include <bits/stdc++.h>

#define mp make_pair
#define pbp ush-back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;

int main()
{

    int tt;
    cin >> tt;

    while (tt--) {
        ll n;
        cin >> n;
        ll ans = n * (n + 1) / 2;
        for (ll d = 1; d <= n; d *= 2) {
            ans -= 2 * d;
        }
        cout << ans << "\n";
    }

}