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

const int maxn = 1000 * 1000 * 2;
const int BUBEN = 40;

int64 fib[BUBEN];

int a[maxn];

int n;
int64 X, Y;
int64 P;

struct M
{
    int64 a[2][2];
    M(){memset(a, 0, sizeof(a));}
    int64* operator[](int x)
    {
        return a[x];
    }
    M operator*(M m)
    {
        M res;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    res[i][j] = (res[i][j] + a[i][k] * m[k][j]) % P;
        return res;
    }
};

M pw(M x, int64 y)
{
    M res;
    res[0][0] = res[1][1] = 1;
    while (y)
    {
        if (y % 2LL == 1LL)
            res = res * x, --y;
        else
            x = x * x, y /= 2LL;
    }
    return res;
}

const double alpha = (1. + sqrt(5.)) * 0.5;

bool cmp(pair<int64, int64> p, pair<int64, int64> q)
{
    if (X >= BUBEN - 2)
        return p.first * alpha + p.second > q.first * alpha + q.second;
    return p.first * fib[X + 1] + p.second * fib[X] > q.first * fib[X + 1] + q.second * fib[X];
}

int main()
{
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < BUBEN; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    cin >> n >> X >> Y >> P;
    int64 sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        sum %= P;
    }
    sort(a, a + n);
    if (0) {
        vi v;
        for (int i = 0; i < n; ++i)
            v.pb(a[i]);
        for (int i = 0; i < X; ++i) {
            vi w;
            w.pb(v[0]);
            for (int j = 1; j < sz(v); ++j)
                w.pb(v[j - 1] + v[j]), w.pb(v[j]);
            v = w;
        }
        sort(all(v));
        for (int i = 0; i < Y; ++i) {
            vi w;
            w.pb(v[0]);
            for (int j = 1; j < sz(v); ++j)
                w.pb(v[j - 1] + v[j]), w.pb(v[j]);
            v = w;
        }
        int64 res = 0;
        for (int i = 0; i < sz(v); ++i)
            res += v[i];
        res %= P;
        cerr << res << "\n";
    }
    if (n == 1)
    {
        cout << (a[0] % P) << "\n";
        return 0;
    }
    int64 l1 = a[0], r1 = a[n - 1];
    int64 l2 = a[0];
    pair<int64, int64> _r2(-1, -1);
    for (int i = 0; i < n - 1; ++i)
    {
        int64 x = a[i], y = a[i + 1];
        if (x < y) swap(x, y);
        pair<int64, int64> cur(x, y);
        if (cmp(cur, _r2))
            _r2 = cur;
    }
    M mf;
    mf[0][0] = mf[0][1] = mf[1][0] = 1;
    M F = pw(mf, X);
    int64 r2 = F[0][0] * (_r2.first % P) + F[0][1] * (_r2.second % P);
    r2 %= P;
    
    M m1;
    m1[0][0] = 3;
    m1[0][1] = (P - 1) % P;
    m1[1][1] = 1;
    M m2 = pw(m1, X);
    int64 T1 = l1 + r1;
    int64 T2 = l2 + r2;
    T1 %= P;
    T2 %= P;
    int64 s0 = m2[0][0] * sum + m2[0][1] * (T1);
    s0 %= P;
    M m3 = pw(m1, Y);
    int64 res = m3[0][0] * s0 + m3[0][1] * (T2);
    res %= P;
    res += P;
    res %= P;
    cout << res << "\n";
    return 0;
}