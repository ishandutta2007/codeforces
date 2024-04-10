#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int n, m, k;

struct Multiset {
    map<int, int> good, bad;
    ll Sum;
    int size;

    Multiset () {
        Sum = 0;
        size = 0;
    }

    void insert(int x) {
        if (bad.empty() || x < bad.begin()->first) {
            ++good[x];
            Sum += x;
            ++size;
        } else ++bad[x];
    }

    void prune(int sz) {
        while (size > sz) {
            auto it = good.end();
            --it;
            Sum -= it->first;
            --size;
            ++bad[it->first];
            if (it->second == 1) good.erase(it);
            else --it->second;
        }
        while (size < sz && !bad.empty()) {
            auto it = bad.begin();
            Sum += it->first;
            ++size;
            ++good[it->first];
            if (it->second == 1) bad.erase(it);
            else --it->second;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<int> c(n);
    forn(i, 0, n) cin >> c[i];
    vector<char> a(n), b(n);
    int cnt;
    cin >> cnt;
    while (cnt--) {
        int x;
        cin >> x;
        --x;
        a[x] = 1;
    }
    cin >> cnt;
    while (cnt--) {
        int x;
        cin >> x;
        --x;
        b[x] = 1;
    }
    vector<int> common, aOnly, bOnly, other;
    forn(i, 0, n) {
        if (a[i]) {
            if (b[i]) common.eb(c[i]);
            else aOnly.eb(c[i]);
        } else {
            if (b[i]) bOnly.eb(c[i]);
            else other.eb(c[i]);
        }
    }
    sort(all(aOnly));
    sort(all(bOnly));
    sort(all(common));
    while (aOnly.size() > bOnly.size() || aOnly.size() > k) {
        other.eb(aOnly.back());
        aOnly.pop_back();
    }
    while (aOnly.size() < bOnly.size() || bOnly.size() > k) {
        other.eb(bOnly.back());
        bOnly.pop_back();
    }
    ll ans = LINF;
    ll prefSum = 0, aSum = 0, bSum = 0;
    for (int x : aOnly) aSum += x;
    for (int x : bOnly) bSum += x;
    Multiset Other;
    for (int x : other) Other.insert(x);
    fore(i, 0, common.size()) {
        while (aOnly.size() + i > k && !aOnly.empty()) {
            aSum -= aOnly.back();
            bSum -= bOnly.back();
            Other.insert(aOnly.back());
            Other.insert(bOnly.back());
            aOnly.pop_back();
            bOnly.pop_back();
        }
        if (aOnly.size() + i >= k) {
            int rest = m - 2 * int(aOnly.size()) - i;
            if (rest >= 0) {
                Other.prune(rest);
                if (Other.size == rest) {
                    ans = min(ans, Other.Sum + aSum + bSum + prefSum);
                }
            }
        }
        if (i != common.size()) prefSum += common[i];
    }
    if (ans == LINF) ans = -1;
    cout << ans << '\n';
}