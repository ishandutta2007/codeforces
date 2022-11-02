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

vi v;

struct R
{
    int64 x, y;
    R(){}
    R(int64 x, int64 y = 1) : x(x), y(y) {}
    bool operator<(R r)
    {
        return x * r.y < y * r.x;
    }
};

int main()
{
    int n;
    cin >> n;
    v = vi(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    R left(0), right(v[0] + 1);
    for (int i = 0; i < n; ++i)
    {
        R t1(v[i], i + 1);
        if (left < t1)
            left = t1;
        R t2(v[i] + 1, i + 1);
        if (t2 < right)
            right = t2;
    }
    int cur = v[sz(v) - 1] + 1;
    vi v;
    for (int it = 0; it < 1000 * 1000 * 2; ++it)
    {
        R p(cur, n + 1);
        R q(cur + 1, n + 1);
        R M = q < right ? q : right;
        R m = p < left ? left : p;
        if (!(m < M))
        {
            ++cur;
            continue;
        }
        //cerr << cur << "\n";
        v.pb(cur);
        if (sz(v) > 1) break;
        ++cur;
    }
    if (sz(v) > 1)
        cout << "not unique\n";
    else
        cout << "unique\n" << v[0] << "\n";
    return 0;
}