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

const int maxn = 50050;

int n;
int a[maxn];
int b[maxn];
unordered_set<int> used;

bool can(int lim) {
    used.clear();
    forn(i, n) {
        int x = a[i];
        while (x && (x > lim || used.count(x))) {
            x /= 2;
        }
        if (x == 0) return false;
        b[i] = x;
        used.insert(x);
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    cin >> n;
    forn(i, n) cin >> a[i];
    int l = 0, r = 1000000000;
    while (r-l > 1) {
        int m = (l+r) / 2;
        if (can(m)) r = m;
        else l = m;
    }
    can(r);
    forn(i, n) cout << b[i] << " ";
    cout << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}