#ifndef LOCAL
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>

using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim>typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim>
struct rge {
    c b, e;
};

sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }

sim> auto dud(c *r) -> decltype(cerr << *r);

sim> char dud(...);

struct muu {
#ifdef LOCAL
    stringstream a;

    ~muu() { cerr << a.str() << endl; }

    R22(<) a << boolalpha << g;
        ris; }

    R22(==) ris << range(begin(g), end(g)); }

    sim mor rge<c> u) {
        a << "[";
        for (c i = u.b; i != u.e; ++i)
            *this << ", " + 2 * (i == u.b) << *i;
        ris << "]";
    }

    sim, class m mor pair<m, c> r) {
        ris << "(" << r.first << ", " << r.second << ")";
    }

#else
    sim mor const c&){ris;}
#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

ll dp[1000007];
ll dp_pref[10000007];
ll dp_pref_1[10000007];
int ost[10000007];

const int mod = 1000000007;

int main() {
    string s;
    cin >> s;
    vector<char> serio;
    bool bylo = false;
    int lewa = 0;
    for (auto it : s) {
        bylo |= it == '1';
        if (bylo)
            serio.push_back(it);
        else
            lewa += 1;
    }
    if (!bylo) {
        printf("%d\n", (int) s.size());
        return 0;
    }
    int prawa = 0;
    while (serio.back() == '0') {
        prawa++;
        serio.pop_back();
    }
    dp[1] = 1;
    dp_pref[1] = 1;
    dp_pref_1[1] = 1;
    int ost1 = 1;
    int ile = 0;
    for (int i = 2; i <= (int) serio.size(); i++) {
        char l = serio[i - 1];
        dp_pref_1[i] = dp_pref_1[i - 1];
        if (l == '1') {
            dp[i] = dp_pref[i - 1] - dp_pref[ost1 - 1];
            ost1 = i;
            ile = 0;
            dp_pref_1[i] = (dp_pref_1[i] + dp[i]) % mod;
        } else {
            ++ile;
            dp[i] = (dp_pref_1[i - 1] - dp_pref_1[ost[ile]]) % mod;
            ost[ile] = i;
        }
        dp_pref[i] = (dp_pref[i - 1] + dp[i]) % mod;
    }
    dp_pref_1[serio.size()] *= lewa + 1;
    dp_pref_1[serio.size()] %= mod;
    dp_pref_1[serio.size()] *= prawa + 1;
    dp_pref_1[serio.size()] %= mod;
    if (dp_pref_1[serio.size()] < 0)
        dp_pref_1[serio.size()] += mod;
    printf("%lld\n", dp_pref_1[serio.size()]);
    return 0;
}