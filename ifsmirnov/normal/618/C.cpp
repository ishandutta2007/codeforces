#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
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
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

struct pii {
    int fi, se;
    int id;
    bool operator<(const pii& x) const { return fi < x.fi || (fi == x.fi && se < x.se); }
};
int n;
pii p[100500];

pii operator-(const pii& a, const pii& b) { return {a.fi-b.fi, a.se-b.se, 0}; }
i64 operator*(const pii& a, const pii& b) { return (i64)a.fi*b.se - (i64)a.se*b.fi; }

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    cin >> n;
    forn(i, n) { cin >> p[i].fi >> p[i].se; p[i].id = i; }
    sort(p, p+n);
    forn(i, n-2) {
        if (0 != ((p[i+1]-p[i]) * (p[i+2]-p[i]))) {
            cout << p[i].id+1 << " " << p[i+1].id+1 << " " << p[i+2].id+1 << endl;
            return 0;
        }
    }
    assert(false);

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}