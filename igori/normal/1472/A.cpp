#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int w, h, n;
        cin >> w >> h >> n;
        long long p = 1;
        while (w % 2 == 0)
            w /= 2, p *= 2;
        while (h % 2 == 0)
            h /= 2, p *= 2;
        if (p >= n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}