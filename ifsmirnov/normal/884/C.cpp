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

const int maxn = 100500;
int n;
int a[maxn];
int b[maxn];

void scan() {
    cin >> n;
    forn(i, n) {
        cin >> a[i];
        --a[i];
    }
}

void solve() {
    vi t;
    forn(i, n) if (!b[i]) {
        int j = i;
        int c = 0;
        while (!b[j]) {
            ++c;
            b[j] = 1;
            j = a[j];
        }
        t.push_back(c);
    }
    sort(all(t));
    reverse(all(t));
    t.push_back(0);
    t[1] += t[0];
    t.erase(t.begin());
    i64 res = 0;
    for (i64 x: t) res += x*x;
    cout << res << endl;
}

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}