// Hydro submission #63203ac832ae6c3198c9df84@1663056585589
#include <bits/stdc++.h>
using namespace std;
int n, q;
double p; // p/2000
//  j  i 
double f[1005][10005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        f[i][0] = 0;
    for (int j = 1; j <= 10000; j++)
        for (int i = 1; i <= n; i++)
        {
            f[i][j] = f[i][j - 1] * i / n +
                      f[i - 1][j - 1] * (n - (i - 1)) / n;
        }
    while (q--)
    {
        cin >> p;
        for (int j = 1; j <= 10000; j++)
            if (f[n][j] >= p / 2000)
            {
                cout << j << "\n";
                break;
            }
    }
    return 0;
}