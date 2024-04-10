#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector <int> vi;

const int inf = 1000000000;

int main()
{

    int n, m, d;
    cin >> n >> m >> d;
    int a[120][120];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        cin >> a[i][j];

    int ans = inf;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
    {
        int otv = 0;
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++)
            if (otv != inf)
            {
                int t = abs(a[i][j] - a[x][y]);
                if (t % d == 0) otv += t / d;
                else {otv = inf; break;}
            }
            else break;
        ans = min(ans, otv);
    }

    if (ans != inf) cout << ans;
    else cout << "-1";

}