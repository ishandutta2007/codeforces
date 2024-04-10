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

const int maxn = 200500;

int n;
vector<int> with[4];
int cost[maxn];
int b[maxn];
int a[maxn], bb[maxn];
int p[4];

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    cin >> n;
    forn(i, n) cin >> cost[i];
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> bb[i];
    forn(i, n) {
        with[a[i]].pb(i);
        with[bb[i]].pb(i);
    }
    forn(i, 4) sort(all(with[i]), [](int i, int j) { return cost[i] < cost[j]; });
    int m;
    cin >> m;
    forn(i, m) {
        int c;
        cin >> c;
        bool done = false;
        while (p[c] < (int)with[c].size()) {
            int x = with[c][p[c]++];
            if (b[x]) continue;
            done = true;
            cout << cost[x] << " ";
            b[x] = 1;
            break;
        }
        if (!done) cout << -1 << " ";
    }
    cout << "\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}