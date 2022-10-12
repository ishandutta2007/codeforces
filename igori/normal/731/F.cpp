#include <iostream>

using namespace std;

long long ps[500000];
long long c[500000];

signed main()
{
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long d;
        cin >> d;
        c[d]++;
    }
    ps[0] = c[0];
    for (int i = 1; i <= 400000; i++)
    {
        ps[i] = ps[i - 1] + c[i];
        //cout << ps[i] << " ";
    }
    long long ans = 0;
    for (int i = 1; i <= 200000; i++)
    {
        long long p = 0;
        if (c[i] == 0)
            continue;
        for (int j = 1; (j - 1) * i <= 200000; j++)
        {
            //cout << i * j - 1 << " " << ps[j * i - 1] << " " << ps[j * (i - 1) - 1] << endl;
            p = p + (ps[j * i - 1] - ps[(j - 1) * i - 1]) * (j - 1) * i;
        }
        //cout << i << " " << p << endl;
        ans = max(p, ans);
    }
    cout << ans;
}