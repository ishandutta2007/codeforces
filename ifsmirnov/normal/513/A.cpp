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

const int maxn = 55;

// int d[2][maxn][maxn];
// int k[2];
// int n1, n2;
// 
// int go(int x, int y, int m) {
//     if (x == 0) return 0;
//     if (d[m][x][y]) return d[m][x][y];
//     int r = 0;
//     fore(i, 1, min(k[m], x)) {
//         if (!go(y
// }

int main() {
#ifdef HOME
//     freopen("input.txt", "r", stdin);
#endif

    int n1, n2, a, b;
    cin >> n1 >> n2;
    if (n1 > n2) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}