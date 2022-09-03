#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
ll r_max, c_min, x, r_max2, r_sum, c_sum, ans;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    r_max = 0;
    r_max2 = 0;
    r_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (r_max <= x)
        {
            r_max2 = r_max;
            r_max = x;
        }
        else if (r_max2 <= x)
            r_max2 = x;
        r_sum += x;
    }
    c_min = (int)(1e8);
    c_sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        if (c_min >= x)
            c_min = x;
        c_sum += x;
    }
    if (r_max > c_min)
    {
        cout << "-1";
        return 0;
    }
    ans = r_sum * (ll)m;
    ans += c_sum;
    ans -= r_max * (ll)m;
    if (r_max < c_min)
        ans += r_max - r_max2;
    cout << ans;
    return 0;
}