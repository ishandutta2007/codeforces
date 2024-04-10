#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long h;
        cin >> h;
        
        vector<long long> a(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        a[n] = a[n - 1] + h + 1;
        
        long long L = 0, R = h + 1;
        while (L + 1 < R)
        {
            long long M = (L + R) / 2;
            long long res = 0;
            for (int i = 0; i < n; i++)
            {
                res += min(M, a[i + 1] - a[i]);
                if (res >= h)
                    break;
            }
            if (res >= h)
                R = M;
            else
                L = M;
        }
        cout << R << "\n";
    }
}