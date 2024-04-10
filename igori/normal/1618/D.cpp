#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int x = n - 2 * k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int kek = 0;
        for (int i = x; i < n; i++) if (a[i] == a[n - k]) kek++;
        cout << accumulate(a.begin(), a.begin() + x, 0ll) + max(0, kek - k) << "\n";
    }
}