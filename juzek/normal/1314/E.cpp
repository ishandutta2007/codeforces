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

const int MAXN = 2027;

ll dp1[MAXN][MAXN];
ll dp2[2][MAXN][MAXN];

int N;
int K;
int wyn3 = 0;

bool check(vector<int> t) {
    vector<int> tt;
    int KK = K;
    while (KK--) {
        int sum = 0;
        for (auto it : t)
            sum += it;
        if (sum > N)
            return false;
        tt.resize(sum);
        int ile = 0;
        for (int i = t.size() - 1; i >= 0; i--)
            for (int w = 0; w < t[i]; w++)
                tt[ile++] = i + 1;
        swap(t, tt);
    }
    return true;
}

void adam(int n, int m, vector<int> &wziete) {
    if (check(wziete))
        wyn3++;
    else
        return;
    for (int i = min(n, m); i >= 1; i--) {
        wziete.push_back(i);
        adam(n - i, i, wziete);
        wziete.pop_back();
    }
}

int main() {
    const int mod = 998244353;
    scanf("%d%d", &N, &K);
    if (K == 1) {
        for (int i = 0; i <= N; i++)
            dp1[0][i] = 1;
        ll wyn = 0;
        for (int sum = 1; sum <= N; sum++) {
            for (int x = 1; x <= sum; x++) {
                dp1[sum][x] = dp1[sum][x - 1] + dp1[sum - x][x];
                dp1[sum][x] %= mod;
            }
            for (int x = sum + 1; x <= N; x++)
                dp1[sum][x] = dp1[sum][x - 1];
            wyn += dp1[sum][N];
            wyn %= mod;
        }
        printf("%lld", wyn);
    } else if (K == 2) {
        int curr = 0;
        for (int i = 0; i <= N; i++)
            dp2[curr][0][i] = 1;
        ll wyn = 0;
        for (int n = 1; n <= 64; n++) {
            curr = !curr;
            for (int sum = 1; sum <= N; sum++) {
                for (int x = N; x >= 1; x--) {
                    if (sum - x * n >= 0)
                        dp2[curr][sum][x] = dp2[!curr][sum - x * n][x];
                    else
                        dp2[curr][sum][x] = 0;
                    dp2[curr][sum][x] %= mod;
                    wyn += dp2[curr][sum][x];
                    wyn %= mod;
                    dp2[curr][sum][x] += dp2[curr][sum][x + 1];
                }
                debug << imie(n) imie(sum);
                debug << range(dp2[curr][sum] + 1, dp2[curr][sum] + N + 1);
            }
            for (int x = 0; x <= N; x++)
                dp2[curr][0][x] = 0;
        }
        printf("%lld", wyn);
    } else {
        vector<int> wziete;
        int maxi = (int) sqrt(2 * N);
        adam(maxi, maxi, wziete);
        printf("%d", wyn3 - 1);
    }
    return 0;
}