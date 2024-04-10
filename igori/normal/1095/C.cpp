#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int a[4000000];

int main()
{
    int n, k;
    cin >> n >> k;
    long long d = (1LL << 32);
    int x = 0;
    if (k > n)
    {
        cout << "NO";
        return 0;
    }
    while (d >= 1)
    {
        if (d <= n)
        {
            n -= d;
            a[x] = d;
            x++;
        }
        d /= 2;
    }
    if (x > k)
    {
        cout << "NO";
        return 0;
    }
    int i = 0;
    while (x < k)
    {
        if (a[i] > 1)
        {
            a[x] = a[i] / 2;
            a[i] /= 2;
            x++;
        }
        else
        {
            i++;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << " ";
    }

}