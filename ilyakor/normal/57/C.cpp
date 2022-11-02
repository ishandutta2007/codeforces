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

const int64 mod = 1000000007;

int64 pw(int64 x, int64 y)
{
    int64 res = 1;
    while (y)
    {
        if (y % 2 == 1)
            res = (res * x) % mod, --y;
        else
            x = (x * x) % mod, y /= 2;
    }
    return res;
}

int64 C(int n, int k)
{
    int64 p = 1, q = 1;
    for (int i = n; i >= n - k + 1; --i)
        p = (p * (int64)i) % mod;
    for (int i = 1; i <= k; ++i)
        q = (q * (int64)i) % mod;
    q = pw(q, mod - 2);
    p *= q;
    p %= mod;
    return p;
}

int main()
{
    int n;
    cin >> n;
    --n;
    int64 res = C(2 * n + 1, n + 1);
    res *= 2;
    res -= n + 1;
    res %= mod;
    res += mod;
    res %= mod;
    cout << res << "\n";
    return 0;
}