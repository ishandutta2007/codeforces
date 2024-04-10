#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

long long n, k;
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    string t = "CODEFORCES";
    int x = 10;
    int n = min(x, (int)s.size());
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[i])
            x--;
        else
            break;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[s.size() - i - 1] == t[t.size() - i - 1])
            x--;
        else
            break;
    }
    if (x > 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}