#include<bits/stdc++.h>
#define INF 1000000000000000000ll
using namespace std;
typedef long long ll;

ll calc(int W, int H, int x1, int y1, int x2, int y2, int w, int h)
{
    ll res = INF;
    if(w <= x1 || h <= y1)
    {
        return 0;
    }
    if(w > x1 && w + x2 - x1 <= W)
    {
        res = min(res, (ll)w - x1);
    }
    if(h > y1 && h + y2 - y1 <= H)
    {
        res = min(res, (ll)h - y1);
    }
    return res;
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
        int W, H, w, h;
        cin >> W >> H;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        ll res = INF;
        res = min(res, calc(W, H, x1, y1, x2, y2, w, h));
        res = min(res, calc(W, H, W - x2, H - y2, W - x1, H - y1, w, h));
        res = min(res, calc(H, W, H - y2, x1, H - y1, x2, h, w));
        res = min(res, calc(H, W, y1, W - x2, y2, W - x1, h, w));
        if(res == INF)
        {
            cout << "-1\n";
        }
        else
        {
            cout << res << '\n';
        }
    }
}