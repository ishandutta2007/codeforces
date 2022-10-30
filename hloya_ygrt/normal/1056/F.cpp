#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <algorithm>
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

const int maxn = (int) 1e6 + 25;
const int maxlog = 21;
// const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-12;
const ld PI = acos(-1.);
const ll llinf = 1e18;
const int inf = 2e9;

pair<int, int> b[101];
ld dp[101][101][10 * 101];

ld power[105];

ld dsolve(ld a, ld b, ld c) {
    ld D = sqr(b) - 4. * a * c;
    if (D < -eps) {
        return -1;
    }

    return (-b + sqrt(D)) / (2. * a);
}

void solve() {
    int n;
    cin >> n;

    ld C, T;
    cin >> C >> T;

    for (int i = 0; i < n; i++) {
        int a, p;
        cin >> a >> p;
        b[i] = mp(a, p);
    }

    sort(b, b + n);
    reverse(b, b + n);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++)
            for (int prof = 0; prof <= j * 10; prof++)
                dp[i][j][prof] = 1e50;

    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            for (int prof = 0; prof <= j * 10; prof++) {
                if (dp[i][j][prof] > (ld)1e48)
                    continue;
                // not take
                upmin(dp[i + 1][j][prof], dp[i][j][prof]);
                // take
                upmin(dp[i + 1][j + 1][prof + b[i].s], dp[i][j][prof] + (ld)b[i].f / power[j]);
            }

    int ans = 0;
    for (int taken = 0; taken <= n; taken++)
        for (int prof = 0; prof <= taken * 10; prof++) {
            if (dp[n][taken][prof] > (ld)1e48) continue;
            if (dp[n][taken][prof] + taken * 10. < T + eps) {
                upmax(ans, prof);
            } else {
                ld t1 = dp[n][taken][prof];
                ld root = dsolve(C, 10. * taken * C + 1 - C * T, 10. * taken - T + t1);
                if (root >= 0) {
                    upmax(ans, prof);
                }
            }
        }
    cout << ans << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);

    power[0] = 0.9;
    for (int i = 1; i < 105; i++) {
        power[i] = power[i - 1] * 0.9;
    }
    
    int t;
    cin >> t;

    while (t--)
        solve();
    return 0; 
}