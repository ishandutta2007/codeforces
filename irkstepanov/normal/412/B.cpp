#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
ll mod = 1000000007;
ll inf = 1000000000;

struct pt
{
    double x, y;
};

double dist (pt a, pt b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool smaller (double a, double b)
{
    return (b - a >= 0.000001);
}

set <int> p;

void f (int n, map <int, int> &mapn)
{
    for (int d = 2; d * d <= n; d++)
    {
        if (n % d == 0) p.insert(d);
        while (n % d == 0)
        {
            n /= d;
            ++mapn[d];
        }
    }
    if (n > 1)
    {
        ++mapn[n];
        p.insert(n);
    }
}

int main()
{

    int n, k;
    cin >> n >> k;

    int a[100500];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int kol = 0;
        for (int j = 0; j < n; j++)
            kol += (a[j] >= a[i]);

        if (kol >= k) ans = max(ans, a[i]);
    }

    cout << ans;

}