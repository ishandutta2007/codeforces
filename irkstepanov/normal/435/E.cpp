#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <bitset>

#define pb push_back

using namespace std;

int n, m;

bool try_line (vector <vector <char> > &a)
{

    int b[5] = {0, 0, 0, 0, 0};

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int x = a[i][j] - '0';
            if (x && b[x] && b[x] != 2 - (i % 2)) return false;
            else b[x] = 2 - (i % 2);
        }

    int kol[3] = {0, 0, 0};
    for (int i = 1; i <= 4; i++)
        ++kol[b[i]];
    if (kol[2] > 2 || kol[1] > 2) return false;

    for (int i = 1; i <= 4; i++)
    {
        if (!b[i])
        {
            if (kol[2] < 2)
            {
                b[i] = 2;
                ++kol[2];
            }
            else
            {
                b[i] = 1;
                ++kol[1];
            }
        }
    }

    vector <vector <char> > ans(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++)
    {
        char c1 = '0', c2 = '0';
        for (int j = 1; j <= 4; j++)
            if (b[j] == 2 - (i % 2))
        {
            if (c1 == '0') c1 = (char) (j + '0');
            else c2 = (char) (j + '0');
        }
        bool ok = true;
        for (int j = 1; j <= m; j++)
        {
            if (j % 2 && a[i][j] != '0' && a[i][j] != c1) ok = false;
            if (!(j % 2) && a[i][j] != '0' && a[i][j] != c2) ok = false;
        }
        if (ok)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j % 2) ans[i][j] = c1;
                else ans[i][j] = c2;
            }
        }
        else
        {
            ok = true;
            for (int j = 1; j <= m; j++)
            {
                if (j % 2 && a[i][j] != '0' && a[i][j] != c2) ok = false;
                if (!(j % 2) && a[i][j] != '0' && a[i][j] != c1) ok = false;
            }
            if (ok)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (j % 2) ans[i][j] = c2;
                    else ans[i][j] = c1;
                }
            }
            else return false;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%c", ans[i][j]);
        printf("\n");
    }

    return true;

}

bool try_col (vector <vector <char> > &a)
{

    int b[5] = {0, 0, 0, 0, 0};

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int x = a[i][j] - '0';
            if (x && b[x] && b[x] != 2 - (j % 2)) return false;
            else b[x] = 2 - (j % 2);
        }

    int kol[3] = {0, 0, 0};
    for (int i = 1; i <= 4; i++)
        ++kol[b[i]];
    if (kol[2] > 2 || kol[1] > 2) return false;

    for (int i = 1; i <= 4; i++)
    {
        if (!b[i])
        {
            if (kol[2] < 2)
            {
                b[i] = 2;
                ++kol[2];
            }
            else
            {
                b[i] = 1;
                ++kol[1];
            }
        }
    }

    vector <vector <char> > ans(n + 1, vector <char> (m + 1));
    for (int j = 1; j <= m; j++)
    {
        char c1 = '0', c2 = '0';
        for (int i = 1; i <= 4; i++)
            if (b[i] == 2 - (j % 2))
        {
            if (c1 == '0') c1 = (char) (i + '0');
            else c2 = (char) (i + '0');
        }
        //cout << j << " " << c1 << " " << c2 << "\n";
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 && a[i][j] != '0' && a[i][j] != c1) ok = false;
            if (!(i % 2) && a[i][j] != '0' && a[i][j] != c2) ok = false;
        }
        if (ok)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i % 2) ans[i][j] = c1;
                else ans[i][j] = c2;
            }
        }
        else
        {
            ok = true;
            for (int i = 1; i <= n; i++)
            {
                if (i % 2 && a[i][j] != '0' && a[i][j] != c2) ok = false;
                if (!(i % 2) && a[i][j] != '0' && a[i][j] != c1) ok = false;
            }
            if (ok)
            {
                for (int i = 1; i <= n; i++)
                {
                    if (i % 2) ans[i][j] = c2;
                    else ans[i][j] = c1;
                }
            }
            else return false;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%c", ans[i][j]);
        printf("\n");
    }

    return true;

}

int main()
{

    scanf("%d%d", &n, &m);
    scanf("\n");
    vector <vector <char> > a(n + 2, vector <char> (m + 2));

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
        a[i][j] = '0';

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
        scanf("%c", &a[i][j]);
        if (i != n) scanf("\n");
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        if (a[i][j] != '0')
    {
        if (a[i][j] == a[i - 1][j] || a[i][j] == a[i + 1][j] || a[i][j] == a[i][j - 1] || a[i][j] == a[i][j + 1])
        {
            printf("0");
            return 0;
        }
    }

    if (try_line(a)) return 0;
    if (try_col(a)) return 0;

    printf("0");

}