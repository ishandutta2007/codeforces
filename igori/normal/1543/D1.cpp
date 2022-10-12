#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        cout << (i ^ tot) << endl;
        int res;
        cin >> res;
        if (res == 1)
            break;
        tot ^= (i ^ tot);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}