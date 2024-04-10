#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

namespace SuffixArray {
    const int maxlen = 2e5 + 10;
    const int alphabet = 256;
    int p[maxlen], cnt[maxlen], c[maxlen], pn[maxlen], cn[maxlen];
    int* build(string s) {
        s += "$";
        int n = (int)s.size();
        memset(cnt, 0, alphabet * sizeof(int));
        for (int i = 0; i < n; ++i)
            ++cnt[(int)s[i]];
        for (int i = 1; i < alphabet; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; ++i)
            p[--cnt[(int)s[i]]] = i;
        int classes = 0;
        c[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (s[p[i]] != s[p[i - 1]])
                ++classes;
            c[p[i]] = classes;
        }
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; ++i) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0)
                    pn[i] += n;
            }
            memset(cnt, 0, (classes + 1) * sizeof(int));
            for (int i = 0; i < n; ++i)
                ++cnt[c[pn[i]]];
            for (int i = 1; i <= classes; ++i)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i)
                p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 0;
            for (int i = 1; i < n; ++i) {
                int m1 = p[i] + (1 << h), m2 = p[i - 1] + (1 << h);
                if (m1 >= n) m1 -= n;
                if (m2 >= n) m2 -= n;
                if (c[p[i]] != c[p[i - 1]] || c[m1] != c[m2])
                    ++classes;
                cn[p[i]] = classes;
            }
            memcpy(c, cn, n * sizeof(int));
        }
        return p;
    }

    int lcp[maxlen], pos[maxlen];
    int* build_lcp(string s) {
        s += "$";
        int n = (int)s.length();
        for (int i = 0; i < n; ++i)
            pos[p[i]] = i;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (k) --k;
            if (pos[i] == n - 1) {
                lcp[n - 1] = -1;
                k = 0;
            } else {
                int j = p[pos[i] + 1];
                while (max(i, j) + k < n && s[i + k] == s[j + k])
                    ++k;
                lcp[pos[i]] = k;
            }
        }
        return lcp;
    }
}

using SuffixArray::build;
using SuffixArray::build_lcp;
using SuffixArray::pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    string s, bad;
    cin >> s >> bad;
    reverse(all(s));
    reverse(all(bad));
    build(s);
    int* lcp = build_lcp(s);
    vector<int> good;
    forn(i, 0, n) if (bad[i] == '0') good.eb(pos[i] - 1);
    int sz = good.size();
    if (sz == 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> nxt;
    sort(all(good));
    forn(i, 1, sz) {
        int mn = INF;
        forn(j, good[i - 1] + 1, good[i] + 1)
            setmin(mn, lcp[j]);
        nxt.eb(mn);
    }
    --sz;
    ll ans = 0;
    forn(i, 0, n) if (bad[i] == '0') setmax(ans, ll(n - i));
    vector<int> lft(sz), rgt(sz);
    stack<int> q;
    forn(i, 0, sz) {
        while (!q.empty() && nxt[q.top()] >= nxt[i])
            q.pop();
        if (q.empty())
            lft[i] = -1;
        else
            lft[i] = q.top();
        q.push(i);
    }
    while (!q.empty()) q.pop();
    ford(i, 0, sz) {
        while (!q.empty() && nxt[q.top()] >= nxt[i])
            q.pop();
        if (q.empty())
            rgt[i] = sz;
        else
            rgt[i] = q.top();
        q.push(i);
    }
    forn(i, 0, sz) {
        int len = rgt[i] - lft[i];
        setmax(ans, 1ll * len * nxt[i]);
    }
    cout << ans << '\n';
}