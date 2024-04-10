#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, int> pll;

const int inf = 2e9 + 10;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    ll d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;

    ll ans;
    if (k <= d) {
        ans = k * a + (d - k) * b;
    } else {
        ans = d * a;
        cout << ans << "\n";
        return 0;
    }

    ll m = d / k;
    if (d % k == 0) {
        --m;
    }

    ans = min(ans, a * d + m * t);
    m = d / k;

    ans = min(ans, a * k * m + (m - 1) * t + (d - k * m) * b);

    cout << ans << "\n";

}