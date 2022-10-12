#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll dx1, dy1, dx2, dy2;
    cin >> dx1 >> dy1 >> dx2 >> dy2;

    if (dx1 == 0 && dy1 == 0)
    {
        cout << "NO\n";
        return 0;
    }
    if (dx2 == 0 && dy2 == 0)
    {
        cout << "NO\n";
        return 0;
    }

    int fl = 0;

    if (dx1 == 0 || dx2 == 0)
    {
        swap(dx1, dy1);
        swap(dx2, dy2);
        fl = 1;
    }
    if (dx1 == 0 || dx2 == 0)
    {
        ll s1 = abs(dx1) + abs(dx2);
        ll s2 = abs(dy1) + abs(dy2);
        if (fl) swap(s1, s2);
        if (n == s1 * s2)
        {
            cout << "YES\n";
            for (int i = 0; i < s1; i++)
            {
                for (int j = 0; j < s2; j++)
                {
                    cout << i << " " << j << "\n";
                }
            }
        }
        else
        {
            cout << "NO\n";
        }
        return 0;
    }

    if (dx1 < 0) dx1 *= -1, dy1 *= -1;
    if (dx2 < 0) dx2 *= -1, dy2 *= -1;

    ll g1 = __gcd(abs(dx1), abs(dy1));
    ll g2 = __gcd(abs(dx2), abs(dy2));

    if (dx1 / g1 == dx2 / g2 && dy1 / g1 == dy2 / g2)
    {
        cout << "NO\n";
        return 0;
    }

    ll de = dx1 * dx2 / __gcd(dx1, dx2);
    ll p1 = dy1 * de / dx1;
    ll p2 = dy2 * de / dx2;

    ll szY = abs(p1 - p2);
    cerr << szY << endl;
    assert(szY != 0);

    ll szX = __gcd(dx1, dx2);

    if (szX * szY != n)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (fl) swap(szX, szY);
    for (int i = 0; i < szX; i++)
    {
        for (int j = 0; j < szY; j++)
        {
            cout << i << " " << j << "\n";
        }
    }
}