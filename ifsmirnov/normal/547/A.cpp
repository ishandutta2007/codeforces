#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;
int mod;
int add(int x, int y) { return (x+y)%mod; }
int mul(int x, int y) { return (i64)x*y%mod; }

#define y1 fuck_you

int x1, y1, x2, y2, h1, h2, a1, a2;
int m;

int first_reach(int h, int x, int y, int a) {
    forn(i, m+10) {
        if (h == a) {
            return i;
        }
        h = add(y, mul(h, x));
    }
    return -1;
}

int per(int x, int y, int a) {
    int h = a;
    forn(i, m+10) {
        h = add(y, mul(h, x));
        if (h == a) return i+1;
    }
    return 0;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    i64 ans = 0;

    cin >> mod >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
    m = mod;

    forn(i, m*2 + 10) {
        if (h1 == a1 && h2 == a2) {
            cout << i << endl;
            return 0;
        }
        h1 = add(y1, mul(h1, x1));
        h2 = add(y2, mul(h2, x2));
        ++ans;
    }

    int fr1 = first_reach(h1, x1, y1, a1);
    int fr2 = first_reach(h2, x2, y2, a2);
    if (-1 == fr1 || -1 == fr2) {
        cout << -1 << endl;
        return 0;
    }

//     cout << fr1 << " " << fr2 << endl;

    int per1 = per(x1, y1, a1);
    int per2 = per(x2, y2, a2);

//     cout << per1 << " " << per2 << endl;

    if (fr1 == fr2) {
        cout << fr1 << endl;
        return 0;
    }

    if (per1 == 0 && per2 == 0) {
        cout << -1 << endl;
        return 0;
    } else if (per1 == 0) {
        if (fr1 > fr2 && (fr1 - fr2) % per2 == 0) {
            cout << fr1 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    } else if (per2 == 0) {
        if (fr2 > fr1 && (fr2 - fr1) % per1 == 0) {
            cout << fr2 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    int p1 = per1 - fr1;
    int p2 = per2 - fr2;

    assert(p1 > 0);
    assert(p2 > 0);

    int add = per1 - p1;
    p1 += add; p1 %= per1;
    assert(p1 == 0);
    p2 += add; p2 %= per2;
    ans += add;

    forn(i, m+10) {
        if (p2 == 0) {
            cout << ans << endl;
            return 0;
        }
        p2 += per1; p2 %= per2;
        ans += per1;
    }

    cout << -1 << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}