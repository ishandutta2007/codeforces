#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n) - 1; i >= (int)(a); --i)
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

template<typename T, typename S>
istream& operator>> (istream& in, pair<S, T>& p) {
    in >> p.fs >> p.sn;
    return in;
}
template<typename T, typename S>
ostream& operator<< (ostream& out, pair<S, T>& p) {
    out << p.fs << ' ' << p.sn << ' ';
    return out;
}

template<typename T>
istream& operator>> (istream& in, vector<T>& v) {
    for (T& x : v) in >> x;
    return in;
}
template<typename T>
ostream& operator<< (ostream& out, vector<T>& v) {
    for (T& x : v) out << x << ' ';
    return out;
}

const ld eps = 1e-9;
const int INF = 1e9 + 100;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 4e5 + 10;
const int LOG = 19;

int pr1[LOG][N], pr2[LOG][N], mx1[LOG][N];
ll sum2[LOG][N];

int main() {
    int Q;
    scanf("%d", &Q);
    int last = 0, cnt = 2;
    forn(i, 0, LOG) {
        sum2[i][0] = LINF;
    }
    while (Q--) {
        int tp;
        ll p, q;
        scanf("%d %lld %lld", &tp, &p, &q);
        if (tp == 1) {
            int par = int(p ^ last), w = int(q ^ last);
            pr1[0][cnt] = par;
            forn(i, 1, LOG)
                pr1[i][cnt] = pr1[i - 1][pr1[i - 1][cnt]];
            mx1[0][cnt] = w;
            forn(i, 1, LOG)
                mx1[i][cnt] = max(mx1[i - 1][cnt], mx1[i - 1][pr1[i - 1][cnt]]);
            int u = par;
            ford(i, 0, LOG)
                if (mx1[i][u] < w)
                    u = pr1[i][u];
            pr2[0][cnt] = mx1[0][u] >= w ? u : pr1[0][u];
            forn(i, 1, LOG)
                pr2[i][cnt] = pr2[i - 1][pr2[i - 1][cnt]];
            sum2[0][cnt] = w;
            forn(i, 1, LOG)
                sum2[i][cnt] = min(LINF, sum2[i - 1][cnt] + sum2[i - 1][pr2[i - 1][cnt]]);
            ++cnt;
        } else {
            int u = int(p ^ last);
            ll lim = q ^ last;
            int ans = 0;
            ford(i, 0, LOG) {
                if (pr2[i][u] == 0) continue;
                if (sum2[i][u] <= lim) {
                    //printf("!!!: %d\n", i);
                    lim -= sum2[i][u];
                    u = pr2[i][u];
                    ans += (1 << i);
                }
            }
            if (u && sum2[0][u] <= lim) ++ans;
            //printf("here: %d\n", sum2[0][u]);
            printf("%d\n", ans);
            last = ans;
        }
    }
    /*
    forn(i, 0, cnt) cout << pr1[0][i] << ' ';
    cout << '\n';
    forn(i, 0, cnt) cout << pr2[0][i] << ' ';
    */
}