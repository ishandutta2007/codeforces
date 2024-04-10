#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define op operator
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef double ld;
const int maxn = 3000600;

int n, k, m = 1000001;
int s[maxn];
int a[maxn];

inline int get(int l, int r) {
    return s[r] - (l ? s[l-1] : 0);
}

void scan() {
    scanf("%d%d", &n, &k);
    forn(i, n) {
        int a;
        scanf("%d", &a);
        ++s[a];
        ::a[i] = a;
    }
    forn(i, m) if (i) s[i] += s[i-1];
    for (int i = m; i < maxn; i++) {
        s[i] = s[i-1];
    }
}

bool solve(int d) {
    if (s[d-1]) return false;
    if (d <= k+1) return true;
    int l = k+1, r = d-1;
    while (l < m) {
        if (get(l, r)) {
            return false;
        }
        l += d;
        r += d;
    }
    return true;
}

int solve() {
    for (int d = m;; --d) {
        if (solve(d)) {
            return d;
        }
    }
}

int solve_slow() {
    for (int d = 1000;; --d) {
        bool fail = false;
        forn(i, n) if (a[i] < d || a[i] % d > k) {
            fail = true;
            break;
        }
        if (!fail) {
            return d;
        }
    }
}

int main()
{
//     freopen("input.txt", "r", stdin);

    scan();
    cout << solve() << endl;

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}