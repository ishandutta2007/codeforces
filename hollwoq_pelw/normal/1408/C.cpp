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
const int MAXN = 1e6 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int n, l;
ld a[MAXN];
ld tim[MAXN][2];
ld spd[MAXN][2];
int test;

void Solve () {
    cin >> n >> l;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[0] = 0; a[n + 1] = l;
    tim[0][0] = tim[n + 1][1] = 0;
    for (int i = 1; i <= n + 1; i++){
        tim[i][0] = tim[i - 1][0] + (a[i] - a[i - 1]) / i;
        int j = n + 1 - i;
        tim[j][1] = tim[j + 1][1] + (a[j + 1] - a[j]) / i;
        spd[i][0] = spd[j][1] = i;
    }
    for (int i = 1; i <= n + 1; i++){
        ld t1 = tim[i - 1][0], t2 = tim[i][1];
        ld sp1 = spd[i][0], sp2 = spd[i - 1][1];
        ld gap = a[i] - a[i - 1];
        if (t1 < t2){
            ld x = t2 - t1;
            gap -= x * sp1;
        }else{
            ld x = t1 - t2;
            gap -= x * sp2;
        }
        if (gap < 0) continue;
        ld t = gap / (sp1 + sp2);
        cout << setpre(10) << t + max(t1, t2) << endl;
        return ;
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    cin >> TC;
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