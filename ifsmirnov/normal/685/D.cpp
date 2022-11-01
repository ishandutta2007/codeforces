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

const int maxn = 400500;
const int maxk = 305;

int n, k;
pii pos[maxn];
int b[maxn], e[maxn];
vi ip;

void scan() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d%d", &pos[i].fi, &pos[i].se);
}

void gen_ip() {
    forn(i, n) {
        ip.pb(pos[i].fi + 1);
        ip.pb(pos[i].fi - k + 1);
    }
    sort(all(ip));
    ip.erase(unique(all(ip)), ip.end());
    forn(i, n) {
        b[i] = lower_bound(all(ip), pos[i].fi-k+1) - ip.begin();
        e[i] = lower_bound(all(ip), pos[i].fi+1) - ip.begin();
    }
}

i64 res[maxn];

int val[maxn];
int upd[maxn];

void solve() {
    vector<pii> evs;
    forn(i, n) {
        evs.emplace_back( pos[i].se - k + 1, i );
        evs.emplace_back( pos[i].se + 1, ~i );
    }

    sort(all(evs));
    for (auto ev: evs) {
        int y, id;
        tie(y, id) = ev;
        int delta = 1;
        if (id < 0) {
            delta = -1, id = ~id;
        }
        for (int i = b[id]; i != e[id]; ++i) {
            int len = ip[i+1] - ip[i];
            res[val[i]] += (i64)len * (y - upd[i]);
            upd[i] = y;
            val[i] += delta;
        }
    }

    forn(i, n) {
        cout << res[i+1] << " ";
    }
    cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    scan();
    gen_ip();
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}