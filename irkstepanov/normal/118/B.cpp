#include <bits/stdc++.h>

#define x first
#define y second

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair <int, int> cell;

int main()
{

    int ans[50][50];
    int n;
    cin >> n;

    for (int i = 0; i <= 2 * n; i++)
    {
        if (i <= n) ans[i][n] = i;
        else ans[i][n] = 2 * n - i;
        for (int j = n - 1; j >= 0; j--)
            ans[i][j] = max (ans[i][j + 1] - 1, -1);
        for (int j = n + 1; j <= 2 * n; j++)
            ans[i][j] = max (ans[i][j - 1] - 1, -1);
        for (int j = 0; j < n; j++)
            if (ans[i][j] >= 0) cout << ans[i][j] << " ";
            else cout << "  ";
        cout << ans[i][n];
        for (int j = n + 1; j <= 2 * n; j++)
            if (ans[i][j] >= 0) cout << " " << ans[i][j];
        cout << "\n";
    }

}