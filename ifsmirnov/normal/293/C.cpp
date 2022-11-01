#include <functional>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define le(x, y) ((x)<=(y)+eps)
#define gt(x, y) ((x)>(y)+eps)
#define ge(x, y) ((x)>=(y)-eps)
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9+100500;
const int maxn = 100500;

void bad() {
    cout << 0 << endl;
    exit(0);
}

vector<i64> divs;

void factor(i64 n) {
    for (i64 i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            divs.pb(i);
            if (i*i != n) {
                divs.pb(n/i);
            }
        }
    }
    forn(i, divs.size()) {
        if ((double)divs[i]*divs[i]*divs[i] < (double)n*0.9) {
            swap(divs[i], divs.back());
            divs.pop_back();
            --i;
        }
    }
    sort(all(divs));
}

i64 ra, rb;
i64 mx = 0;
inline int sq(i64 b, i64 c) {
    i64 d2 = b*b-c*4ll;
    int t = d2&15;
    if (t != 0 && t != 1 && t != 4 && t != 9)
        return 0;
    mx = max(mx, d2);
    if ((b+d2)%2)
        return 0;
    i64 d = roundl(sqrtl(d2));
    if (d*d != d2)
        return 0;
    //cout << d << endl;
    ra = b-d;
    rb = b+d;
    return ra > 0 && rb > 0;
}
inline int gres(i64 a, i64 b, i64 c) {
    if (c > a)
        return 0;
    //cout << a << " " << b << " " << c << endl;
    if (a == b) {
        if (a == c)
            return 1;
        return 3;
    }
    if (a == c || b == c) return 3;
    return 6;
}

i64 n;

int res = 0;

void solve()
{
    if (n%3 != 0)
        bad();
    n /= 3;
    factor(n);

    forn(i_apb, divs.size()) {
        i64 apb = divs[i_apb];
        i64 np = n / apb;

        //i64 tres = res;

        for (i64 c = 1; c * (c+apb) < np; c++) {
            i64 ab = np - c * (c+apb);
            if (sq(apb, ab))
                res += gres(ra, rb, c*2);
        }

        //if (tres != res)
            //cout << endl;
    }

    cout << res << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    solve();


#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}