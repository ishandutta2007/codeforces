#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    vector<string> S, T;
    S = {s}, T = {t};
    int c = 50;
    for (int i = 1; i < c; i++)
        S.push_back(S.back() + s);
    for (int i = 1; i < c; i++)
        T.push_back(T.back() + t);
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (S[i] == T[j])
            {
                cout << S[i] << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
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