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

string s[3];

int64 res = (int64)(1e18);

void go(int n, vector<int64> v)
{
    if (n >= 3)
    {
        res = min(res, v[0]);
        return;
    }
    for (int i = 0; i < sz(v); ++i)
    {
        for (int j = i + 1; j < sz(v); ++j)
        {
            vector<int64> w = v;
            if (s[n] == "+")
                w[i] += w[j];
            else
                w[i] *= w[j];
            w.erase(w.begin() + j, w.begin() + j + 1);
            go(n + 1, w);
        }
    }
}

int main()
{
    int64 a[4];
    for (int i = 0; i < 4; ++i)
        cin >> a[i];
    for (int i = 0; i < 3; ++i)
        cin >> s[i];
    vector<int64> v;
    for (int j = 0; j < 4; ++j)
        v.pb(a[j]);
    go(0, v);
    cout << res << "\n";
    return 0;
}