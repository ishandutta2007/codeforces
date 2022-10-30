#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC optimize("unroll-loops")
using namespace std;

#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef list<int> vi;

//mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 3e5 + 22;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = (ll) 1e18 + 5;
const int inf = 2e9 + 5;

const int mod = 998244353;

int dp[2005][2005];

int add(int x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int n, m, k;
    cin >> n >> m >> k;

    dp[0][0] = m;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            // j
            dp[i][j] = add(dp[i - 1][j], ((j > 0) ? (1ll * dp[i - 1][j - 1] * (m - 1) % mod) : 0));
            // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }

    cout << dp[n - 1][k];
    return 0;
}