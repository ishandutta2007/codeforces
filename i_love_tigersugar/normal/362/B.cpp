#include <iostream>
#include <stack>
#include <set>
#include <queue>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstring>
#include <complex>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORE(i, v) for (__typeof ((v).begin ()) i = (v).begin (); i != (v).end (); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPD(i, n) for (int i = (int) (n) - 1; i >= 0; --i)
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef pair <int, int> PII;
typedef long long LL;
typedef double DD;
typedef complex <DD> Point;
#define X real()
#define Y imag()
#define sqr(x) ((x) * (x))
const int INF = 1e9;

int main () {
//  ios::sync_with_stdio (false);
//  freopen ("in", "r", stdin);
    int n, m;
    scanf ("%d%d", &n, &m);
    vector <int> v (m);
    REP (i, m) {
        scanf ("%d", &v [i]);
        if (v [i] == 1 || v [i] == n) {
            cout << "NO\n";
            return 0;
        }
    }
    sort (v.begin (), v.end ());
    REP (i, v.size ()) {
        if (i + 2 < v.size () && v [i] + 1 == v [i + 1] && v [i + 2] == v [i] + 2) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}