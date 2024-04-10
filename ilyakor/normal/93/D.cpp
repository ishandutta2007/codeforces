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

bool check2(int m) {
    int m1 = m % 4;
    m /= 4;
    int m2 = m % 4;
    m /= 4;
    if (m1 == m2) return false;
    if (m1 == 0 && m2 == 3) return false;
    if (m1 == 3 && m2 == 0) return false;
    if (m1 == 2 && m2 == 1) return false;
    if (m1 == 1 && m2 == 2) return false;
    return true;
}

bool check3(int m) {
    int m1 = m % 4;
    m /= 4;
    int m2 = m % 4;
    m /= 4;
    int m3 = m % 4;
    m /= 4;
    if (!check2(m1 * 4 + m2)) return false;
    if (!check2(m2 * 4 + m3)) return false;
    if (m1 == 1 && m2 == 0 && m3 == 2) return false;
    if (m1 == 2 && m2 == 0 && m3 == 1) return false;
    return true;
}

const int N = 16;

struct M {
    int64 a[N][N];
    M() {memset(a, 0, sizeof(a)); }
    int64* operator[](int ind) { return a[ind];}
    M operator*(M m) {
        M res;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                for (int k = 0; k < N; ++k)
                    res[i][j] = (res[i][j] + a[i][k] * m[k][j]) % mod;
        return res;
    }
    vector<int64> operator*(vector<int64> v) {
        vector<int64> res(sz(v), 0);
        for (int i = 0; i < sz(v); ++i)
            for (int j = 0; j < sz(v); ++j)
                res[i] = (res[i] + a[i][j] * v[j]) % mod;
        return res;
    }
};

M pw(M a, int64 y) {
    M res;
    for (int i = 0; i < N; ++i)
        res[i][i] = 1;
    while (y) {
        if (y % 2 == 1) --y, res = res * a;
        else y /= 2, a = a * a;
    }
    return res;
}

int64 pw(int64 a, int64 y) {
    int64 res = 1;
    while (y) {
        if (y % 2 == 1) --y, res = (res * a) % mod;
        else y /= 2, a = (a * a) % mod;
    }
    return res;
}

int64 inv(int64 x) {
    return pw(x, mod - 2);
}

bool ok(int m, int ind) {
    if (ind == 0) return false;
    return true;
}

int64 calc(int64 n) {
    if (n == 0) return 0;
    if (n == 1) return 4;
    vi vm;
    for (int i = 0; i < (1 << 6); ++i)
        if (check3(i)) vm.pb(i);
    vi v2;
    for (int i = 0; i < (1 << 4); ++i)
        if (check2(i)) v2.pb(i);
    sort(all(v2));
    M a;
    for (int i = 0; i < sz(v2); ++i) {
        for (int j = 0; j < 4; ++j) {
            int x = v2[i] * 4 + j;
            if (!check3(x)) continue;
            x %= 16;
            ++a[i][lower_bound(all(v2), x) - v2.begin()];
        }
    }
    for (int i = 0; i <= sz(v2); ++i)
        a[sz(v2)][i] = 1;

    vector<int64> v(sz(v2) + 1, 0LL);
    for (int i = 0; i < sz(v2); ++i)
        v[i] = 1;

    vector<int64> tmp;
    tmp = pw(a, n - 1) * v;
    int64 res = tmp[sz(tmp) - 1];
    
    M b = pw(a, (n + 1) / 2 - 1);
    tmp = b * v;
    res += tmp[sz(tmp) - 1];
    res += 8LL;
    res *= inv(2LL);
    res %= mod;
    return res;
}

int main()
{
    int64 l, r;
    cin >> l >> r;
    int64 res = calc(r) - calc(l - 1);
    res %= mod;
    res += mod;
    res %= mod;
    cout << res << "\n";
    return 0;
}