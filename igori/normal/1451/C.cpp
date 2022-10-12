const int MOD = 1e9 + 7;

#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    vector<int> cnt1(26), cnt2(26);
    for (int i = 0; i < n; i++)
    {
        cnt1[s[i] - 'a']++;
        cnt2[t[i] - 'a']++;
    }
    for (int i = 0; i < 25; i++)
    {
        if (cnt1[i] < cnt2[i])
        {
            cout << "No\n";
            return;
        }
        while (cnt1[i] > cnt2[i])
        {
            if (cnt1[i] < k)
            {
                cout << "No\n";
                return;
            }
            cnt1[i] -= k;
            cnt1[i + 1] += k;
        }
    }
    if (cnt1[25] != cnt2[25])
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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