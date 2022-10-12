#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 506070;
const int MOD = 998244353;

void solve()
{
    string a;
    cin >> a;
    int r = 0, s = 0, p = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'R') r++;
        if (a[i] == 'S') s++;
        if (a[i] == 'P') p++;
    }
    if (r >= s && r >= p)
    {
        for (int i = 0; i < a.size(); i++) cout << "P";
        cout << "\n";
    }
    else if (s >= r && s >= p)
    {
        for (int i = 0; i < a.size(); i++) cout << "R";
        cout << "\n";
    }
    else if (p >= r && p >= s)
    {
        for (int i = 0; i < a.size(); i++) cout << "S";
        cout << "\n";
    }
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