#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l;
    cin >> l;

    vector<ll> cur;
    vector<ll> cur_not_1;

    ll x = 0;

    const ll LIM = (1ll << 32);

    for (int i = 0; i < l; i++)
    {
        string s;
        cin >> s;
        if (s == "for")
        {
            ll c;
            cin >> c;
            cur.push_back(c);
            if (c > 1) cur_not_1.push_back(c);
        }
        if (s == "add")
        {
            ll val = 1;
            for (auto e : cur_not_1)
            {
                val = val * e;
                if (val >= LIM) val = LIM;
            }
            x += val;
            if (x >= LIM)
            {
                cout << "OVERFLOW!!!";
                return 0;
            }
        }
        if (s == "end")
        {
            if (cur.back() > 1)
                cur_not_1.pop_back();
            cur.pop_back();
        }
    }
    cout << x << "\n";
}