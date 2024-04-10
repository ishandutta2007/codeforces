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

const int maxn = 1050;
int n;
int p[maxn];
int deg[maxn], cc[maxn];

void yes() {
    cout << "Yes\n";
    exit(0);
}

void no() {
    cout << "No\n";
    exit(0);
}

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    cin >> n;
    forn(i, n) if (i) cin >> p[i], --p[i];
    ford(i, n) {
        if (i) ++deg[p[i]];
        if (deg[i] == 0) ++cc[p[i]];
        else if (cc[i] < 3) no();
    }
    yes();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}