#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define endl "\n"
#define int long long

signed main()
{
    freopen("", "r", stdin);
    freopen("", "w", stdout);
    //I'm reading from files
    int q;
    cin >> q;
    while (q--) // q tests
    {
        long long n, m; // they aren't long long's
        cin >> n >> m;
        long long ans = 0;
        long long kek = 10 * m;
        long long blocks = n / kek; //note I'm dividing wrong
        n %= kek;
        long long res = 0;
        for (int i = 0; i < 10; i++) res += i * m % 10;
        ans = res * blocks;
        for (int i = 0; i < 10; i++) // check this also
        {
            if (i * m <= n)
            {
                ans += i * m % 10;
            }
        }
        cout << ans << "\n";
    }
}