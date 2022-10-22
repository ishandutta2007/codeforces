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
const int MAXN = 100005, MAX_M = 200010;
// code
#define int long long

int n, m, x, k, y;
int pos[MAX_M];
int a[MAX_M], b[MAX_M];
void Solve() {
    cin >> n >> m;
    cin >> x >> k >> y;
    int z = min(x, k*y);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
	}
	for (int i = 1; i <= m; i++){
        cin >> b[i];
        b[i] = pos[b[i]];
	}
	b[m+1] = n+1;
	int ans = 0;
	for (int i = 0; i <= m; i++){
        int l = b[i], r = b[i+1], mx = a[l+1];
        for (int j = l+1; j < r; j++){
            mx = max(mx, a[j]);
        }
        //cout << l << ' ' << r << ' ' << mx << endl;
        //cout << r - l - 1 << ' ' << (r-l-1) / k * z + (r-l-1) % k * y << endl;
        if (mx > max(a[l], a[r]) && r - l - 1 < k && r - l - 1 > 0 || r - l - 1 < 0){
            cout << -1;
            return;
        }
        ans += (r-l-1) / k * z + (r-l-1) % k * y;
        if (mx > max(a[l], a[r])){
            ans += x - z;
        }
    }
    //cerr << z << ' ' << y;
    cout << ans;
}

signed main(){
    FAST_IO;
    int TC = 1;
    //cin >> TC;
    while(TC--) Solve();
    return 0;
}