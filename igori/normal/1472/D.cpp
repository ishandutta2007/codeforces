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
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.rbegin(), a.rend());
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (a[i] % 2 == 0) res += a[i];
            }
            else
            {
                if (a[i] % 2 == 1) res -= a[i];
            }
        }
        if (res < 0) cout << "Bob\n";
        else if (res > 0) cout << "Alice\n";
        else cout << "Tie\n";
    }
}