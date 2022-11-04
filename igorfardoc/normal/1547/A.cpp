#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



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
        int xa, ya, xb, yb, xf, yf;
        cin >> xa >> ya >> xb >> yb >> xf >> yf;
        int ans = abs(xa - xb) + abs(ya - yb);
        if(xa != xb && ya != yb)
        {
            cout << ans << '\n';
            continue;
        }
        if(xa == xb)
        {
            if(ya > yb)
            {
                int k = ya;
                ya = yb;
                yb = k;
            }
            if(xf == xa && yf < yb && yf > ya)
            {
                ans += 2;
            }
        }
        else
        {
            if(xa > xb)
            {
                int k = xa;
                xa = xb;
                xb = k;
            }
            if(yf == ya && xf < xb && xf > xa)
            {
                ans += 2;
            }
        }
        cout << ans << '\n';
    }
}