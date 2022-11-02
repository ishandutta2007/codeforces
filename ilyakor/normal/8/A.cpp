#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

char ts[200000];

vi PrefixFunction(string s)
{
    int n = sz(s);
    vi pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

bool check(string& s, string& s1, string& s2)
{
    string t = s1 + "#" + s;
    vi pref = PrefixFunction(t);
    int l = 10000000;
    for (int i = 0; i < sz(s); i++)
        if (pref[sz(s1) + i + 1] >= sz(s1))
        {
            l = i - sz(s1) + 1;
            break;
        }
    if (l > sz(s)) return false;
    t = s2 + "#" + s;
    pref = PrefixFunction(t);
    int r = -10000000;
    for (int i = sz(s) - 1; i >= 0; i--)
        if (pref[sz(s2) + i + 1] >= sz(s2))
        {
            r = i - sz(s2) + 1;
            break;
        }
    if (r < 0) return false;
    //cerr << l << " " << r << "\n";
    return l + sz(s1) - 1 < r;
}

int main()
{
    string s, s1, s2;
    scanf("%s", ts); s = ts;
    scanf("%s", ts); s1 = ts;
    scanf("%s", ts); s2 = ts;
    int res = check(s, s1, s2) ? 1 : 0;
    reverse(all(s));
    res = res * 2 + (check(s, s1, s2) ? 1 : 0);
    char dr[4][100] = {"fantasy", "backward", "forward", "both"};
    printf("%s\n", dr[res]);
    return 0;
}