#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < n && a[j] - a[i] <= d)
            j++;
        ans += (j - i - 1);
    }
    cout << ans * 2 << "\n";
}