#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
// #define For(i, l, r, x)     for (int i = l; i < r; i+=x)
// #define ForE(i, l, r, x)    for (int i = l; i <= r; i+=x)
// #define Ford(i, r, l)       for (int i = r; i > l; i--)
// #define FordE(i, r, l)      for (int i = r; i >= l; i--)
#define Fora(i, a)          for (auto i : a)
// I/O 
#define IOS                 std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PrintV(a)           Fora(ii, a) cout << ii << ' '; cout << endl;
#define PrintVl(a)          Fora(ii, a) cout << ii << endl;
#define PrintA(a, l, r)     for (int ii = l; ii <= r; ii++) cout << a[ii] << ' '; cout << endl;
#define PrintAl(a, l, r)    for (int ii = l; ii <= r; ii++) cout << a[ii] << endl;
#define Ptest(x)            return cout << x, 0;
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
#define ms0(a)              memset(a, 0, sizeof(a));
#define ms1(a)              memset(a, 1, sizeof(a));
#define msn1(a)             memset(a, -1, sizeof(a));
// constant
const int mod1 = 998244353, mod2 = 1e9+7;
const int N = 100005, M = 200010;
//
void solve() {
    ll n,x,y;
    cin >> n >> x >> y;
    ll d1 = max(x-1, y-1);
    ll d2 = max(n-x, n-y);
    if (d1 <= d2) cout << "White";
    else cout << "Black";
}

signed main(){
    IOS;
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}