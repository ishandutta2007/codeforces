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
int x[10], y[10];

int main() {
#ifdef HOME
//     freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    forn(i, n) cin >> x[i] >> y[i];
    int dx = *max_element(x, x+n) - *min_element(x, x+n);
    int dy = *max_element(y, y+n) - *min_element(y, y+n);
    if (dx && dy) cout << dx*dy << endl;
    else cout << -1 << endl;


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}