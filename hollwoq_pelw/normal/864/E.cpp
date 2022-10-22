/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 1e5 + 6 , MAXM = 2e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

struct item{
    int d, t, p, id;
    item(int t, int d, int p, int i) : t(t), d(d), p(p), id(i) {}
    bool operator < (const item& oth) const {
        return (d < oth.d) || (d == oth.d && (t < oth.t || (t == oth.t && (p < oth.p || (p == oth.p && id < oth.id)))));
    }
};

int n, dp[202][2020];

void Solve() {
    cin >> n;
    vector<item> arr;
    for (int i = 0; i < n; i++){
        int t, d, p;
        cin >> t >> d >> p;
        arr.eb(t, d, p, i+1);
    }
    sort(all(arr));
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= 2000; j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (arr[i].t + j < arr[i].d){
                dp[i+1][j + arr[i].t] = max(dp[i+1][j + arr[i].t], dp[i][j] + arr[i].p);
            }
        }
    }
    /*
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < 30; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    */
    int cur = max_element(dp[n], dp[n] + 2020) - dp[n];
    cout << dp[n][cur] << endl;
    vector<int> ans;
    for (int i = n-1; i >= 0; i--){
        if (arr[i].d > arr[i].t && arr[i].t <= cur && dp[i][cur - arr[i].t] == dp[i+1][cur] - arr[i].p){
            ans.push_back(arr[i].id);
            cur -= arr[i].t;
        }
    }
    reverse(all(ans));
    cout << sz(ans) << endl;
    for (auto v : ans) cout << v << ' ';
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\


+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/