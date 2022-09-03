#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, s;
    cin >> n >> k;
    s = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s += 2 * a;
    }
    int nn = n;
    while (s < n * (2 * k - 1))
        s += 2 * k, n++;
    cout << n - nn;
    return 0;
}