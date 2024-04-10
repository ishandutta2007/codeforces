#include <bits/stdc++.h>

using namespace std;

int find_mex(vector<int> a)
{
    vector<int> cnt(a.size() + 1);
    for (int i = 0; i < a.size(); i++) cnt[a[i]]++;
    for (int i = 0; i <= a.size(); i++) if (cnt[i] == 0)
    {
        return i;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> res;
    while (1)
    {
        if (find_mex(a) != n)
        {
            int x = find_mex(a);
            res.push_back(x);
            a[x] = x;
        }
        else
        {
            int tr = -1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != i)
                {
                    tr = i;
                    break;
                }
            }
            if (tr == -1)
                break;
            a[tr] = find_mex(a);
            res.push_back(tr);
        }
    }
    cout << res.size() << "\n";
    for (auto e : res)
    {
        cout << e + 1 << " ";
    }
    cout << "\n";
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