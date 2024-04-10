#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) cout << a[i] << " " << a[2 * n - 1 - i] << " ";
    cout << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}