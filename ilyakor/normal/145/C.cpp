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

const int mod = 1000000007;

vector<int64> gen() {
    vector<int64> res;
    for (int len = 1; len <= 11; ++len)
        for (int mask = 0; mask < (1 << len); ++mask) {
            int64 cur = 0;
            for (int i = 0; i < len; ++i)
                cur = cur * 10LL + (int64) (((mask >> i) & 1) ? 7 : 4);
            res.pb(cur);
        }

    sort(all(res));

    return res;
}

const int maxn = 218 * 1000;

int64 fact[maxn], rf[maxn];

int64 pw(int64 x, int64 y) {
    int64 res = 1;
    while (y) {
        if (y % 2)
            --y, res = (res * x) % mod;
        else
            y /= 2, x = (x * x) % mod;
    }
    return res;
}

int64 rev(int64 x) {
    return pw(x, mod - 2);
}

int main()
{
    fact[0] = rf[0] = 1;
    for(int i = 1; i < maxn; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
        rf[i] = rev(fact[i]);
    }

    vector<int64> vl = gen();
    vi v;
    map<int, int> M;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (binary_search(all(vl), (int64)x))
            ++M[x];
        else
            v.pb(x);
    }

    vector<int64> d(k + 1, 0);
    d[0] = 1;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        int x = it->first;
        int64 y = it->second;
        for (int i = k - 1; i >= 0; --i) if (d[i])
            d[i + 1] = (d[i + 1] + d[i] * y) % mod;
    }

    int64 res = 0;

    for (int i = 0; i <= k; ++i) {
        if (k - i > sz(v)) continue;
        int64 x = d[i];
        x *= fact[sz(v)];
        x %= mod;
        x *= rf[k - i];
        x %= mod;
        x *= rf[sz(v) - (k - i)];
        x %= mod;
        res += x;
        res %= mod;
    }

    cout << res << "\n";

    return 0;
}