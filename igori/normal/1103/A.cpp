#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i != (n); i++)
#define fi first
#define se second
#define pb push_back
#define sz size()

int a[5][5];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            if (a[0][0] == 0)
            {
                cout << "1 1\n";
                a[0][0] = 1;
                a[1][0] = 1;
            }
            else
            {
                cout << "3 1\n";
                a[0][0] = 0;
                a[1][0] = 0;
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                if (a[i][1] == 0)
                {
                    a[i][1] = 1;
                    a[i][2] = 1;
                    cout << i + 1 << " 2\n";
                    if (i == 3)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            a[j][1] = 0;
                            a[j][2] = 0;
                        }
                    }
                    break;
                }
            }
        }
    }
}