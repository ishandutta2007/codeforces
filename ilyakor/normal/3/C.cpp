#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
//#include <cmath>

#define mp make_pair
#define sz(v)((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x);}
template<class T> T sqr(T x) {return x * x;}

struct pos
{
    int a[3][3];
    pos(){memset(a, 0, sizeof(a));}
    int marshall()
    {
        int res = 0, cur = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                res ^= a[i][j] << (2 * cur);
                cur++;
            }
        return res;
    }
    void unmarshall(int x)
    {
        int cur = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                a[i][j] = (x >> (2 * cur)) & 3;
                cur++;
            }
    }
    int winner()
    {
        for (int i = 0; i < 3; i++)
        {
            if (a[i][0] == 0) continue;
            bool eq = true;
            for (int j = 0; j < 3; j++)
                if (a[i][j] != a[i][0]) eq = false;
            if (eq) return a[i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            if (a[0][i] == 0) continue;
            bool eq = true;
            for (int j = 0; j < 3; j++)
                if (a[j][i] != a[0][i]) eq = false;
            if (eq) return a[0][i];
        }
        if (a[0][0] && a[0][0] == a[1][1] && a[0][0] == a[2][2])
            return a[0][0];
        if (a[0][2] && a[0][2] == a[1][1] && a[0][2] == a[2][0])
            return a[0][2];
        return 0;
    }
    bool draw()
    {
        int c = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (!a[i][j]) c++;
        return c == 0;
    }
    int who()
    {
        int b = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == 1) b++;
                if (a[i][j] == 2) b--;
            }
        return b == 0 ? 1 : 2;
    }
};

set<int> fi, se, fiw, sew, dr;

void dfs(pos p)
{
    int x = p.marshall();
    int w = p.winner();
    if (w)
    {
        if (w == 1) fiw.insert(x);
        else sew.insert(x);
        return;
    }
    if (p.draw())
    {
        dr.insert(x);
        return;
    }
    int who = p.who();
    if (who == 1)
        fi.insert(x);
    else
        se.insert(x);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (p.a[i][j]) continue;
            p.a[i][j] = who;
            dfs(p);
            p.a[i][j] = 0;
        }
}

int main()
{
    pos p;
    dfs(p);
    pos q;
    for (int i = 0; i < 3; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++)
        {
            if (s[j] == 'X') q.a[i][j] = 1;
            else if (s[j] == '0') q.a[i][j] = 2;
            else q.a[i][j] = 0;
        }
    }
    int x = q.marshall();
    if (fi.count(x)) cout << "first\n";
    else if (se.count(x)) cout << "second\n";
    else if (fiw.count(x)) cout << "the first player won\n";
    else if (sew.count(x)) cout << "the second player won\n";
    else if (dr.count(x)) cout << "draw\n";
    else cout << "illegal\n";
    return 0;
}