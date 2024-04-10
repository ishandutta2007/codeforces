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

const int maxn = 5050;

int n2, n3;

// many 3s
bool can3(int x) {
    for (int i = 0; i*2 <= x; ++i) {
        if ((x-2*i) % 3 != 0) continue;
        int j = (x-2*i) / 3;
        if (i <= n2 && j <= n3) {
            n2 -= i;
            n3 -= j;
            return true;
        }
    }
    return false;
}

// many 2s
bool can2(int x) {
    for (int i = x/2; i >= 0; --i) {
        if ((x-2*i) % 3 != 0) continue;
        int j = (x-2*i) / 3;
        if (i <= n2 && j <= n3) {
            n2 -= i;
            n3 -= j;
            return true;
        }
    }
    return false;
}

bool solve(int lim) {
    int nn2 = n2, nn3 = n3;
    int rem = 2*n2 + 3*n3;

    while (rem > 0 && lim > 1) {
        if (lim > rem) continue;
        if (n2 > n3) {
            if (can2(lim)) rem -= lim;
        } else {
            if (can3(lim)) rem -= lim;
        }
        --lim;
    }

    n2 = nn2;
    n3 = nn3;

    return rem == 0;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    cin >> n2 >> n3;
    int l = 0, r = 1e9;
    while (r-l > 1) {
        int m = (r+l) / 2;
        int c2 = m/2 - m/6;
        int c3 = m/3 - m/6;
        int r2 = max(0, n2-c2);
        int r3 = max(0, n3-c3);
        if (m/6 >= r2 + r3) r = m;
        else l = m;
    }
    cout << r << endl;


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}