#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
typedef long long i64;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int M = 21;

const ld eps = 1e-6;

int n = 0, k, m;
ld p[M];
int id[M];
ld d[1 << M];
ld ans[M];


void read() {
    cin >> m >> k;
    for (int i = 0; i < m; ++i) {
        ld x;
        cin >> x;
        if (x > eps) {
            p[n] = x;
            id[n] = i;
            ++n;
        } else {
            ans[i] = 0;
        }
    }
}

void kill() {
    if (k >= n) {
        for (int i = 0; i < n; ++i)
            ans[id[i]] = 1.0;
    } else {
        d[0] = 1.0;
        
        for (int mask = 0; mask < (1 << n); ++mask)
            if (__builtin_popcount(mask) < k) {
                ld sum = 0.0;

                for (int t = 0; t < n; ++t)
                    if (((mask >> t) & 1) == 0) {
                        sum += p[t];
                    }

                for (int t = 0; t < n; ++t)
                    if (!((mask >> t) & 1)) {
                        d[mask ^ (1 << t)] += p[t] / sum * d[mask];
                    }
            }

        for (int mask = 0; mask < (1 << n); ++mask)
            if (__builtin_popcount(mask) == k) {
                for (int t = 0; t < n; ++t)
                    if ((mask >> t) & 1) {
                        ans[id[t]] += d[mask];
                    }
            }
    }

    for (int i = 0; i < m; ++i)
        cout << ans[i] << " ";
    cout << endl;
}



signed main() {
#ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
#endif

    cout.precision(10);
    cout << fixed;

    read();
    kill();


#ifdef LOCAL
    cerr << "Time: " << clock()/1000 << " ms" << endl;
#endif
}