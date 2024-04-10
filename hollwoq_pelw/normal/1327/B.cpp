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
//#define PrintV(a)           Fora(ii, a) cout << ii << ' '; cout << endl;
//#define PrintVl(a)          Fora(ii, a) cout << ii << endl;
//#define PrintA(a, l, r)     for (int ii = l; ii <= r; ii++) cout << a[ii] << ' '; cout << endl;
//#define PrintAl(a, l, r)    for (int ii = l; ii <= r; ii++) cout << a[ii] << endl;
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
const int mod1 = 998244353, mod2 = 1e9+7;
const int N = 100005, M = 200010;
//
void solve() {
    int n, k;
    cin >> n;
    vector<int> a[n];
    set<int> ck;
    for (int i = 0; i < n; i ++){
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++){
            cin >> a[i][j];
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= sz(a[i]); j++){
            if (j == sz(a[i])){
                if (ans == -1) ans = i+1;
                break;
            }
            if (!ck.count(a[i][j])){
                ck.insert(a[i][j]);
                break;
            }
        }
    }
    if (ans != -1){
        cout << "IMPROVE\n" << ans << ' ';
        for (int i = 1; i <= n; i++){
            if (!ck.count(i)) {
                cout << i << endl;
                return;
            }
        }
    }
    cout << "OPTIMAL\n";
}

signed main(){
    FAST_IO;
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}