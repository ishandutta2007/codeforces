#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int ans = 0;
        for (int i = 0; i + 1 < s2.size(); i++)
            ans += abs((int)s1.find(s2[i]) - (int)s1.find(s2[i + 1]));
        cout << ans << "\n";
    }
}