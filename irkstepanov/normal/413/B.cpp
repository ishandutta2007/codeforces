#include <iostream>

using namespace std;

int main()
{

    int n, m, k;
    int matr[20005][15];
    int i, j;
    int ans[20005];
    int chat[15];

    cin >> n >> m >> k;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        cin >> matr[i][j];

    for (i = 1; i <= n; i++)
        ans[i] = 0;
    for (j = 1; j <= m; j++)
        chat[j] = 0;

    for (i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        ans[a]--;
        chat[b]++;
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        if (matr[i][j]) ans[i] += chat[j];

    for (i = 1; i <= n; i++)
        cout << ans[i] << " ";

}