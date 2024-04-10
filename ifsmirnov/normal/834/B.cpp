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

const int maxn = 1000500;

int n, k;
string s;
int d[maxn];

void yes() {
    cout << "YES\n";
    exit(0);
}

void no() {
    cout << "NO\n";
    exit(0);
}

void solve() {
    cin >> n >> k >> s;
    fore(c, 'A', 'Z') {
        int fp = s.find(c);
        int lp = s.rfind(c);
        if (fp != (int)string::npos) {
            ++d[fp];
            --d[lp+1];
        }
    }
    partial_sum(d, d+maxn, d);

    if (*max_element(d, d+maxn) <= k) no();
    else yes();
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