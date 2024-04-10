#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/c++io.h>
#include <cmath>
#include <algorithm>

using namespace std;
#define td typedef
td long long ll;

ll n;
string s;
ll beauty[170];

void recalc()
{
    int iss = 1;
    for (int i = 0; i + 1 < s.size(); i++)
    {
        if (s[i] != s[i + 1])
            iss = 0;
    }
    if (iss == 1)
    {
        beauty[s[0]] = beauty[s[0]] + (beauty[s[0]] + 1) * s.size();
        beauty[s[0]] = min(1000000000LL, beauty[s[0]]);
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (c != s[0])
                beauty[c] = min(beauty[c], 1LL);
        }
        return;
    }
    else
    {
        int pref = 1;
        int suff = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[0])
                pref++;
            else
                break;
        }
        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (s[i] == s[s.size() - 1])
                suff++;
            else
                break;
        }
        if (beauty[s[0]] == 0 && s[0] == s[s.size() - 1])
        {
            beauty[s[0]] = max(pref, suff);
        }
        else
        {
            if (s[0] == s[s.size() - 1])
            {
                beauty[s[0]] = 1 + pref + suff;
            }
            else
            {
                beauty[s[0]] = min(beauty[s[0]], 1LL) + pref;
                beauty[s[s.size() - 1]] = min(beauty[s[s.size() - 1]], 1LL) + suff;
            }
        }
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (c != s[0] && c != s[s.size() - 1])
                beauty[c] = min(beauty[c], 1LL);
        }
        s = s + "%";
        ll cnt = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
            {
                beauty[s[i - 1]] = max(beauty[s[i - 1]], cnt);
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        //s = "a";
        recalc();
    }
    ll ans = 1;
    for (char c = 'a'; c <= 'z'; c++)
    {
        ans = max(ans, beauty[c]);
    }
    cout << ans;
}