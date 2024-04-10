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
    int h, w;
    cin >> h >> w;
    vector<vector<char> > a(h, vector<char>(w));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = (a[0][0] == '*');
    int x = 0;
    int y = 0;
    for(int i = 0; i < w + h - 2; i++)
    {
        if(x + 1 == h)
        {
            y += 1;
            ans += (a[x][y] == '*');
            continue;
        }
        if(y + 1 == w)
        {
            x += 1;
            ans += (a[x][y] == '*');
            continue;
        }
        if(a[x + 1][y] == '*')
        {
            x += 1;
            ans += (a[x][y] == '*');
            continue;
        }
        y += 1;
        ans += (a[x][y] == '*');
        continue;
    }
    cout << ans;
}