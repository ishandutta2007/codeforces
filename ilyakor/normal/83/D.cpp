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

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

vi p;

const int maxn = 57 * 1000 * 1000;

bitset<maxn> u;

int64 get(int64 l, int64 r, int64 x) {
    int64 pl = l / x, pr = r / x;
    if (l % x) ++pl;
    return max(0LL, pr - pl + 1);
}

int64 calc(int64 a, int64 b, int k) {
    p.clear();
    int cur = 2;
    int64 ml = 1;
    while (sz(p) < 12) {
        while (!isPrime(cur)) ++cur;
        p.pb(cur);
        ml *= cur;
        ++cur;
    }
    //cerr << ml << " " << cur << "\n";
    if (sz(p) && k <= p[sz(p) - 1]) {
        int ind = -1;
        while (p[sz(p) - 1] != k) p.pop_back();
        for (int i = 0; i < sz(p); ++i)
            if (p[i] == k) ind = i;
        int64 res = 0;
        for (int mask = 0; mask < (1 << sz(p)); ++mask) if ((mask >> ind) & 1) {
            int cnt = 0, x = mask;
            int64 l = 1;
            for (int i = 0; i < sz(p); ++i) if ((mask >> i) & 1) {
                ++cnt;
                l *= p[i];
            }
            if (cnt % 2 == 1) res += get(a, b, l);
            else res -= get(a, b, l);
        }
        return res;
    }
    b /= k;
    int64 tmp = a / k;
    if (a % k) ++tmp;
    a = tmp;
    u.reset();
    int64 res = 0;
    int lim = sqrt(b + 0.) + 10;
    lim = min(lim, k);
    for (int i = 1; i <= b; ++i) {
        if (u[i]) continue;
        if (i >= a) {
            //cerr << i << "\n";
            ++res;
        }
        if (i == 1) continue;
        if (i >= lim) continue;
        for (int j = i * i; j <= b; j += i)
            u[j] = true;
    }
    u.reset();
    lim = sqrt(b + 0.) + 10;
    for (int i = 2; i <= min<int64>(b, k); ++i) {
        if (u[i]) continue;
        if (i >= a && i < k) {
            //cerr << i << "\n";
            --res;
        }
        if (i == 1) continue;
        if (i >= lim) continue;
        for (int j = i * i; j <= b; j += i)
            u[j] = true;
    }
    return res;
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    if (!isPrime(k)) {
        printf("0\n");
        return 0;
    }
    int64 res = calc(a, b, k);
    cout << res << "\n";
    return 0;
}