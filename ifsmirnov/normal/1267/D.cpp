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

const int maxn = 300;

int n;
int need[maxn];
int test[maxn];
int have[maxn];
vector<pii> edges;
int ct[maxn];

void scan() {
    cin >> n;
    forn(i, n) {
        forn(j, 3) {
            int x;
            cin >> x;
            need[i] = need[i] * 2 + x;
        }
    }
    forn(i, n) {
        forn(j, 3) {
            int x;
            cin >> x;
            test[i] = test[i] * 2 + x;
        }
        test[i] &= need[i];
    }
}

void solve() {
    memset(have, -1, sizeof have);
    memset(ct, -1, sizeof ct);
    have[7] = 0;
    ct[0] = 1;

    bool done = true;
    while (done) {
        done = false;

        forn(v, n) if (ct[v] == -1) {
            int x = need[v];
            if (have[x] != -1 && (test[v] & x) && have[test[v] & x] == -1) {
                // cerr << "1Got " << x << " at " << v << "\n";
                // cerr << "Propagate to " << (test[v]) << "\n";
                ct[v] = 1;
                have[x & test[v]] = v;
                edges.emplace_back(have[x], v);
                done = true;
                break;
            }
        }
        if (done) continue;

        forn(v, n) if (ct[v] == -1) {
            int x = need[v];
            if (have[test[v] & x] != -1) continue;
            if (!(test[v] & x)) continue;
            forn(y, 8) if (!done) forn(z, y) if (have[y] != -1 && have[z] != -1 && (y|z) == x) {
                // cerr << "2Got " << x << " at " << v << "\n";
                // cerr << "Propagate to " << test[v] << "\n";
                cerr << have[y] << " " << have[z] << "\n";
                ct[v] = 1;
                have[x & test[v]] = v;
                edges.emplace_back(have[y], v);
                edges.emplace_back(have[z], v);
                done = true;
                break;
            }
            if (done) break;
        }
        if (done) continue;

        forn(v, n) if (ct[v] == -1) {
            int x = need[v];
            if (have[x] != -1) continue;
            forn(y, 8) if (!done) forn(z, y) if (have[y] != -1 && have[z] != -1 && (y|z) == x) {
                // cerr << "3Got " << x << " at " << v << "\n";
                ct[v] = 0;
                have[x] = v;
                edges.emplace_back(have[y], v);
                edges.emplace_back(have[z], v);
                done = true;
                break;
            }
            if (done) break;
        }
    }

    forn(v, n) if (ct[v] == -1) {
        if (need[v] == 0) {
            ct[v] = 0;
            continue;
        }
        if (have[need[v]] == -1) {
            cout << "Impossible\n";
            return;
        }
        edges.emplace_back(have[need[v]], v);
        ct[v] = 0;
    }

    cout << "Possible\n";
    forn(i, n) cout << ct[i] << " \n"[i+1 == n];
    cout << edges.size() << "\n";
    for (auto kv : edges) {
        cout << kv.fi+1 << " " << kv.se+1 << "\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    scan();
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}