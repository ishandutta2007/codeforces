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

int f(const vi& a) {
    int s = 0;
    int n = a.size();
    forn(j, n) forn(i, j+1) {
        s += *min_element(a.begin()+i, a.begin()+j+1);
    }
    return s;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    i64 n, k;
    cin >> n >> k; --k;
    vi a, b;
    forn(i, n-1) {
        if (k < (1ll<<(n-i-2))) {
            a.pb(i);
        } else {
            k -= (1ll<<(n-i-2));
            b.pb(i);
        }
    }
    reverse(all(b));
    for (auto x: a) cout << x+1 << " ";
    cout << n << " ";
    for (auto x: b) cout << x+1 << " ";
    cout << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}