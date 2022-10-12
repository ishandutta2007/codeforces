#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    string s, t;
    cin >> s >> t;
    vector<int> cnt(257);
    for (int i = 0; i < t.size(); i++)
        cnt[t[i]]++;
    string g = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (cnt[s[i]] > 0)
        {
            g += s[i];
            cnt[s[i]]--;
        }
    }
    reverse(g.begin(), g.end());
    if (g == t) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}