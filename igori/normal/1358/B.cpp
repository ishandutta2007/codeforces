#include <bits/stdc++.h>

const int N = 100005;

using namespace std;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= i + 1) c = i + 1;
    }
    cout << c + 1 << "\n";
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