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

const int maxn = 100500;

int pr[maxn];

bool prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

vi res;

bool check2(int n) {
    if (n < maxn) {
        if (pr[n]) {
            res.pb(n);
            return true;
        }
    }

    if (prime(n)) {
        res.pb(n);
        return true;
    }

    forn(i, 50000) {
        if (n-i == 1) break;
        if (pr[i] && prime(n-i)) {
            res.pb(i);
            res.pb(n-i);
            return true;
        }
    }

    int k = n/2;
    int l = n-k;
    forn(i, 100000) {
        if (k-i == 1) break;
        if (prime(k-i) && prime(l+i)) {
            res.pb(k-i);
            res.pb(l+i);
            return true;
        }
    }
    return false;
}

bool solve(int n) {
    if (check2(n)) return true;
    if (check2(n-3)) {
        res.pb(3);
        return true;
    }
    return false;
}

int main() {
#ifdef HOME
//     freopen("input.txt", "r", stdin);
#endif

    forn(i, maxn) if (i >= 2) pr[i] = prime(i);

    int n;
    while (cin >> n) {
        res.clear();
        assert(solve(n));
        cout << res.size() << endl;
        for (auto x: res) cout << x << " ";
        cout << endl;
    }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}