#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

long long n;
const int K = 708;
int r[K + 1][K + 1];
int v[K * K];
int t, a, b;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> a >> b;
        if (t == 1)
        {
            v[a] += b;
            for (int div = 1; div <= K; div++)
            {
                r[div][a % div] += b;
            }
        }
        else
        {
            if (a > K)
            {
                long long ans = 0;
                for (int pos = b; pos <= 500000; pos += a)
                {
                    ans = ans + v[pos];
                }
                cout << ans << "\n";
            }
            else
            {
                cout << r[a][b] << "\n";
            }
        }
    }
}