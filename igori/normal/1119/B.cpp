#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <time.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n;
ll a[500000];
ll h;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> c;
        for (int j = 0; j <= i; j++) c.push_back(a[j]);
        sort(c.begin(), c.end());
        reverse(c.begin(), c.end());
        ll x = 0;
        for (int j = 0; j < c.size(); j += 2)
            x += c[j];
        if (x <= h)
            ans = i + 1;
    }
    cout << ans;
}