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
        int n, x;
        cin >> n >> x;
        long long tot = 0, si = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            tot += a;
            si += (a + x - 1) / x;
        }
        cout << (tot + x - 1) / x << " " << si << "\n";
    }
}