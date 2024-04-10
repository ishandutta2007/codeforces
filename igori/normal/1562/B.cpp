#include <bits/stdc++.h>

using namespace std;

int is_prime(int x)
{
    if (x == 1) return 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char c : s)
    {
        if (!is_prime(c - '0'))
        {
            cout << 1 << "\n";
            cout << c << "\n";
            return;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                cout << 2 << "\n";
                cout << s[i] << s[j] << "\n";
                return;
            }
        }
    }
    for (int i = 1; i < (1 << s.size()); i++)
    {
        int x = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if ((1 << j) & i) x = 10 * x + s[j] - '0';
        }
        if (!is_prime(x) && __builtin_popcount(i) == 2)
        {
            cout << __builtin_popcount(i) << "\n";
            cout << x << "\n";
            return;
        }
    }
    for (int i = 1; i < (1 << s.size()); i++)
    {
        int x = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if ((1 << j) & i) x = 10 * x + s[j] - '0';
        }
        if (!is_prime(x) && __builtin_popcount(i) == 3)
        {
            cout << __builtin_popcount(i) << "\n";
            cout << x << "\n";
            return;
        }
    }
    for (int i = 1; i < (1 << s.size()); i++)
    {
        int x = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if ((1 << j) & i) x = 10 * x + s[j] - '0';
        }
        if (!is_prime(x) && __builtin_popcount(i) == 4)
        {
            cout << __builtin_popcount(i) << "\n";
            cout << x << "\n";
            return;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}