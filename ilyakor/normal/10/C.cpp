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

const int maxl = 1000100;

int a[10];

int d[maxl];
int p[maxl];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++)
        d[i] = i;
    for (int i = 10; i < maxl; i++)
    {
        int s = 0;
        int x = i;
        while (x)
            s += x % 10, x /= 10;
        d[i] = d[s];
    }
    for (int i = 1; i <= n; i++)
        a[d[i]]++;
    int64 res = 0;
    for (int i = 1; i < 10; i++)
        for (int j = i; j < 10; j++)
        {
            int64 x1 = a[i], x2 = a[j], x3 = a[d[i * j]];
            if (i == j)
                res += x1 * x2 * x3;
            else
                res += 2LL * x1 * x2 * x3;
        }
    p[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        bool ok = false;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
            {
                ok = true;
                int x = i, y = 0;
                while (x % j == 0) x /= j, y++;
                p[i] = p[x] * (y + 1);
                break;
            }
        if (!ok)
            p[i] = 2;
    }
    for (int i = 1; i <= n; i++)
        res -= p[i];
    cout << res << "\n";
    return 0;
}