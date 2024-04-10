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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int mn = *min_element(a.begin(), a.end());
        int fl = 0;
        for (int i = 0; i < n / 2 + fl; i++)
        {
            if (a[i] != mn) cout << a[i] << " " << mn << "\n";
            else fl++;
        }
    }
}