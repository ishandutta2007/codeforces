#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, m;
    int i, j;
    vector <vector <int> > t(60000, vector <int> (10));
    vector <vector <int> > ans(60000, vector <int> (10));

    cin >> m >> n;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        cin >> t[i][j];

    ans[1][1] = t[1][1];
    for (i = 2; i <= m; i++)
        ans[i][1] = ans[i - 1][1] + t[i][1];

    for (j = 2; j <= n; j++)
    {
        ans[1][j] = ans[1][j - 1] + t[1][j];
        for (i = 2; i <= m; i++)
        {
            if (ans[i][j - 1] <= ans[i - 1][j]) ans[i][j] = ans[i - 1][j] + t[i][j];
            else ans[i][j] = ans[i][j - 1] + t[i][j];
        }
    }

    for (i = 1; i <= m; i++)
        cout << ans[i][n] << " ";

}