#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int maxUp = 0, maxDown = 0, maxLeft = 0, maxRight = 0;
        int x = 0, y = 0;
        int fl = 1;
        for (int i = 0; i < s.size(); i++)
        {
            int x0 = n - maxDown, y0 = m - maxLeft;
            if (s[i] == 'U') x--;
            if (s[i] == 'D') x++;
            if (s[i] == 'R') y++;
            if (s[i] == 'L') y--;
            maxUp = max(maxUp, -x);
            maxDown = max(maxDown, x);
            maxLeft = max(maxLeft, y);
            maxRight = max(maxRight, -y);
            if (maxUp + maxDown == n || maxLeft + maxRight == m)
            {
                cout << x0 << " " << y0 << "\n";
                fl = 0;
                break;
            }
        }
        int x0 = n - maxDown, y0 = m - maxLeft;
        if (fl) cout << x0 << " " << y0 << "\n";
    }
}