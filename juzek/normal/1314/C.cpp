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

    sim, class m mor pair<m, c> r) { ris << "(" << r.first << ", " << r.second << ")"; }

#else
    sim mor const c&){ris;}
#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r...) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

int wspolne[1007][1007];
unsigned long long dp[1007][1007];
unsigned long long dp_pref[1007][1007];
string s;
int N, M;

const unsigned long long inf = 2500000000000000000ll;

ll policz(string wieksze, int spos) {
    for (int i = N - 1; i >= 0; i--) {
        int wsp = wspolne[spos][i];
        if (wsp >= wieksze.size() || (i + wsp < s.size() && s[i + wsp] > wieksze[wsp]))
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
        dp_pref[0][i] = dp_pref[0][i + 1] + dp[0][i];
    }
    debug << range(dp[0] + 0, dp[0] + s.size());
    for (int z = 1; z <= M; z++) {
        for (int i = s.size() - 1; i >= 0; i--) {
//            dp[z][i] = dp[z][i + 1];
            dp[z][i] = 0;
            int wsp = wspolne[spos][i];
            if (wsp >= wieksze.size() || (i + wsp < s.size() && s[i + wsp] > wieksze[wsp]))
                dp[z][i] = dp_pref[z - 1][i + min(wsp, (int) wieksze.size() - 1) + 1];
            if (dp[z][i] > inf)
                dp[z][i] = inf;
            dp_pref[z][i] = dp_pref[z][i + 1] + dp[z][i];
            if (dp_pref[z][i] > inf)
                dp_pref[z][i] = inf;
        }
        debug << range(dp[z] + 0, dp[z] + s.size());
    }
    return dp[M][0];
}

int main() {
    unsigned long long K;
    scanf("%d%d%llu", &N, &M, &K);
    M--;
    cin >> s;
    vector<pair<string, int>> v;
    for (int i = 0; i < s.size(); i++) {
        string cur = "";
        for (int w = i; w < s.size(); w++) {
            cur += s[w];
            v.push_back({cur, i});
        }
    }
    sort(v.begin(), v.end(), greater<pair<string, int>>());
    for (int i = s.size() - 1; i >= 0; i--)
        for (int w = s.size() - 1; w >= 0; w--)
            if (s[i] == s[w])
                wspolne[i][w] = 1 + wspolne[i + 1][w + 1];
    int pocz = -1, kon = v.size();
    while (pocz != kon - 1) {
        int sr = (pocz + kon) / 2;
        ll ter = policz(v[sr].first, v[sr].second);
        if (ter >= K)
            kon = sr;
        else
            pocz = sr;
    }
    printf("%s", v[kon].first.c_str());
    return 0;
}