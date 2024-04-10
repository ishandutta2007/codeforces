#include <iostream>
#include <vector>

using namespace std;

int n, m, c;
int a[2000];

bool check()
{
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 0 || a[i - 1] == 0)
            return 0;
        if (a[i] < a[i - 1])
            return 0;
    }
    return 1;
}

signed main()
{
    //freopen("stdin.in", "r", stdin);
    //freopen("stdout.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> c;
    if (c % 2 == 1)
        c++;

    for (int i = 0; i < m; i++)
    {
        int p = 0, e = 0;
        cin >> p;
        if (p <= c / 2)
        {
            int j = n;
            while (j - 1 >= 1 && (a[j - 1] == 0 || a[j - 1] > p))
            {
                j--;
            }
            e = j;
        }
        else
        {
            int j = 1;
            while (j + 1 <= n && (a[j + 1] == 0 || a[j + 1] < p))
            {
                j++;
            }
            e = j;
        }
        cout << e << endl;
        a[e] = p;
        if (check())
            return 0;
    }
}