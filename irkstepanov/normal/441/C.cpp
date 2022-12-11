#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <int, int> pii;

int main()
{

    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    int x = 1, y = 1;

    vector <pii> v;
    while (x <= n && y <= m)
    {
        v.pb(mp(x, y));
        if (y == 1 && x % 2 == 0) ++x;
        else if (y == m && x % 2) ++x;
        else
        {
            if (x % 2) ++y;
            else --y;
        }
    }

    int pos = 0;
    for (int i = 1; i < k; i++)
    {
        cout << "2 ";
        cout << v[pos].first << " " << v[pos].second << " " << v[pos + 1].first << " " << v[pos + 1].second << "\n";
        pos += 2;
    }

    cout << (int) v.size() - pos << " ";
    for (; pos < v.size(); pos++)
        cout << v[pos].first << " " << v[pos].second << " ";

}