#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int n;
    int ans = 0;
    cin >> n;
    int a[120];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxim = -1, minim = 120;
    for (int i = 0; i < n; i++)
    {
        maxim = max (maxim, a[i]);
        minim = min (minim, a[i]);
    }

    while (a[0] != maxim)
    {
        int nmax;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == maxim) {nmax = i; break;}
        }
        swap (a[nmax], a[nmax - 1]);
        ++ans;
    }

    while (a[n - 1] != minim)
    {
        int nmin;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == minim) {nmin = i; break;}
        }
        swap (a[nmin], a[nmin + 1]);
        ++ans;
    }

    cout << ans;

}