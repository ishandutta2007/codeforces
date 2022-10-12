#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()

int main()
{
    string s;
    cin >> s;
    string g = "";
    int c1 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1') c1++;
        else g += s[i];
    }
    int fl = 0;
    for (int i = 0; i < g.size(); i++)
    {
        if (g[i] == '2' && !fl)
        {
            cout << string(c1, '1');
            fl = 1;
        }
        cout << g[i];
    }
    if (!fl) cout << string(c1, '1');
}