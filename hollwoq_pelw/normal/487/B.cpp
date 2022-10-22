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
#define int long long

int a[MAXN], n, s, l, lg[MAXN];

int stmax[MAXN][22], stmin[MAXN][22];
int nxt[MAXN], dp[MAXN];

void build(){
    for (int i = 1; i <= n; i++){
        stmax[i][0] = stmin[i][0] = a[i];
        // cout << a[i] << ' ';
    }
    cout << endl;
    for (int i = 2; i <= n; i++){
        lg[i] = lg[i / 2] + 1;
    }
    for (int j = 1; j < 22; j++){
        for (int i = 1; i + (1 << j) <= n + 1; i++){
            stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
            stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    int j = lg[r - l + 1];
    int mn = min(stmin[l][j], stmin[r - (1 << j) + 1][j]);
    int mx = max(stmax[l][j], stmax[r - (1 << j) + 1][j]);
    // cout << "query " << l << ' ' << r << " : ";
    // cout << mx << ' ' << mn << endl;
    return mx - mn;
}

void Solve() {
    cin >> n >> s >> l;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build();
    int cur = 1, ans = 0;
    for (int cur = 1; cur <= n; cur++){
        int tl = cur + l - 1, tr = n, res = -1;
        // cout << tl << endl;
        while(tl <= tr){
            int tm = tl + tr >> 1;
            if (query(cur, tm) <= s){
                res = tm;
                tl = tm + 1;
            }else{
                tr = tm - 1;
            }
        }
        nxt[cur] = res;
    }
    dp[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= n; i++){
        dp[i] = inf;
        if (i - l >= 0)
            pq.push({dp[i - l], nxt[i - l + 1]});
        while(!pq.empty() && pq.top().S < i){
            pq.pop();
        }
        if (!pq.empty()) dp[i] = pq.top().F + 1;
        // cout << dp[i] << ' ';
    }
    if (dp[n] >= inf)
        dp[n] = -1;
    cout << dp[n];
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

\/-=====>>><<<-------- DEBUG -------->>><<<=====-\/
/\.............................................../\
+====================== INP ======================+


+====================== OUT ======================+


+======================*****======================+
\/...............................................\/
/\-=====>>><<<--------= END =-------->>><<<=====-/\

*/