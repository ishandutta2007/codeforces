#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int x = 0;
    for (int i = 0; i < (int)s1.size(); i++)
    {
        if (s1[i] == '0' && s2[i] == '0')
        {
            if (i - 1 >= 0 && s1[i - 1] == '0')
            {
                s1[i - 1] = 'X';
                s1[i] = 'X';
                s2[i] = 'X';
                x++;
            }
            else if (i - 1 >= 0 && s2[i - 1] == '0')
            {
                s2[i - 1] = 'X';
                s1[i] = 'X';
                s2[i] = 'X';
                x++;
            }
            else if (i + 1 < (int)s1.size() && s1[i + 1] == '0')
            {
                s1[i + 1] = 'X';
                s1[i] = 'X';
                s2[i] = 'X';
                x++;
            }
            else if (i + 1 < (int)s1.size() && s2[i + 1] == '0')
            {
                s2[i + 1] = 'X';
                s1[i] = 'X';
                s2[i] = 'X';
                x++;
            }
        }
    }
    cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}