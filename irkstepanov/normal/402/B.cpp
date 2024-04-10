#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{

    int n, k, m[1200], i, l, ans = 99999999, l0;

    cin >> n >> k;
    for (i = 1; i <= n; i++)
        cin >> m[i];

    for (l = 1; l <= n; l++)
    {
        int x = 0;
        for (i = l - 1; i >= 1; i--)
        {
            if (m[i] != m[l] - k * (l - i)) x++;
            if (m[l] - k * (l - i) <= 0) x = ans;
        }
        for (i = l + 1; i <= n; i++)
            if (m[i] != m[l] + k * (i - l)) x++;
        if (ans > x) {ans = x; l0 = l;}
    }

    cout << ans << endl;
    for (i = 1; i < l0; i++)
        if (m[i] != m[l0] - k * (l0 - i))
    {
        if (m[i] > m[l0] - k * (l0 - i)) cout << '-' << " " << i << " " << m[i] - (m[l0] - k * (l0 - i)) << endl;
        else cout << '+' << " " << i << " " << m[l0] - k * (l0 - i) - m[i] << endl;
    }

    for (i = l0 + 1; i <= n; i++)
        if (m[i] != k * (i - l0) + m[l0])
    {
        if (m[i] > k * (i - l0) + m[l0]) cout << '-' << " " << i << " " << m[i] - (k * (i - l0) + m[l0]) << endl;
        else cout << '+' << " " << i << " " << k * (i - l0) + m[l0] - m[i] << endl;
    }

}