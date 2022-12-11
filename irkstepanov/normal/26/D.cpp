#include <bits/stdc++.h>
#include <string.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{

    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    if (k >= m) {
        cout << "1\n";
        return 0;
    }
    if (n + k - m < 0) {
        cout << "0\n";
        return 0;
    }

    ld ans = 1.0;
    for (int a = 1; a <= k + 1; ++a) {
        ans *= (ld)(m - a + 1);
        ans /= (ld)(n + a);
    }
    ans = 1.0 - ans;

    cout << fixed;
    cout.precision(12);
    cout << ans << "\n";

}