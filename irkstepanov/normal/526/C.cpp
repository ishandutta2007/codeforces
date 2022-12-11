#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;

ll c, hr, hb, wb, wr;

ll solve(ll red)
{
    ll blue = (c - red * wr) / wb;
    return red * hr + blue * hb;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> c >> hr >> hb >> wr >> wb;

    if (c / wr <= 1000000)
    {
        ll ans = 0;
        for (ll r = 0; r <= c / wr; r++)
        {
            ll b = (c - r * wr) / wb;
            ans = max(ans, r * hr + b * hb);
        }
        cout << ans << "\n";
        return 0;
    }

    if (c / wb <= 1000000)
    {
        ll ans = 0;
        for (ll b = 0; b <= c / wb; b++)
        {
            ll r = (c - b * wb) / wr;
            ans = max(ans, r * hr + b * hb);
        }
        cout << ans << "\n";
        return 0;
    }

    ll ans = 0;
    for (ll b = 0; b <= 100000; b++)
    {
        ll r = (c - b * wb) / wr;
        ans = max(ans, r * hr + b * hb);
    }
    for (ll r = 0; r <= 100000; r++)
    {
        ll b = (c - r * wr) / wb;
        ans = max(ans, r * hr + b * hb);
    }

    cout << ans << "\n";

}