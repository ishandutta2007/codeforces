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
ll s[500000];
ll len[500000];
ll p[500000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s, s + n);
    for (int i = 0; i < n - 1; i++)
        len[i] = s[i + 1] - s[i];
    len[n - 1] = 2e18;
    sort(len, len + n);
    for (int i = 0; i < n; i++)
    {
        //cout << len[i] << endl;
        p[i] = p[i - 1] + len[i];
    }
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll l, r;
        cin >> l >> r;
        ll Len = r - l + 1;
        //cout << Len << "\n";
        l = -1, r = n;
        while (l + 1 < r)
        {
            ll mid = (l + r) / 2;
            if (len[mid] < Len)
                l = mid;
            else
                r = mid;
        }
        //cout << l << "\n";
        //cout << p[l] << " " << n - l - 1<< "\n";
        long long ans = p[l] + Len * (n - l - 1);
        cout << ans << " ";
    }
}