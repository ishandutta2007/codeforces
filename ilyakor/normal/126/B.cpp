/*
 * Powered by C++Helper v0.001alpha
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

#ifndef _STRINGS_H
#define _STRINGS_H

vi prefix(string s)
{
    vi res(sz(s), 0);
    for (int i = 1; i < sz(s); ++i)
    {
        int cur = res[i - 1];
        while (cur && s[cur] != s[i])
            cur = res[cur];
        if (s[cur] == s[i])
            ++cur;
        res[i] = cur;
    }
    return res;
}

vi zfunc(string s)
{
    vi res(sz(s), 0);
    int l = 0, r = 0;
    for (int i = 1; i < sz(s); ++i)
 {
        if (i <= r) {
            res[i] = min(r - i + 1, res[i - l]);
        }
        while (i + res[i] < sz(s) && s[res[i]] == s[i + res[i]])
            ++res[i];
        if (i + res[i] - 1 > r)
            l = i, r = i + res[i] - 1;
    }
    return res;
}



vi subpoly(string s)
{
    vi d1(sz(s), 0);
    int l = 0, r = -1;
    for (int i = 0; i < sz(s); ++i)
    {
        int k;
        if (i <= r)
            k = min(d1[l + r - i], r - i) + 1;
        else
            k = 1;
        while (i + k < sz(s) && i - k >= 0 && s[i + k] == s[i - k])
            ++k;
        --k;
        d1[i] = k;
        if (i + k > r)
            l = i - k, r = i + k;
    }
    vi d2(sz(s), 0);
    l = 0, r = -1;
    for (int i = 0; i < sz(s); ++i)
    {
        int k;
        if (i <= r)
            k = min(d2[l + r - i + 1], r - i + 1) + 1;
        else
            k = 1;
        while (i + k - 1 < sz(s) && i - k >= 0 && s[i + k - 1] == s[i - k])
            ++k;
        --k;
        d2[i] = k;
        if (i + k - 1 > r)
            l = i - k, r = i + k - 1;
    }
    d1.insert(d1.end(), all(d2));
    return d1;
}

#endif


int main() {
    string s;
    cin >> s;
    vi z = zfunc(s);
    int M = 0;
    for (int i = 1; i < sz(s) - 1; ++i) {
        int cur = z[i];
        if (i + cur == sz(s)) --cur;
        M = max(M, cur);
    }
    int res;
    for (res = sz(s) - 2; res > 0; --res) {
        if (res > M) continue;
        if (z[sz(s) - res] != res) continue;
        break;
    }
//    cerr << res << "\n";
    if (res <= 0) printf("Just a legend\n");
    else {
        for (int i = 0; i < res; ++i)
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}