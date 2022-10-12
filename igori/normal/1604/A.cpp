#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int mx = 0;
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            mx = max(mx, a - j);
        }
        cout << mx << "\n";
    }
}