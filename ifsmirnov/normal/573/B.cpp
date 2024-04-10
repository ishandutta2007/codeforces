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

const int maxn = 100500;

int n;
int a[maxn];
int b[maxn];
int mx[maxn];
int res[maxn];

struct S {
    vi a;
    vi mx;
    void push(int x) {
        a.pb(x);
        if (mx.empty()) mx.pb(x);
        else mx.pb(min(mx.back(), x));
    }
    void pop() {
        a.pop_back();
        mx.pop_back();
    }
    int get() {
        return mx.empty() ? 1100000000 : mx.back();
    }
};

struct Q {
    S a, b;
    void push(int x) {
        a.push(x);
    }
    void pop() {
        if (b.a.empty()) {
            while (!a.a.empty()) {
                b.push(a.a.back());
                a.pop();
            }
        }
        b.pop();
    }
    int get() {
        return min(a.get(), b.get());
    }
};

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
}

void f(int k) {
    forn(i, n) b[i] = a[i]-i;
//     cout << "b "; forn(i, n) cout << b[i] << " "; cout << endl;
    Q q;
    forn(i, k-1) {
        q.push(b[i]);
    }
    for (int i = k-1; i < n; ++i) {
//         cout << "stay @" << i << ", mx = " << q.get() << ", tmx = " << q.get() + i << endl;
        q.push(b[i]);
        if (q.get() + i >= k) {
//             cout << "yep" << endl;
            mx[i] = 1;
        }
        q.pop();
    }
}

bool can(int k) {
    forn(i, n) mx[i] = 0;
    f(k);
//     forn(i, n) cout << mx[i] << " "; cout << endl;
    forn(i, n) { res[i] = mx[i]; mx[i] = 0; }
    reverse(a, a+n);
    f(k);
    reverse(a, a+n);
    forn(i, n) res[i] &= mx[n-i-1];
    return *max_element(res, res+n);
}

void solve() {
    int l = 1, r = n;
    while (r-l > 1) {
        int m = (l+r)/2;
        if (can(m)) l = m;
        else r = m;
    }
    cout << l << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}