#include <bits/stdc++.h>

using namespace std;

vector<int> bin(long long x)
{
    vector<int> a;
    while (x > 0)
    {
        a.push_back(x % 2);
        x /= 2;
    }
    reverse(a.begin(), a.end());
    return a;
}

int main()
{
    long long x, y;
    cin >> x >> y;
    if (x == y)
    {
        cout << "YES\n";
        return 0;
    }
    vector<int> a = bin(x), b = bin(y);
    //for (auto e : a) cout << e; cout << "\n";
    //for (auto e : b) cout << e; cout << "\n";
    a.push_back(1);
    for (int ii = 0; ii < 2; ii++)
    {
        for (int pos = 0; pos < b.size(); pos++)
        {
            int t = 1;
            for (int i = 0; i < pos; i++) if (b[i] == 0) t = 0;
            for (int i = 0; i < a.size(); i++)
            {
                if (pos + i >= b.size()) t = 0;
                else if (b[pos + i] != a[i]) t = 0;
            }
            for (int i = pos + a.size(); i < b.size(); i++) if (b[i] == 0) t = 0;
            if (t)
            {
                cout << "YES\n";
                return 0;
            }
        }
        reverse(a.begin(), a.end());
        for (int pos = 0; pos < b.size(); pos++)
        {
            int t = 1;
            for (int i = 0; i < pos; i++) if (b[i] == 0) t = 0;
            for (int i = 0; i < a.size(); i++)
            {
                if (pos + i >= b.size()) t = 0;
                else if (b[pos + i] != a[i]) t = 0;
            }
            for (int i = pos + a.size(); i < b.size(); i++) if (b[i] == 0) t = 0;
            if (t)
            {
                cout << "YES\n";
                return 0;
            }
        }
        reverse(a.begin(), a.end());
        a.pop_back();
        while (a.size() && a.back() == 0)
            a.pop_back();
    }
    cout << "NO\n";
}