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

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    ll l, d, v, g, r;
    cin >> l >> d >> v >> g >> r;

    ll k = d / (v * (g + r));
    ll lf = k * (r + g);

    ld ans = (ld)(l) / (ld)(v);

    if (d >= v * (lf + g)) {
        ld dt = lf + r + g - (ld)(d) / (ld)(v);
        ans += dt;
    }

    cout << fixed;
    cout.precision(12);
    cout << ans << "\n";

}