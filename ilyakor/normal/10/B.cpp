#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

int k;

bool a[200][200];

bool can(int x, int y1, int y2)
{
    for (int i = y1; i <= y2; i++)
        if (a[x][i]) return false;
    return true;
}

int main()
{
    int n;
    cin >> n >> k;
    for (int it = 0; it < n; it++)
    {
        int m;
        cin >> m;
        int r = 10000000, rx = -1, ry = -1;
        int xc = k / 2, yc = k / 2;
        for (int i = 0; i < k; i++)
            for (int j = 0; j + m - 1 < k; j++)
                if (can(i, j, j + m - 1))
                {
                    int cur = abs(i - xc) * m;
                    for (int t = j; t < j + m; t++)
                        cur += abs(t - yc);
                    if (cur < r)
                        r = cur, rx = i, ry = j;
                }
        if (rx == -1)
        {
            printf("-1\n");
            continue;
        }
        printf("%d %d %d\n", rx + 1, ry + 1, ry + m);
        for (int i = ry; i < ry + m; i++)
            a[rx][i] = true;
    }
    return 0;
}