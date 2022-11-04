#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x, y, a, b;

pair<int, int> get(int a1)
{
    ll min1 = (ll)a1 * a;
    if(min1 > x)
    {
        return {0, -1};
    }
    int xnew = x - min1;
    ll min2 = (ll)a1 * b;
    if(min2 > y)
    {
        return {0, -1};
    }
    int ynew = y - min2;
    int can = min(xnew / b, ynew / a);
    int ans = can + a1;
    int leftx = xnew - can * b;
    int lefty = ynew - can * a;
    if(lefty >= leftx)
    {
        return {ans, 1};
    }
    return {ans, -1};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> a >> b;
        if(b < a)
        {
            int k = a;
            a = b;
            b = k;
        }
        int l = 0;
        int r = x;
        while(r - l > 1)
        {
            int mid = (l + r) / 2;
            if(get(mid).second == 1)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << max(get(l).first, get(l + 1).first) << '\n';
    }
}