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

bool pr(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    vi res;
    for (int p = 2; p <= n; ++p) if (pr(p)) {
        int x = p;
        while (x <= n) {
            res.pb(x);
            x *= p;
        }
    }
    cout << res.size() << endl;
    for (auto x: res) cout << x << " "; cout << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}