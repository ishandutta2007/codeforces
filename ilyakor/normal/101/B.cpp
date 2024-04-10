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

const int64 mod = 1000000007LL;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ii> v(m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &v[i].second, &v[i].first);
    sort(all(v));
    vector<int64> d(sz(v), 0);
    vector<int64> s(sz(v), 0);
    int64 res = 0;
    for (int i = 0; i < sz(v); ++i) {
        int64 val = 0;
        if (v[i].second <= 0) ++val;

        int r = v[i].first, l = v[i].second;
        int indL = lower_bound(all(v), ii(l, -100000)) - v.begin();
        int indR = lower_bound(all(v), ii(r, -100000)) - v.begin();
        int64 sL = indL == 0 ? 0LL : s[indL - 1];
        int64 sR = indR == 0 ? 0LL : s[indR - 1];
        val += sR - sL;
        val %= mod;
        val += mod;
        val %= mod;


        d[i] = val % mod;
        if (i > 0) s[i] = s[i - 1];
        s[i] += d[i];
        s[i] %= mod;

        if (v[i].first == n)
            res = (res + val) % mod;
    }
    cout << res << "\n";
    return 0;
}