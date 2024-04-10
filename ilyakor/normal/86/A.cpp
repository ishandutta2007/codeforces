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

int64 calc(int64 x) {
    int64 y = 0;
    vi v;
    int64 t = x;
    while (t)
        v.pb(t % 10), t /= 10;
    for (int i = sz(v) - 1; i >= 0; --i)
        y = y * 10 + (9 - v[i]);
    return x * y;
}

int main()
{
    int64 l, r;
    cin >> l >> r;
    int64 res = max(calc(l), calc(r));
    int64 cur = 1;
    for (int i = 0; i < 12; ++i) {
        cur *= 10;
        int64 x = (cur - 1) / 2;
        int64 y = x + 1;
        int64 z = x - 1;
        if (x >= l && x <= r) res = max(res, calc(x));
        if (y >= l && y <= r) res = max(res, calc(x));
        if (z >= l && z <= r) res = max(res, calc(z));
    }
    cout << res << "\n";
    return 0;
}