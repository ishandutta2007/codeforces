#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define prev prev228

void solve()
{
    int n;
    cin >> n;
    cout << 1 << " " << n - 1 << " ";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
    int mx = 0;
    cin >> mx;
    int l = 2, r = n;
    while (l != r)
    {
        int mid = (l + r) / 2;
        cout << 1 << " " << mid - l + 1 << " " << 1 << " ";
        for (int i = l; i <= mid; i++) cout << i << " ";
        cout << endl;
        int x;
        cin >> x;
        if (x == mx) r = mid;
        else l = mid + 1;
    }
    cout << 1 << " " << n - 1 << " ";
    cout << l << " ";
    for (int i = 1; i <= n; i++) if (i != l) cout << i << " ";
    cout << endl;
    int x = 0;
    cin >> x;
    cout << "-1 " << x << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}