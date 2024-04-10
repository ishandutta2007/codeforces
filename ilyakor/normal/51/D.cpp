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

int isgeom(const vector<int64>& v)
{
    if (sz(v) < 2) return 0;
    int64 x = v[1], y = v[0];
    if (y == 0 && x != 0) return 2;
    if (y == 0)
    {
        int cnt = 0;
        for (int i = 2; i < sz(v); ++i)
            if (v[i] != 0) ++cnt;
        if (cnt == 0)
            return 0;
        if (cnt == 1) 
            return 1;
        return 2;
    }
    int cnt = 0;
    int64 px = v[1], py = 1;
    for (int i = 2; i < sz(v); ++i)
    {
        if (cnt >= 2) break;
        int64 tmp = px * x;
        if (abs(tmp) % (y * py) != 0)
        {
            ++cnt;
            continue;
        }
        tmp /= (y * py);
        if (tmp != v[i]) ++cnt;
        else
            px = v[i], py = 1;
    }
    if (cnt == 0)
        return 0;
    if (cnt == 1) 
        return 1;
    return 2;
}

int main()
{
    int n;
    cin >> n;
    vector<int64> v(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        v[i] = x;
    }
    int t = isgeom(v);
    if (t != 2)
    {
        cout << t << "\n";
        return 0;
    }
    vector<int64> w;
    for (int i = 1; i < sz(v); ++i)
        w.pb(v[i]);
    if (isgeom(w) == 0) 
    {
        printf("1\n");
        return 0;
    }
    w.clear();
    for (int i = 0; i < sz(v); ++i)
        if (i != 1)
            w.pb(v[i]);
    if (isgeom(w) == 0) 
    {
        printf("1\n");
        return 0;
    }
    printf("2\n");
    return 0;
}