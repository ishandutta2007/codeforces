#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

int n;
string s, t, m;
int dp[1200][60][60];
int aS, aT;
int goS[60][160];
int goT[60][160];

bool sims(int x1, int x2, int y1, int y2)
{
    for (int i = 0; i < x2 - x1; i++)
    {
        if (s[x1 + i] != s[y1 + i])
            return 0;
    }
    return 1;
}

bool simt(int x1, int x2, int y1, int y2)
{
    for (int i = 0; i < x2 - x1; i++)
    {
        if (t[x1 + i] != t[y1 + i])
            return 0;
    }
    return 1;
}

void run(int i, int j, int k, char c)
{
    int ni = i + 1;
    int nj = 0;
    int nk = 0;
    int delta = 0;
    nj = goS[j][c];
    if (nj == s.size())
    {
        nj = aS;
        delta++;
    }
    nk = goT[k][c];
    if (nk == t.size())
    {
        nk = aT;
        delta--;
    }
    dp[ni][nj][nk] = max(dp[ni][nj][nk], dp[i][j][k] + delta);
}

int main()
{
    cin >> m >> s >> t;
    for (int i = 0; i < s.size(); i++)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int prlen = 0; prlen <= i; prlen++)
            {
                int t = 1;
                if (s[prlen] != c)
                    t = 0;
                for (int kk = 0; kk < prlen; kk++)
                    if (s[kk] != s[i - prlen + kk])
                        t = 0;
                if (t)
                    goS[i][c] = prlen + 1;
            }
            //cout << i << " " << c << " " << goS[i][c] << endl;
        }
    }

    for (int i = 0; i < t.size(); i++)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int prlen = 0; prlen <= i; prlen++)
            {
                int tr = 1;
                if (t[prlen] != c)
                    tr = 0;
                for (int kk = 0; kk < prlen; kk++)
                    if (t[kk] != t[i - prlen + kk])
                        tr = 0;
                if (tr)
                    goT[i][c] = prlen + 1;
            }
        }
    }

    for (int i = 0; i < 1200; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            for (int k = 0; k < 60; k++)
            {
                dp[i][j][k] = -10000;
            }
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (sims(0, i, s.size() - i, s.size()))
            aS = i;
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (simt(0, i, t.size() - i, t.size()))
            aT = i;
    }
    //cout << aS << " " << aT << endl;
    dp[0][0][0] = 0;
    for (int i = 0; i < m.size(); i++)
    {
        char c = m[i];
        for (int j = 0; j <= s.size(); j++)
        {
            for (int k = 0; k <= t.size(); k++)
            {
                if (c == '*')
                {
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        run(i, j, k, c);
                    }
                }
                else
                {
                    run(i, j, k, c);
                }
            }
        }
    }
    int ans = -10000;
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            ans = max(ans, dp[m.size()][i][j]);
        }
    }
    cout << ans;
}