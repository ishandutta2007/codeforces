#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    map<string, set<int> > mm;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int l = 0; l < s[i].size(); l++)
        {
            string t = "";
            for (int r = l; r < s[i].size(); r++)
            {
                t += s[i][r];
                mm[t].insert(i);
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        string S;
        cin >> S;
        cout << mm[S].size() << " ";
        if (mm[S].size() == 0) cout << "-\n";
        else cout << s[*mm[S].begin()] << "\n";
    }
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