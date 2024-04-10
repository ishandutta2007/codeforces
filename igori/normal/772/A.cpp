#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long double n, k;
long double a[100002];
long double b[100002];

const long double INF = 1e15 + 1;

int check(long double& mid)
{
    long double s = 0;
    for (int i = 0; i < n; i++)
    {
        long double need = a[i] * mid - b[i];
        if (need > 0)
            s += need;
        if (s > mid * k)
            return 0;
    }
    return 1;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    long long fff = 0;
    for (int i = 0; i < n; i++)
    {
        fff += a[i];
    }
    if (fff <= k)
    {
        cout << -1;
        return 0;
    }
    long double r = 0, l = INF;
    int op = 0;
    while (l > r + 0.00001)
    {
        long double mid = (r + l) / 2;
        //cout << r << ' ' << l << endl;
        op++;
        if (op == 95)
            break;
        if (check(mid) == 0)
            l = mid;
        else
            r = mid;
    }
    cout << l;
}