#include <functional>
#include <cstring>
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

int n, k, a, b;

bool solve(int a, int b, int k, int x) {
    if (k == 0) return x == 0;
//     cout << a << " " << b << " " << k << " " << x << endl;
    if (k%2 == 0) {
        if (a && !solve(a-1, b, k-1, !x)) return true;
        if (b && !solve(a, b-1, k-1, x)) return true;
        return false;
    }

    if (a % 2 == x && a <= k/2) return false;
    if (b % 2 != x && b <= k/2) return false;
    return true;
}


int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

//     cout << solve(3, 2, 2, 0) << endl;
//     return 0;

    scanf("%d%d", &n, &k);
    k = n-k;
    int x;
    forn(i, n) {
        scanf("%d", &x);
        if (x % 2) b++; else a++;
    }

    x = 1 ^ (b % 2);

//     cout << a << " " << b << " " << k << " " << x << endl;

    printf("%s\n", solve(a, b, k, x) ? "Stannis" : "Daenerys");

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}