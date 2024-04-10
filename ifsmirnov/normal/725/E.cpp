#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;
// #define sz(x) int((x).size())

const int maxn = 200500;

int n;
int c;
int a[maxn];
i64 s[maxn];

void scan() {
    scanf("%d%d", &c, &n);
    forn(i, n) scanf("%d", &a[i]);
    sort(a, a+n, greater<int>());
    forn(i, n) {
        if (i) s[i] = s[i-1];
        s[i] += a[i];
    }
}

i64 get(int i, int j) {
    return s[j] - (i ? s[i-1] : 0);
}

int greedy(int L, int R, int c) { // [L, R]
    if (L > R) return c;
    int p = L;
    while (true) {
        // take
        if (a[p] <= c) {
            if (get(p, R) <= c) {
                return c - get(p, R);
            }
            int l = p, r = R;
            while (r-l > 1) {
                int m = (l+r)/2;
                if (get(p, m) <= c) {
                    l = m;
                } else {
                    r = m;
                }
            }
//             assert(get(p, l) <= c);
//             assert(get(p, r) > c);
            c -= get(p, l);
            p = l+1;
        }

        if (p > R) return c;
        if (a[R] > c) return c;
        int l = p, r = R;
        while (r-l > 1) {
            int m = (l+r)/2;
            if (a[m] <= c) {
                r = m;
            } else {
                l = m;
            }
        }
//         assert(a[r] <= c);
//         assert(a[l] > c);
        p = r;
    }
}

bool go(int pos, int x) {
    int c = ::c;
    c = greedy(0, pos-1, c);
    if (c >= x) {
        c -= x;
    }
    c = greedy(pos, n-1, c);
    return c != 0;
}

void solve() {
    int pos = n;
    for (int x = 1; x <= c; ++x) {
        while (pos && a[pos-1] < x) --pos;
        if (go(pos, x)) {
            cout << x << endl;
            exit(0);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("e.in", "r", stdin);
#endif

    scan();
    solve();
    cout << "Greed is good" << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}