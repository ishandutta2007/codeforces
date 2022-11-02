#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
#include <cassert>
//#include <cmath>

#define mp make_pair
#define sz(v)((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x);}
template<class T> T sqr(T x) {return x * x;}

const int maxn = 1001;
const int inf = 100000000;

char a[maxn][maxn][2];
int d[maxn][maxn];
int from[maxn][maxn];
int n;

int check(int ind)
{
    d[0][0] = a[0][0][ind];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (!i && !j) continue;
            d[i][j] = inf;
            if (i)
            {
                if (d[i][j] > d[i - 1][j] + a[i][j][ind])
                {
                    d[i][j] = d[i - 1][j] + a[i][j][ind];
                    from[i][j] = 1;
                }
            }
            if (j)
            {
                if (d[i][j] > d[i][j - 1] + a[i][j][ind])
                {
                    d[i][j] = d[i][j - 1] + a[i][j][ind];
                    from[i][j] = 2;
                }
            }
        }
    return d[n - 1][n - 1];
}

int main()
{
    cin >> n;
    bool zer = false;
    int zx, zy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int x;
            scanf("%d", &x);
            if (x == 0)
            {
                zer = true;
                zx = i, zy = j;
                continue;
            }
            int p = 0, q = 0;
            while (x % 2 == 0) p++, x /= 2;
            while (x % 5 == 0) q++, x /= 5;
            a[i][j][0] = p, a[i][j][1] = q;
        }
    int r2 = check(0), r5 = check(1);
    int res = min(r2, r5);
    if (zer && res > 1)
    {
        res = 1;
        cout << res << "\n";
        for (int i = 0; i < zx; i++)
            printf("D");
        for (int i = 0; i < zy; i++)
            printf("R");
        for (int i = zx; i < n - 1; i++)
            printf("D");
        for (int i = zy; i < n - 1; i++)
            printf("R");
        printf("\n");
        return 0;
    }
    check(r2 <= r5 ? 0 : 1);
    cout << res << "\n";
    string s;
    int x = n - 1, y = n - 1;
    while (x || y)
    {
        if (from[x][y] == 1)
            x--, s += "D";
        else
            y--, s += "R";
    }
    reverse(all(s));
    cout << s << "\n";
    return 0;
}