#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s += s;
    vector<int> z(2 * n);
    int L = 1, R = 1;
    for (int i = 1; i < 2 * n; i++)
    {
        z[i] = max(0, min(z[i - L], R - i));
        while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] > R)
        {
            R = i + z[i];
            L = i;
        }
    }
    for (int pos = 1; pos < n; pos++)
    {
        if (s[pos + z[pos]] > s[z[pos]])
        {
            for (int i = 0; i < k; i++)
                cout << s[i % pos];
            return 0;
        }
    }
    for (int i = 0; i < k; i++)
        cout << s[i % n];
}