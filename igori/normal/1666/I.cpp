const long long INFLL = 1e18;
const long long MOD = 998244353;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define uniq(x) sort(all(x)); x.resize(unique(all(x)) - (x).begin())

void solve()
{
    auto dist = [&](int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    };

    int n = 16, m = 16;
    cin >> n >> m;

    // verify
    vector<vector<int> > states;
    forn(x1, n) forn(y1, m)
    forn(x2, n) forn(y2, m)
    {
        pair<int, int> A = {x1, y1}, B = {x2, y2};
        if (A >= B) continue;
        states.push_back({x1, y1, x2, y2});
    }
    int fl = 0;
    int Q = 5;
    while (states.size() > 1)
    {
        int opt = states.size();
        int optX = 0, optY = 0;
        if (fl == 1)
        {
            forn(i, n) forn(j, m)
            {
                vector<int> cnt(64);
                for (auto e : states)
                {
                    cnt[dist(i, j, e[0], e[1]) + dist(i, j, e[2], e[3])]++;
                }
                int mx = *max_element(all(cnt));
                if (mx < opt)
                {
                    opt = mx, optX = i, optY = j;
                }
            }
        }
        if (Q == 0) exit(1);
        cout << "SCAN " << optX + 1 << " " << optY + 1 << endl;
        Q--;
        int res;
        cin >> res;
        vector<vector<int> > states2;
        for (auto e : states)
        {
            if (dist(optX, optY, e[0], e[1]) + dist(optX, optY, e[2], e[3]) == res)
                states2.push_back(e);
        }
        states = states2;
        fl = 1;
        if (states.size() == 2 && Q == 1)
        {
            break;
        }
    }
    if (states.size() == 1)
    {
        cout << "DIG " << states[0][0] + 1 << " " << states[0][1] + 1 << endl;
        int x;
        cin >> x;
        assert(x == 1);
        cout << "DIG " << states[0][2] + 1 << " " << states[0][3] + 1 << endl;
        x;
        cin >> x;
        assert(x == 1);
    }
    else
    {
        cout << "DIG " << states[0][0] + 1 << " " << states[0][1] + 1 << endl;
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << "DIG " << states[0][2] + 1 << " " << states[0][3] + 1 << endl;
            x;
            cin >> x;
            assert(x == 1);
        }
        else
        {
            cout << "DIG " << states[1][0] + 1 << " " << states[1][1] + 1 << endl;
            int x;
            cin >> x;
            assert(x == 1);
            cout << "DIG " << states[1][2] + 1 << " " << states[1][3] + 1 << endl;
            x;
            cin >> x;
            assert(x == 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}