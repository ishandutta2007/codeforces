#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 == s.size() || s[i] < s[i + 1])
        {
            a = i;
            break;
        }
    }
    b = a;
    while (b > 0 && s[b - 1] == s[b]) b--;
    string s1 = "", s2 = "", s3 = "";
    s3 += s[0];
    s3 += s[0];
    for (int i = 0; i <= a; i++) s1 += s[i];
    for (int i = a; i >= 0; i--) s1 += s[i];
    for (int i = 0; i <= b; i++) s2 += s[i];
    for (int i = b; i >= 0; i--) s2 += s[i];
    cout << min({s1, s2, s3}) << "\n";
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