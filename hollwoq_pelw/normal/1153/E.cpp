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
const int mod1 = 998244353, mod = 1e9+7;
const int MAXN = 100005, MAXM = 200010;
// code
#define int long long

int query(int x1, int x2, int y1, int y2){
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    int a; cin >> a; return a & 1;
}

int n;
void Solve(){
    cin >> n;
    vector<int> xp, yp;
    for (int i = 1; i <= n; i++)
        if (query(i, i, 1, n)) xp.eb(i);
    
    for (int i = 1; i <= n; i++)
        if (query(1, n, i, i)) yp.eb(i);
    
    if (xp.empty()){
        // same row
        int l = 1, r = n;
        while(l < r){
            int m = (l + r) / 2;
			if (query(l, m, yp[0], yp[0]))
				r = m;
			else
				l = m + 1;
        }
        cout << "! " << l << ' ' << yp[0] << ' ' << l << ' ' << yp[1] << endl;
        return ;
    }
    if (yp.empty()){
        // same col
        int l = 1, r = n;
        while(l < r){
            int m = (l + r) / 2;
			if (query(xp[0], xp[0], l, m))
				r = m;
			else
				l = m + 1;
        }
        cout << "! " << xp[0] << ' ' << l << ' ' << xp[1] << ' ' << l << endl;
        return ;
    }
    if (!query(xp[0], xp[0], yp[0], yp[0])){
        swap(xp[0], xp[1]);
    }
    cout << "! " << xp[0] << ' ' << yp[0] << ' ' << xp[1] << ' ' << yp[1] << endl;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    //cin >> TC;
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