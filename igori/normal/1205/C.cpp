#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

long long n;
int a[51][51];
int res[50][50][50][50];

int q(int i1, int j1, int i2, int j2)
{
    if (res[i1][j1][i2][j2] == 5)
    {
        cout << "? " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
        string s;
        cin >> s;
        if (s == "0")
            res[i1][j1][i2][j2] = 0;
        else
            res[i1][j1][i2][j2] = 1;
    }
    return res[i1][j1][i2][j2];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y <= n; y++)
                {
                    res[i][j][x][y] = 5;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = 5;
    a[1][1] = 1;
    for (int i = 1; i + 2 <= n; i += 2)
    {
        int r = q(1, i, 1, i + 2);
        if (r == 0)
        {
            a[1][i + 2] = 1 - a[1][i];
        }
        else
        {
            a[1][i + 2] = a[1][i];
        }
    }
    for (int i = 1; i + 2 <= n; i += 2)
    {
        int r = q(i, 1, i + 2, 1);
        if (r == 0)
        {
            a[i + 2][1] = 1 - a[i][1];
        }
        else
        {
            a[i + 2][1] = a[i][1];
        }
    }
    a[1][2] = 3;
    for (int i = 2; i + 2 <= n; i += 2)
    {
        int r = q(1, i, 1, i + 2);
        if (r == 0)
        {
            a[1][i + 2] = 7 - a[1][i];
        }
        else
        {
            a[1][i + 2] = a[1][i];
        }
    }
    for (int i = 1; i + 2 <= n; i += 2)
    {
        int r = q(i, 2, i + 2, 2);
        if (r == 0)
        {
            a[i + 2][2] = 7 - a[i][2];
        }
        else
        {
            a[i + 2][2] = a[i][2];
        }
    }
    for (int dia = -n; dia <= n; dia++)
    {
        for (int i = 1; i <= n; i++)
        {
            int j = i + dia;
            if (1 <= i && i + 1 <= n && 1 <= j && j + 1 <= n)
            {
                int x = q(i, j, i + 1, j + 1);
                if (x == 0)
                {
                    if (a[i][j] == 1)
                    {
                        a[i + 1][j + 1] = 0;
                    }
                    if (a[i][j] == 0)
                    {
                        a[i + 1][j + 1] = 1;
                    }
                    if (a[i][j] == 3)
                    {
                        a[i + 1][j + 1] = 4;
                    }
                    if (a[i][j] == 4)
                    {
                        a[i + 1][j + 1] = 3;
                    }
                    if (a[i + 1][j + 1] == 1)
                    {
                        a[i][j] = 0;
                    }
                    if (a[i + 1][j + 1] == 0)
                    {
                        a[i][j] = 1;
                    }
                    if (a[i + 1][j + 1] == 3)
                    {
                        a[i][j] = 4;
                    }
                    if (a[i + 1][j + 1] == 4)
                    {
                        a[i][j] = 3;
                    }
                }
                else
                {
                    if (a[i][j] == 1)
                    {
                        a[i + 1][j + 1] = 1;
                    }
                    if (a[i][j] == 0)
                    {
                        a[i + 1][j + 1] = 0;
                    }
                    if (a[i][j] == 3)
                    {
                        a[i + 1][j + 1] = 3;
                    }
                    if (a[i][j] == 4)
                    {
                        a[i + 1][j + 1] = 4;
                    }
                    if (a[i + 1][j + 1] == 1)
                    {
                        a[i][j] = 1;
                    }
                    if (a[i + 1][j + 1] == 0)
                    {
                        a[i][j] = 0;
                    }
                    if (a[i + 1][j + 1] == 3)
                    {
                        a[i][j] = 3;
                    }
                    if (a[i + 1][j + 1] == 4)
                    {
                        a[i][j] = 4;
                    }
                }
            }
        }
    }
    int k30 = -1;
    for (int i = 1; i + 2 <= n; i++)
    {
        int t = 1;
        if (a[i][i] != a[i + 1][i + 1] && a[i + 1][i + 1] == a[i + 2][i + 2])
        {
            t = 0;
            int c = (a[i][i + 1] == a[i + 1][i + 2]);
            if (c)
            {
                cout << "? " << i << " " << i + 1 << " " << i + 2 << " " << i + 2 << endl;
                string s;
                cin >> s;
                if (s == "1")
                {
                    // equals (i, i + 1) (i + 2, i + 2)
                    if (a[i][i + 1] == 3 && a[i + 2][i + 2] == 0)
                    {
                        k30 = 1;
                    }
                    else
                    if (a[i][i + 1] == 4 && a[i + 2][i + 2] == 1)
                    {
                        k30 = 1;
                    }
                    else
                        k30 = 0;
                }
                else
                {
                    if (a[i][i + 1] == 3 && a[i + 2][i + 2] == 0)
                    {
                        k30 = 0;
                    }
                    else
                    if (a[i][i + 1] == 4 && a[i + 2][i + 2] == 1)
                    {
                        k30 = 0;
                    }
                    else
                        k30 = 1;
                }
            }
            else
            {
                cout << "? " << i << " " << i << " " << i + 1 << " " << i + 2 << endl;
                string s;
                cin >> s;
                if (s == "1")
                {
                    if (a[i][i] == 0 && a[i + 1][i + 2] == 3)
                        k30 = 1;
                    else
                    if (a[i][i] == 1 && a[i + 1][i + 2] == 4)
                        k30 = 1;
                    else
                        k30 = 0;
                }
                else
                {
                    if (a[i][i] == 0 && a[i + 1][i + 2] == 3)
                        k30 = 0;
                    else
                    if (a[i][i] == 1 && a[i + 1][i + 2] == 4)
                        k30 = 0;
                    else
                        k30 = 1;
                }
            }
        }
        else
        if (a[i][i] == a[i + 1][i + 1] && a[i + 1][i + 1] != a[i + 2][i + 2])
        {
            t = 0;
            int c = (a[i][i + 1] == a[i + 1][i + 2]);
            if (c)
            {
                cout << "? " << i << " " << i << " " << i + 1 << " " << i + 2 << endl;
                string s;
                cin >> s;
                if (s == "1")
                {
                    if (a[i][i] == 0 && a[i + 1][i + 2] == 3)
                        k30 = 1;
                    else
                        if (a[i][i] == 1 && a[i + 1][i + 2] == 4)
                            k30 = 1;
                        else
                            k30 = 0;
                }
                else
                {
                    if (a[i][i] == 0 && a[i + 1][i + 2] == 3)
                        k30 = 0;
                    else
                        if (a[i][i] == 1 && a[i + 1][i + 2] == 4)
                            k30 = 0;
                        else
                            k30 = 1;
                }
            }
            else
            {
                cout << "? " << i << " " << i + 1 << " " << i + 2 << " " << i + 2 << endl;
                string s;
                cin >> s;
                if (s == "1")
                {
                    if (a[i][i + 1] == 3 && a[i + 2][i + 2] == 0)
                    {
                        k30 = 1;
                    }
                    else
                        if (a[i][i + 1] == 4 && a[i + 2][i + 2] == 1)
                            k30 = 1;
                        else
                            k30 = 0;
                }
                else
                {
                    if (a[i][i + 1] == 3 && a[i + 2][i + 2] == 0)
                    {
                        k30 = 0;
                    }
                    else
                        if (a[i][i + 1] == 4 && a[i + 2][i + 2] == 1)
                            k30 = 0;
                        else
                            k30 = 1;
                }
            }
        }
        if (t == 0)
            break;
    }

    cout << "!\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 3 && k30)
            {
                cout << 0;
            }
            if (a[i][j] == 3 && !k30)
            {
                cout << 1;
            }
            if (a[i][j] == 4 && k30)
            {
                cout << 1;
            }
            if (a[i][j] == 4 && !k30)
            {
                cout << 0;
            }
            if (a[i][j] < 2)
                cout << a[i][j];
        }
        cout << endl;
    }
}