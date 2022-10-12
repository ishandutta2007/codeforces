#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
ll n, m;
ll a[500000];

bool ok(int x)
{
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        int d = a[i] + x;
        vector<pair<int, int> > segm;
        if (d >= m)
        {
            d -= m;
            segm.push_back({0, d});
            segm.push_back({a[i], m - 1});
        }
        else
        {
            segm.push_back({a[i], d});
        }
        int r = 0;
        for (int j = 0; j < segm.size(); j++)
        {
            if (segm[j].first <= y && y <= segm[j].second)
            {
                r = 1;
                break;
            }
        }
        if (r == 0)
        {
            int ok = 1e9 + 7;
            for (int j = 0; j < segm.size(); j++)
            {
                if (segm[j].first > y && segm[j].first < ok)
                {
                    ok = segm[j].first;
                }
            }
            if (ok == 1e9 + 7)
                return 0;
            y = ok;
        }
    }
    return 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int L = -1, R = m - 1;
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        if (ok(M))
        {
            R = M;
        }
        else
        {
            L = M;
        }
    }
    cout << R;
}