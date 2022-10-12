const int MOD = 1e9 + 7;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << "AND 1 2" << endl;
    cout << "OR 1 2" << endl;

    cout << "AND 2 3" << endl;
    cout << "OR 2 3" << endl;

    cout << "AND 1 3" << endl;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    vector<int> ans(n);
    for (int i = 0; (1 << i) < n; i++)
    {
        if (a & (1 << i))
        {
            ans[1] += (1 << i);
            continue;
        }
        if (c & (1 << i))
        {
            ans[1] += (1 << i);
            continue;
        }
        if (!(b & (1 << i))) continue;
        if (!(d & (1 << i))) continue;
        if (!(e & (1 << i)))
        {
            ans[1] += (1 << i);
            continue;
        }
    }
    for (int i = 0; (1 << i) < n; i++)
    {
        if (a & (1 << i))
        {
            ans[0] += (1 << i);
            continue;
        }
        if (!(b & (1 << i)))
        {
            continue;
        }
        ans[0] += (1 << i);
        ans[0] -= (1 << i) & ans[1];
    }
    for (int i = 0; (1 << i) < n; i++)
    {
        if (c & (1 << i))
        {
            ans[2] += (1 << i);
            continue;
        }
        if (!(d & (1 << i)))
        {
            continue;
        }
        ans[2] += (1 << i);
        ans[2] -= (1 << i) & ans[1];
    }
    for (int i = 3; i < n; i++)
    {
        cout << "XOR 2 " << i + 1 << endl;
        int x;
        cin >> x;
        ans[i] = x ^ ans[1];
    }
    cout << "! ";
    for (auto e : ans) cout << e << " "; cout << endl;
}