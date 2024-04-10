//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;

#define fst first
#define snd second
#define mp make_pair
//#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

#define ADD_OPERATORS_IN(T, COMP) \
    bool operator < (const T& ot) const { return COMP(ot) == -1; } \
    bool operator > (const T& ot) const { return COMP(ot) == 1; } \
    bool operator == (const T& ot) const { return COMP(ot) == 0; } \
    bool operator != (const T& ot) const { return COMP(ot) != 0; }

#define ADD_OPERATORS_OUT(T, COMP) \
    bool operator < (const T& a, const T& b) const { return COMP(a, b) == -1; } \
    bool operator > (const T& a, const T& b) const { return COMP(a, b) == 1; } \
    bool operator == (const T& a, const T&b) const { return COMP(a, b) == 0; } \
    bool operator != (const T& a, const T&b) const { return COMP(a, b) != 0; }


typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 1e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
const int pp = 41;
#define next ajksdslk

double p[maxn];
vector<int> g[maxn];
ld f[maxn][2];
int n;

int pre[maxn];
double sump[maxn];
void dfs(int v, int pred = -1) {
    pre[v] = pred;
    for (int to : g[v]) {
        if (to == pred) continue;
        dfs(to, v);
        sump[v] += p[to];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    scanf("%d", &n);

    for (int i = 0; i < n; i ++) {
        scanf("%lf", p + i);
    }
    for (int i = 1; i < n; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }

    double ans = 1;
    for (int i = 0; i < n; i++) {
        ans += 1. * p[i] * ((int)g[i].size() - 1);
        for (int j : g[i]) {
            if (i < j)
                ans -= 1. * p[i] * p[j];
        }
    }

    dfs(0);

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int u;
        double x;

        scanf("%d %lf", &u, &x);

        ans -= p[u] * ((int)g[u].size() - 1);
        ans += x    * ((int)g[u].size() - 1);

        ans += p[u] * (sump[u] + (u == 0 ? 0. : p[pre[u]]));
        ans -= x * (sump[u] + (u == 0 ? 0. : p[pre[u]]));

        if (u != 0) {
            sump[pre[u]] -= p[u];
            sump[pre[u]] += x;
        }

        p[u] = x;
        printf("%6lf\n", ans);
    }
//    dfs(0);
//    cout << fixed << setprecision(10) << f[0][0] + f[0][1] << '\n';
    return 0;
}



/*
 *
 *
 */