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

int n, k, len;
char s[200500];
vi a;
int pos[200500];

void solve() {
    int _;
    cin >> n >> k >> len >> _;
    cin >> s;

    int slots = 0;
    int last = 0;
    forn(i, n+1) {
        if (s[i] != '0') {
            if (last != i) {
                pos[a.size()] = last;
                a.pb(i-last);
                slots += (i-last) / len;
            }
            last = i+1;
        }
    }

    vi res;

    forn(i, a.size()) {
        for (int j = len-1; j < a[i] && slots >= k; j += len) {
            res.pb(pos[i] + j);
            --slots;
        }
    }

    cout << res.size() << endl;
    for (int x: res) cout << x+1 << " ";
    cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}