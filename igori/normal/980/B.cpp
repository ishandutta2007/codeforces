#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << "YES\n";
    vector<string> s(4, string(n, '.'));
    int pnt1 = 1, pnt2 = n - 2;
    int r = 1;
    while (k > 2)
    {
        s[r][pnt1] = '#';
        s[r][pnt2] = '#';
        if (r == 1) r++;
        else r = 1, pnt1++, pnt2--;
        k -= 2;
    }
    if (k == 1)
        s[1][n / 2] = '#';
    else if (k == 2)
        s[1][n / 2] = s[2][n / 2] = '#';
    for (int i = 0; i < 4; i++) cout << s[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}