#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (a < b) swap(a, b);
    while (b > 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{

    int n, m, a[5005], i, b[5005], nod[5005], j;

    cin >> n >> m;

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 1) nod[i] = a[i];
        else nod[i] = gcd(nod[i - 1], a[i]);
       // cout << nod[i] << " ";
    }

    for (i = 1; i <= m; i++)
        cin >> b[i];

    int ans = 0;
    for (i = 1; i <= n; i++)
    {
        int x = a[i];
        for (j = 1; j <= m; j++)
            while (x % b[j] == 0)
        {
            x /= b[j];
            ans--;
        }
        for (j = 2; j * j <= x; j++)
            while (x % j == 0)
        {
            x /= j;
            ans++;
        }
        if (x != 1) ans++;
    }

    //cout << ans;

    int div = 1;

    for (i = n; i >= 1; i--)
    {
        int t = 0, x = nod[i] / div;
        for (j = 1; j <= m; j++)
            while (x % b[j] == 0)
        {
            x /= b[j];
            t--;
        }
        for (j = 2; j * j <= x; j++)
            while (x % j == 0)
        {
            x /= j;
            t++;
        }
        if (x != 1) t++;
        t *= i;
        if (t < 0)
        {
            ans -= t;
            div = nod[i];
        }
        //cout << ans << endl;
    }

    cout << ans;

}