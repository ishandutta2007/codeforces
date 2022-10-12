#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

void go(char c, int &x, int &y)
{
    if (c == 'R') x++;
    if (c == 'L') x--;
    if (c == 'U') y++;
    if (c == 'D') y--;
}

void go_obs(char c, int &x, int &y, int ox, int oy)
{
    if (c == 'R' && (x + 1 != ox || y != oy)) x++;
    if (c == 'L' && (x - 1 != ox || y != oy)) x--;
    if (c == 'U' && (x != ox || y + 1 != oy)) y++;
    if (c == 'D' && (x != ox || y - 1 != oy)) y--;
}

int sim(string s, int lx, int ly)
{
    int x = 0, y = 0;
    for (int i = 0; i < s.size(); i++)
        go_obs(s[i], x, y, lx, ly);
    return (x == 0 && y == 0);
}

void solve()
{
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i < s.size(); i++)
    {
        go(s[i], x, y);
        if (x != 0 || y != 0)
        {
            if (sim(s, x, y))
            {
                cout << x << " " << y << "\n";
                return;
            }
        }
    }
    cout << "0 0\n";
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