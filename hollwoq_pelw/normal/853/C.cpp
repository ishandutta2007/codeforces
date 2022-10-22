#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r, x)     for (int i = l; i < r; i+=x)
//#define ForE(i, l, r, x)    for (int i = l; i <= r; i+=x)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O 
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define PrintV(a)           Fora(ii, a) cout << ii << ' '; cout << rl;
//#define PrintVl(a)          Fora(ii, a) cout << ii << rl;
//#define PrintA(a, l, r)     for (int ii = l; ii <= r; ii++) cout << a[ii] << ' '; cout << rl;
//#define PrintAl(a, l, r)    for (int ii = l; ii <= r; ii++) cout << a[ii] << rl;
//#define Ptest(x)            return cout << x, 0;
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
// geometry calc    
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
const int MAX_N = 100005, MAX_M = 200010;
// code
vector<int> t[MAX_M];
int n, q, p[MAX_M];
void upd(int x, int v){
    for (; x < MAX_M; x += x & (-x)){
        t[x].pb(v);
    }
}

int query(int x, int val){
    int ans = 0;
    for (; x > 0; x -= x & (-x)){
        ans += lower_bound(all(t[x]), val+1) - t[x].begin();
    }
    return ans;
}

ll calc(int x){
    return 1ll * x * (x-1) / 2;
}

void Solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
        upd(p[i], i);
    }
    
    while (q--){
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        /*
        divide by region
         A  |  B  | C
        ----+-----+---
         D  |  E  | F
            |     |
        ----+-----+---
         G  |  H  | I
        */
        int A = query(d-1, l-1);
        int B = query(d-1, r) - A;
        int C = query(d-1, n) - A - B;
        
        int D = query(u, l-1) - A;
        int E = query(u, r) - A - D - B;
        int F = query(u, n) - A - D - B - E - C;
        
        int G = query(n, l-1) - A - D;
        int H = query(n, r) - A - D - G - B - E;
        int I = query(n, n) - A - D - G - B - E - H - C - F;
        
        ll res = calc(n) - calc(A+B+C) - calc(C+F+I) - calc(I+H+G) - calc(G+D+A) + calc(A) + calc(C) + calc(I) + calc(G);
        cout << res << endl;
    }
}

signed main(){
    FAST_IO;
    int TC = 1; 
	//cin >> TC;
    while(TC--) Solve();
    return 0;
}