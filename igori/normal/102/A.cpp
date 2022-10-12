#include <iostream>
#include <string>

using namespace std;

long long n;
int c[101][101];
long long ans;
long long a[50050];
int main()
{
    ans = 1e9;
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        c[v][u] = 1;
        c[u][v] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (c[i][j] && c[j][k] && c[i][k])
                {
                    ans = min(ans, a[i] + a[j] + a[k]);
                }
            }
        }
    }
    if (ans == 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}