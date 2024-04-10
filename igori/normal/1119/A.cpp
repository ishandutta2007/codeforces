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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[n - 1])
            ans = max(ans, n - 1 - i);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[0])
            ans = max(ans, (ll)i - 0);
    }
    cout << ans;
}