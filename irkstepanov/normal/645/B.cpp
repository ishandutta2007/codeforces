#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main()
{

    int n, k;
    cin >> n >> k;

    ll ans = 0;
    for (int i = 0; i < k && n > 1; ++i) {
        ans += (ll)(2 * n - 3);
        n -= 2;
    }

    cout << ans << "\n";

}