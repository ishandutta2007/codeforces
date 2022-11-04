#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int o = 0; o < t; o++)
    {
        long long r, g, b;
        cin >> r >> g >> b;
        long long ans = 0;
        long long max1 = max(r, max(g, b));
        long long min1 = min(r, min(g, b));
        g = r + g + b - max1 - min1;
        r = max1;
        b = min1;
        ans += b;
        if(b > r - g)
        {
            long long d = r - g;
            b -= d;
            r = g;
            g -= (b - 1) / 2 + 1;
            r -= b / 2;
        }
        else
        {
            r -= b;
        }
        ans += min(r, g);
        cout << ans << endl;
    }
}