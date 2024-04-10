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

const int maxn = 10;

int b[maxn];
vi cycles(const vi& a) {
    int n = a.size();
    forn(i, n) b[i] = 0;
    vector<vi> t;
    forn(i, n) if (!b[i]) {
        vi c{i};
        for (int j = a[i]; j != i; j = a[j]) {
            c.pb(j);
            b[j] = 1;
        }
        int mx = *max_element(all(c));
        while (c.front() != mx) {
            int x = c.front();
            c.erase(c.begin());
            c.pb(x);
        }
        t.pb(c);
    }
    sort(all(t), [](const vi& a, const vi& b) { return a.front() < b.front(); });
    vi res;
    for (auto v: t) for (auto k: v) res.pb(k);
    return res;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    int n;
    i64 k;
    cin >> n >> k; --k;
    vector<i64> fib{0,1,2};
    forn(i, n-2) {
        fib.pb(fib[fib.size() - 2] + fib.back());
    }

    while ((int)fib.size() > n) fib.pop_back();
    reverse(all(fib));
    forn(i, n) {
        if (i + 1 == n || k < fib[i]) {
            cout << i+1 << " ";
        } else {
            cout << i+2 << " " << i+1 << " ";
            k -= fib[i];
            ++i;
        }
    }
    cout << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}