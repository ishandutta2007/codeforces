#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::setprecision;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::min;
using std::max;
using std::fill;
using std::max_element;
using std::min_element;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
//#define double long double

const long long MOD = 1e9 + 7;
const long long inf = 1e18;
const long long infsmart = 1e12;

long long n;
long long a[50000];
long long sz, ans;
long long kek[50000];
long long cnt[50000];

long long s2(long long x)
{
    long long l = 0, r = 2e9;
    while (l + 1 < r)
    {
        long long mid = (l + r) / 2;
        if (mid * mid < x)
            l = mid;
        else
            r = mid;
    }
    if (r * r == x)
        return r;
    return -1;
}

long long s3(long long x)
{
    long long l = 0, r = 2e6;
    while (l + 1 < r)
    {
        long long mid = (l + r) / 2;
        if (mid * mid * mid < x)
            l = mid;
        else
            r = mid;
    }
    if (r * r * r == x)
        return r;
    return -1;
}

long long s4(long long x)
{
    long long l = 0, r = 5e4;
    while (l + 1 < r)
    {
        long long mid = (l + r) / 2;
        if (mid * mid * mid * mid < x)
            l = mid;
        else
            r = mid;
    }
    if (r * r * r * r == x)
        return r;
    return -1;
}

int neither(long long x)
{
    if (s2(x) > 0 || s3(x) > 0 || s4(x) > 0)
        return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        long long x = s2(a[i]);
        long long y = s3(a[i]);
        long long z = s4(a[i]);
        if (z > 0)
        {
            kek[sz] = z;
            sz++;
        }
        else
        {
            if (y > 0)
            {
                kek[sz] = y;
                sz++;
            }
            else
            {
                if (x > 0)
                {
                    kek[sz] = x;
                    sz++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long g = std::__gcd(a[i], a[j]);
            if (g > 1 && a[i] != a[j])
            {
                kek[sz] = g;
                sz++;
                if (neither(a[i] / g))
                {
                    kek[sz] = a[i] / g;
                    sz++;
                }
                if (neither(a[j] / g))
                {
                    kek[sz] = a[j] / g;
                    sz++;
                }
            }
        }
    }
    sort(kek, kek + sz);
    sz = unique(kek, kek + sz) - kek;
    
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < n; j++)
        {
            while (a[j] % kek[i] == 0)
            {
                cnt[i]++;
                a[j] /= kek[i];
            }
        }
    }
    long long ans = 1;
    for (int i = 0; i < sz; i++)
    {
        ans = ans * (cnt[i] + 1) % 998244353;
    }
    sort(a, a + n);
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 1) continue;
        cnt++;
        if (j + 1 == n || a[j + 1] != a[j])
        {
            ans = (ans * (cnt + 1) * (cnt + 1)) % 998244353;
            cnt = 0;
        }
    }
    cout << ans;
}