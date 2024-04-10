#ifndef LOCAL
#pragma GCC optimize("O3")
#endif

#include "bits/stdc++.h"
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace std;

//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
//~ using namespace __gnu_pbds;
//~ template <typename T>
//~ using ordered_set =
//~ tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim>
struct rge {
    c b, e;
};

sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }

sim> auto dud(c *x) -> decltype(cerr << *x, 0);

sim> char dud(...);

struct debug {
#ifdef LOCAL

    ~debug() { cerr << endl; }

    eni(!=) cerr << boolalpha << i;
        ris; }

    eni(==) ris << range(begin(i), end(i)); }

    sim, class b dor(pair<b, c> d) {
        ris << "(" << d.first << ", " << d.second << ")";
    }

    sim dor(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        ris << "]";
    }

#else
    sim dor(const c&) { ris; }
#endif
};

debug debug;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#ifdef LOCAL
mt19937 rng(unsigned(69));
#else
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
#define rand rng

using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int MAXN = 100007;

int tab[MAXN];

int dp[10][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        memset(dp, 0, sizeof(dp));
        for (auto it : s) {
            for (int i = 0; i <= 9; i++) {
                for (int w = 0; w <= 9; w++) {
                    if (i == w) {
                        if (it - '0' == i)
                            dp[i][w]++;
                    } else {
                        if (it - '0' == i && dp[i][w] % 2 == 0) {
                            dp[i][w]++;
                        } else if (it - '0' == w && dp[i][w] % 2 == 1) {
                            dp[i][w]++;
                        }
                    }
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < 10; i++)
            maxi = max(maxi, dp[i][i]);
        for (int i = 0; i < 10; i++) {
            for (int w = 0; w < 10; w++) {
                maxi = max(maxi, dp[i][w] - (dp[i][w] % 2));
            }
        }
        cout << s.length() - maxi << "\n";
    }
    return 0;
}