#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    if (s == t)
        cout << "0\n";
    else
    {
        vector<int> pos;
        for (int i = 0; i < n; i++) if (s[i] != t[i]) pos.push_back(i);
        cout << 1 << "\n";
        cout << pos.size() << " ";
        for (auto e : pos) cout << e + 1 << " ";
        cout << "\n";
    }
}

int main()
{
    const int N = 1e6;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}