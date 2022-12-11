#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {

    ll m, b;
    cin >> m >> b;

    ll ans = 0;
    for (ll y = 0; y <= b; ++y) {
        ll x = m * (b - y);
        ans = max(ans, (x + 1) * (y + 1) * (x + y) / 2);
    }

    cout << ans << "\n";

}