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
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)        
bool endline = false;
template<class T>
istream& operator >> (istream& inp, vector<T>& v){
    for (auto& it : v) inp >> it;
    return inp;
}
template<class T>
ostream& operator << (ostream& out, vector<T>& v){
    for (auto& it : v) out << it << (endline ? "\n" : " ");
    return out;
}
template<class T, class U>
istream& operator >> (istream& inp, pair<T, U>& v){
    inp >> v.F >> v.S;
    return inp;
}
template<class T, class U>
ostream& operator << (ostream& out, pair<T, U>& v){
    out << v.F << ' ' << v.S;
    return out;
}
#define debug(x)            cout << #x << " : " << endl << x << endl;
#define Ptest(x)            return cout << x << endl, (void) 0;
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
const int MAXN = 2e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
// #define int long long

int n[5], st[MAXN][25], dp[5][MAXN]; 
vector<int> block[MAXN];
int lg[MAXN];

void build(int s){
    for (int i = 1; i <= n[s]; i++)
        st[i][0] = dp[s][i];
    for (int j = 1; j < 24; j++){
        for (int i = 1; i + (1 << j) <= n[s] + 1; i++){
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    if (l > r) return inf;
    int j = lg[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

void Solve() {
    for (int i = 2; i < MAXN; i++){
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= 4; i++)
        cin >> n[i];
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= n[i]; j++){
            cin >> dp[i][j];
        }
    }
    for (int st = 2; st <= 4; st++){
        build(st - 1);
        // cout << query(1, 2);
        for (int i = 1; i <= n[st]; i++){
            block[i].clear();
            block[i].pb(0);
            block[i].pb(n[st - 1] + 1);
        }
        int q; cin >> q;
        for (int i = 1, x, y; i <= q; i++){
            cin >> x >> y;
            block[y].pb(x);
        }
        for (int i = 1; i <= n[st]; i++){
            int val = inf;
            sort(all(block[i]));
            for (int j = 1; j < block[i].size(); j++){
                val = min(val, query(block[i][j - 1] + 1, block[i][j] - 1));
            }
            // cout << val << endl;
            dp[st][i] = min(dp[st][i] + val, (int) inf);
        }
        // for (int i = 1; i <= n[st]; i++){
        //     cout << dp[st][i] << ' ';
        // }
        // cout << endl;
    }
    int ans = *min_element(dp[4] + 1, dp[4] + n[4] + 1);
    if (ans >= inf) ans = -1; cout << ans;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    // cin >> TC;
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