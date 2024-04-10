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

int n, T;
multiset<int> cur, rem;
i64 cs;
struct T { int a, t, id; bool operator<(const T& t) const { return a < t.a; }; } a[maxn];
int k = 1;
int ans;

void scan() {
    cin >> n >> T;
    forn(i, n) cin >> a[i].a >> a[i].t, a[i].id = i;
    sort(a, a+n);
}

void upd() {
    while (true) {
        if (cur.empty()) {
            if (!rem.empty() && cs + *rem.begin() <= T) {
                cur.insert(*rem.begin());
                cs += *rem.begin();
                rem.erase(rem.begin());
                continue;
            } else {
                break;
            }
        } else {
            if ((int)cur.size() < k && !rem.empty() && cs + *rem.begin() <= T) {
                cur.insert(*rem.begin());
                cs += *rem.begin();
                rem.erase(rem.begin());
            } else if (!rem.empty() && *--cur.end() > *rem.begin()) {
                int x = *--cur.end(); cur.erase(--cur.end());
                int y = *rem.begin(); rem.erase(rem.begin());
                cs -= x - y;
                cur.insert(y);
                rem.insert(x);
            } else {
                break;
            }
        }
    }

    ans = cur.size();
}

void del(int x) {
    auto it = cur.find(x);
    if (it != cur.end()) { cur.erase(it); cs -= x; return; }
    it = rem.find(x);
    assert(it != rem.end());
    rem.erase(it);
}

void solve() {
    pii best(0, 0);
    int ptr = 0;
    forn(i, n) rem.insert(a[i].t);
    upd();
    best = max(best, pii(ans, k));

    while (k < n) {
        ++k;
        while (ptr < n && a[ptr].a < k) del(a[ptr++].t);
        upd();
        best = max(best, pii(ans, k));
    }

    vector<pii> res;
    forn(i, n) if (a[i].a >= best.se) res.emplace_back(a[i].t, a[i].id);
    sort(all(res));

    cout << best.fi << endl;
    cout << best.fi << endl;
    forn(i, best.fi) cout << res[i].se+1 << " ";
    cout << endl;
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