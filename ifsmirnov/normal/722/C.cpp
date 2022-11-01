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
// #define sz(x) int((x).size())

const int maxn = 100500;
int n;
int a[maxn];
i64 s[maxn];
multiset<i64> have;
set<int> u;

i64 get(int l, int r) {
    if (l > r) return 0;
    return s[r] - (l ? s[l-1] : 0);
}

void del(int i) {
    auto it2 = u.lower_bound(i);
    assert(it2 != u.begin() && it2 != u.end());
    auto it1 = it2; --it1;
    assert(*it1 < i && i < *it2);
    i64 val = get(*it1 + 1, *it2 - 1);
    auto it = have.find(val);
    assert(it != have.end());
    have.erase(it);
    have.insert(get(*it1 + 1, i - 1));
    have.insert(get(i + 1, *it2 - 1));
    u.insert(i);
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin >> n;
    forn(i, n) cin >> a[i];
    forn(i, n) {
        if (i) s[i] += s[i-1];
        s[i] += a[i];
    }
    have.insert(s[n-1]);
    have.insert(0);
    u.insert(-1);
    u.insert(n);

    forn(i, n) {
        int x;
        cin >> x;
        del(x-1);
        cout << *have.rbegin() << "\n";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}