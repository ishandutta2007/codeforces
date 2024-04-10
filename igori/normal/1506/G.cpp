#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> cnt(26);
    vector<int> mask(s.size() + 1);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        mask[i] = mask[i + 1];
        cnt[s[i] - 'a']++;
        if (cnt[s[i] - 'a'] == 1) mask[i] += (1 << (s[i] - 'a'));
    }
    vector<vector<int> > nxt(26, vector<int>(s.size() + 1, s.size()));
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++) nxt[j][i] = nxt[j][i + 1];
        nxt[s[i] - 'a'][i] = i;
    }
    int pos = 0, M = mask[0];
    while (M && pos < s.size())
    {
        for (int j = 25; j >= 0; j--)
        {
            if (M & (1 << j))
            {
                int to = nxt[j][pos];
                if ((mask[to + 1] & (M - (1 << j))) == (M - (1 << j)))
                {
                    cout << (char)(j + 'a');
                    pos = to + 1;
                    M -= (1 << j);
                    break;
                }
            }
        }
    }
    cout << "\n";
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