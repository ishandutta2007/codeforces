#include <bits/stdc++.h>

using namespace std;

const int N = 500000;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long x = n;
        long long p = 0, ans = 0;
        for (long long i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                int cnt = 0;
                while (x % i == 0)
                {
                    x /= i;
                    cnt++;
                }
                if (cnt > ans)
                {
                    ans = cnt;
                    p = i;
                }
            }
        }
        if (x > 1)
        {
            if (1 > ans)
            {
                ans = 1;
                p = x;
            }
        }
        cout << ans << "\n";
        for (int i = 0; i < ans - 1; i++)
        {
            cout << p << " ";
            n /= p;
        }
        cout << n << "\n";
    }
}