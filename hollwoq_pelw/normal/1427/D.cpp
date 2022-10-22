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
const int MAXN = 1e5 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
#define int long long

int n;
vector<vector<int>> ans;
vector<int> a;

void prc(){
    bool f = true;
    int lf, rt;
    vector<int> pos(n);
    for (int i = 0; i < n; i++){
        if (a[i] != i) f = false;
        pos[a[i]] = i;
    }
    
    if (f) return;
    //geet
    for (int i = 0; i < n - 1; i++){
        if (pos[i + 1] < pos[i]){
            lf = pos[i + 1];
            rt = pos[i];
        }
    }
    int mid;
    for (int i = lf; i < rt; i++){
        if(a[i] > a[i + 1]) mid = i;
    }
    // build
    
    //cout << lf << ' ' << mid << ' ' << rt << endl;
    vector<int> ask, na;
    if (lf) ask.pb(lf);
    if (mid + 1 - lf) ask.pb(mid + 1 - lf);
    if (rt - mid) ask.pb(rt - mid);
    if (n - rt - 1) ask.pb(n - rt - 1);
    ans.pb(ask);
    // process;
    for (int i = rt + 1; i < n; i++) na.pb(a[i]);
    for (int i = mid + 1; i < rt + 1; i++) na.pb(a[i]);
    for (int i = lf; i < mid + 1; i++) na.pb(a[i]);
    for (int i = 0; i < lf; i++) na.pb(a[i]);
    a = na; //cout << a << endl;
    prc();
}

void Solve () {
    cin >> n;
    a.resize(n);
    cin >> a;
    for (auto &v : a) v--;
    prc();
    cout << ans.size() << endl;
    for (auto vt : ans){
        cout << vt.size() << ' ' << vt << endl;
    }
}
// ('') 
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




+======================*****======================+
\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/