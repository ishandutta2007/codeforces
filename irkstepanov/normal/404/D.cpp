#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
ll mod = 1000000007;

int main()
{

    ll otv[5] = {0, 0, 0, 0, 0};

    string s;
    cin >> s;
    char c = s[0];

    if (c == '*') otv[4] = 1;
    if (c == '?')
    {
        otv[0] = otv[2] = otv[4] = 1;
    }
    if (c == '0') otv[0] = 1;
    if (c == '1') otv[2] = 1;

    for (int j = 1; j < s.size(); j++)
    {
        c = s[j];
        ll ans[5] = {0, 0, 0, 0, 0};
        if (c == '0') ans[0] = (otv[0] + otv[1]) % mod;
        if (c == '1')
        {
            ans[1] = otv[4];
            ans[2] = (otv[0] + otv[1]) % mod;
        }
        if (c == '2') ans[3] = otv[4];
        if (c == '*') ans[4] = (otv[2] + otv[3] + otv[4]) % mod;
        if (c == '?')
        {
            ans[0] = (otv[0] + otv[1]) % mod;
            ans[1] = otv[4];
            ans[2] = (otv[0] + otv[1]) % mod;
            ans[3] = otv[4];
            ans[4] = (otv[2] + otv[3] + otv[4]) % mod;
        }
        for (int i = 0; i < 5; i++)
            otv[i] = ans[i];
    }

    cout << (otv[0] + otv[1] + otv[4]) % mod;

}