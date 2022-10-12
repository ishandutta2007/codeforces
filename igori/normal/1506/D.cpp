#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> cnt;
        for (int i = 0; i < n; i++)
            cin >> a[i], cnt[a[i]]++;
        int fl = -1;
        for (auto it : cnt)
            if (it.second * 2 > n) fl = n - 2 * (n - it.second);

        if (fl == -1)
            cout << n % 2 << "\n";
        else
            cout << fl << "\n";
    }
}