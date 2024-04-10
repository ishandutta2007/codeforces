#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MOD = 1e9 + 7;

#define all(x) (x).begin(), (x).end()
#define int long long
void update(vector<ll> &b)
{
    for (int j = b.size() - 1; j > 0; j--)
        b[j] -= b[j - 1];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    if (n == 1)
    {
        if (a == b)
        {
            cout << "SMALL\n0\n";
        }
        else
        {
            cout << "IMPOSSIBLE";
        }
        return 0;
    }
    int M = 200000;
    string s = "";
    while (M > 0)
    {
        if (b == a)
            break;
        reverse(all(b));
        if (b == a)
        {
            s += 'R';
            break;
        }
        reverse(all(b));
        int t = 1;
        for (int j = 0; j + 1 < b.size(); j++) if (b[j] >= b[j + 1]) t = 0;
        if (t)
        {
            update(b);
            s += 'P', M--;
        }
        else
        {
            int t = 1;
            reverse(all(b));
            s += 'R';
            for (int j = 0; j + 1 < b.size(); j++) if (b[j] >= b[j + 1]) t = 0;
            if (t == 0)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
            update(b);
            s += 'P', M--;
        }
    }
    if (a == b)
    {
        cout << "SMALL\n";
        cout << s.size() << "\n";
        reverse(all(s));
        cout << s;
        return 0;
    }
    M += 2000000;
    while (M > 0)
    {
        if (b == a)
            break;
        reverse(all(b));
        if (b == a)
        {
            s += 'R';
            break;
        }
        reverse(all(b));
        int t = 1;
        for (int j = 0; j + 1 < b.size(); j++) if (b[j] >= b[j + 1]) t = 0;
        if (t)
        {
            update(b);
            s += 'P', M--;
        }
        else
        {
            int t = 1;
            reverse(all(b));
            s += 'R';
            for (int j = 0; j + 1 < b.size(); j++) if (b[j] >= b[j + 1]) t = 0;
            if (t == 0)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
            update(b);
            s += 'P', M--;
        }
    }
    if (a == b)
    {
        cout << "BIG\n";
        cout << 2200000 - M << "\n";
        return 0;
    }
    assert(n == 2);
    ll op_done = 2200000;
    ll x = b[0], y = b[1];
    ll u = min(a[0], a[1]), v = max(a[0], a[1]);
    while (1)
    {
        if (x == u && y == v)
        {
            cout << "BIG\n";
            cout << op_done;
            return 0;
        }
        if (x > y)
        {
            swap(x, y);
            continue;
        }
        if (x == 0 || x == y)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
        if (x != u)
        {
            op_done += y / x;
            y = y % x;
        }
        else
        {
            ll diff = y - v;
            if (diff >= 0 && diff % x == 0)
            {
                cout << "BIG\n";
                cout << op_done + diff / x;
                return 0;
            }
            else
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
}