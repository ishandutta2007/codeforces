#include <bits/stdc++.h>

using namespace std;

int gett(string s)
{
    int ans = 0;
    for (int i = 0; i < (int)s.size() - 1; i++)
        if (s[i] == 'V' && s[i + 1] == 'K')
            ans++;
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int ans = gett(s);
    for (int i = 0; i < (int)s.size(); i++)
    {
        for (char x = 'A'; x < 'Z'; x++)
        {
            char q = s[i];
            s[i] = x;
            ans = max(ans, gett(s));
            s[i] = q;
        }
    }
    cout << ans;
    return 0;
}