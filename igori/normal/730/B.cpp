#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

void solve()
{
    int n;
    cin >> n;
    vector<int> mn, mx;
    for (int i = 1; i + 1 <= n; i += 2)
    {
        cout << "? " << i << " " << i + 1 << endl;
        char c;
        cin >> c;
        if (c == '>')
        {
            mx.push_back(i);
            mn.push_back(i + 1);
        }
        else
        {
            mx.push_back(i + 1);
            mn.push_back(i);
        }
    }
    if (n % 2 == 1) mx.push_back(n), mn.push_back(n);
    while (mx.size() > 1)
    {
        vector<int> mx2;
        for (int i = 0; i + 1 < mx.size(); i += 2)
        {
            cout << "? " << mx[i] << " " << mx[i + 1] << endl;
            char c;
            cin >> c;
            if (c == '>')
            {
                mx2.push_back(mx[i]);
            }
            else
            {
                mx2.push_back(mx[i + 1]);
            }
        }
        if (mx.size() % 2 == 1)
        {
            mx2.push_back(mx.back());
        }
        mx = mx2;
    }
    while (mn.size() > 1)
    {
        vector<int> mn2;
        for (int i = 0; i + 1 < mn.size(); i += 2)
        {
            cout << "? " << mn[i] << " " << mn[i + 1] << endl;
            char c;
            cin >> c;
            if (c == '>')
            {
                mn2.push_back(mn[i + 1]);
            }
            else
            {
                mn2.push_back(mn[i]);
            }
        }
        if (mn.size() % 2 == 1)
        {
            mn2.push_back(mn.back());
        }
        mn = mn2;
    }
    cout << "! " << mn[0] << " " << mx[0] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}