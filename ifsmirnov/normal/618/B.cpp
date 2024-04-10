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
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

int n;
int a[55][55];
int r[55];
int b[55];

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    forn(i, n) forn(j, n) cin >> a[i][j];

    fore(i, 1, n) {
        forn(j, n) {
            bool ok = true;
            int c = 0;
            forn(k, n) {
                if (a[j][k] && a[j][k] != i) ok = false;
                c += a[j][k] == i;
            }
            if (c && ok) {
                forn(k, n) a[j][k] = a[k][j] = 0;
                r[j] = i;
                break;
            }
        }
    }
    forn(i, n) cout << (r[i]?r[i]:n) << " "; cout << endl;


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}