#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = s;
        sort(t.begin(), t.end());
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
            ans += s[i] != t[i];
        cout << ans << "\n";
    }
}