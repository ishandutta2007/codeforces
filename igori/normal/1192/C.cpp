#include <bits/stdc++.h>
using namespace std;
 
int n;
string s[500000], t[500000];
string kek[500000];
long long MOD = 998244353;
 
struct modular{
    long long x;
};
 
modular operator * (modular a, modular b)
{
    a.x = a.x * b.x;
    if (a.x >= MOD)
        a.x %= MOD;
    return a;
}
 
modular operator + (modular a, modular b)
{
    a.x = a.x + b.x;
    if (a.x >= MOD)
        a.x -= MOD;
    return a;
}
 
modular cnt[12][62][62];
modular gen[12][62][62][62];
modular ans;
map<string, int> gg;
 
int figure(char c)
{
    if ('a' <= c && c <= 'z')
        return c - 'a';
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 26;
    return c - '0' + 52;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        t[i] = s[i];
        reverse(t[i].begin(), t[i].end());
        kek[i] = min(s[i], t[i]);
    }
    sort(kek, kek + n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && kek[i] == kek[i - 1]) continue;
        string st = kek[i];
        reverse(st.begin(), st.end());
        cnt[kek[i].size()][figure(kek[i][0])][figure(kek[i][kek[i].size() - 1])].x++;
        if (st != kek[i])
        {
            cnt[kek[i].size()][figure(st[0])][figure(st[kek[i].size() - 1])].x++;
        }
    }
    for (int a = 0; a < 62; a++)
    {
        for (int b = a; b < 62; b++)
        {
            for (int c = b; c < 62; c++)
            {
                for (int M = 0; M < 62; M++)
                {
                    for (int len = 3; len <= 10; len++)
                    {
                        gen[len][a][b][c] = gen[len][a][b][c] + (cnt[len][a][M] * cnt[len][b][M] * cnt[len][c][M]);
                    }
                }
            }
        }
    }
    for (int a = 0; a < 62; a++)
    {
        for (int b = 0; b < 62; b++)
        {
            for (int c = 0; c < 62; c++)
            {
                int x[3] = {a, b, c};
                sort(x, x + 3);
                for (int len = 3; len <= 10; len++)
                {
                    gen[len][a][b][c] = gen[len][x[0]][x[1]][x[2]];
                }
            }
        }
    }
    for (int a = 0; a < 62; a++)
    {
        for (int b = a; b < 62; b++)
        {
            for (int c = b; c < 62; c++)
            {
                for (int d = c; d < 62; d++)
                {
                    modular val;
                    val.x = 0;
                    for (int len = 3; len <= 10; len++)
                        val = val + (gen[len][a][b][c] * gen[len][a][b][d] * gen[len][a][c][d] * gen[len][b][c][d]);
                    modular k;
                    k.x = 24;
                    if (a == d) k.x = 1;
                    else if (a == c || b == d) k.x = 4;
                    if (k.x < 24)
                    {
                        ans = ans + k * val;
                        continue;
                    }
                    if (a == b) k.x /= 2;
                    if (b == c) k.x /= 2;
                    if (c == d) k.x /= 2;
                    ans = ans + k * val;
                }
            }
        }
    }
    cout << ans.x;
}