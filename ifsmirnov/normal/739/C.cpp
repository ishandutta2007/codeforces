// #ifdef LOCAL
// #define _GLIBCXX_DEBUG
// #endif
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

#define npos wokjrew

const int maxn = 300500;
int n;
i64 a[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) { int x; scanf("%d", &x); a[i] =x; }
    forn(i, n-1) a[i] = a[i+1] - a[i];
    --n;
}

int sgn(i64 x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}


multiset<int> ans;

set<int> b;
int npos[maxn];

bool in(int l, int r, int y) { return l <= y && y <= r; }

void remove(int l) {
//     cerr << "remove " << l << endl;
    auto it = b.find(l);
    assert(it != b.end());
    b.erase(it);
    ans.erase(ans.find(npos[l] - l + 1));
}

void add(int l, int r) {
    if (l > r) return;
//     cerr << "add " << l << " " << r << endl;
    npos[l] = r;
    ans.insert(r-l+1);
    b.insert(l);
}

void set0(int i) {
//     cerr << "set0 " << i << endl;
    int l = *--b.upper_bound(i);
    int r = npos[l];
//     cerr << l << " " << r << endl;
    assert(in(l, r, i));
    remove(l);
    add(l, i-1);
    add(i+1, r);
}

void setp(int i) {
//     cerr << "setp " << i << endl;
    int l = i, r = i;
    if (i && sgn(a[i-1]) == 1) {
        int ll = *--b.upper_bound(i);
        int rr = npos[ll];
        assert(rr == i-1);
        remove(ll);
        l = ll;
    }

    if (i+1 < n && sgn(a[i+1]) != 0) {
        int ll = *b.upper_bound(i);
        int rr = npos[ll];
        assert(i+1 == ll);
        remove(ll);
        r = rr;
    }
    add(l, r);
}

void setm(int i) {
//     cerr << "setm " << i << endl;
    int l = i, r = i;
    if (i && sgn(a[i-1]) != 0) {
        int ll = *--b.upper_bound(i);
        int rr = npos[ll];
        assert(rr == i-1);
        remove(ll);
        l = ll;
    }

    if (i+1 < n && sgn(a[i+1]) == -1) {
        int ll = *b.upper_bound(i);
        int rr = npos[ll];
        assert(i+1 == ll);
        remove(ll);
        r = rr;
    }
    add(l, r);
}

void setneed(int i) {
    if (a[i] == 0) set0(i);
    else if (a[i] > 0) setp(i);
    else setm(i);
}

void solve() {
    {
    vi b(a, a+n);
    memset(a, 0, sizeof a);
    forn(i, n) {
        if (b[i] > 0) setp(i);
        if (b[i] < 0) setm(i);
        a[i] = b[i];
    }
    }
    ans.insert(0);
    int m;
    scanf("%d", &m);

//     forn(i, n) cerr << sgn(a[i]) << " "; cerr << endl;
//     for (auto x: b) cerr << x << "-" << npos[x] << " ";
//     cerr << endl;

    forn(i, m) {
        int l, r, d;
        scanf("%d%d%d", &l, &r, &d);

        l -= 2;
        --r;

        if (l >= 0) {
            if (sgn(a[l]) != sgn(a[l] + d)) {
                if (a[l]) set0(l);
                a[l] += d;
                if (a[l]) setneed(l);
            } else {
                a[l] += d;
            }
        }

        if (r < n) {
            if ( sgn(a[r]) != sgn(a[r] - d)) {
                if (a[r]) set0(r);
                a[r] -= d;
                if (a[r]) setneed(r);
            } else {
                a[r] -= d;
            }
        }

        printf("%d\n", 1 + *ans.rbegin());

//         forn(i, n) cout << sgn(a[i]) << " "; cout << endl;
//         for (auto x: b) cout << x << "-" << npos[x] << " ";
//         cout << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}