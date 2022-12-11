#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int maxn = 50000;

int main()
{

    string s;
    cin >> s;

    ll d0, d1, d2, d3, d4;
    d0 = d1 = d2 = d3 = d4 = 0;

    ll ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            d2 += d1;
            d4 += d3;
            ++d0;
            d1 = d3 = 0;
        }
        if (s[i] >= '0' && s[i] <= '9')
        {
            d2 += d1;
            d1 = d3 = d4 = 0;
        }
        if (s[i] == '_')
        {
            d1 = d2 = d3 = d4 = 0;
        }
        if (s[i] == '@')
        {
            d1 = d0;
            d0 = d2 = d3 = d4 = 0;
        }
        if (s[i] == '.')
        {
            d3 = d2;
            d0 = d1 = d2 = d4 = 0;
        }
        ans += d4;
    }

    cout << ans;

}