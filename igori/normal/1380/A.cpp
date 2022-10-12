#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 506070;
const int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < n; j++)
    {
        int i = -1, k = -1;
        for (int x = 0; x < j; x++)
        {
            if (a[x] < a[j]) i = x;
        }
        for (int x = j + 1; x < n; x++)
        {
            if (a[x] < a[j]) k = x;
        }
        if (i != -1 && k != -1)
        {
            cout << "YES\n";
            cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
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