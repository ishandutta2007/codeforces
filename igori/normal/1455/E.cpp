#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        vector<int> x(4), y(4);
        for (int i = 0; i < 4; i++) cin >> x[i] >> y[i];
        long long ans = 1e18;
        vector<int> p = {0, 1, 2, 3};
        for (int ii = 0; ii < 24; ii++, next_permutation(p.begin(), p.end()))
        {
            int x1 = x[p[0]], x2 = x[p[1]], x3 = x[p[2]], x4 = x[p[3]];
            int y1 = y[p[0]], y2 = y[p[1]], y3 = y[p[2]], y4 = y[p[3]];
            //cout << y1 << " " << y2 << " " << y3 << " " << y4 << endl;
            int lx = min(x3, x4) - max(x1, x2);
            int rx = max(x3, x4) - min(x1, x2);
            int ly = min(y2, y4) - max(y1, y3);
            int ry = max(y2, y4) - min(y1, y3);
            lx = max(lx, 0);
            //rx = max(rx, 0);
            if (lx > rx) continue;
            ly = max(ly, 0);
            //ry = max(ry, 0);
            if (ly > ry) continue;
            int k = 0;
            if (rx < ly) k = ly - rx;
            if (ry < lx) k = lx - ry;
            //cout << k << endl;
            //cout << max(x2, x1) << " " << min(x2, x1) << endl;
            ans = min(ans, 2ll * k + max(x2, x1) - min(x2, x1) + max(x4, x3) - min(x4, x3) + max(y3, y1) - min(y3, y1) + max(y4, y2) - min(y4, y2));
        }
        cout << ans << "\n";
    }
}