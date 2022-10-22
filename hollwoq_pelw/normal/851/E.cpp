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
//
#define int long long
int n, x;
map<int, int> dp, pp;

int g(int x){
    if(dp.count(x))
        return dp[x];
    unordered_set<int>s;
    for(int i = 1; i<=30; ++i){
           int y = (x>>i) | (x & ( (1<<(i-1)) - 1));
        if(y != x)
            s.insert(g(y));
    }
    int ans = 0;
    while(s.count(ans))
        ++ans;
    return dp[x] = ans;
}

void Solve() {
	cin >> n;
	for (int i = 0, x; i < n; i++){
	    cin >> x;
	    for(int p = 2; p * p <= x; ++p){
            if(x%p == 0){
                int cn = 0;
                while(x%p==0){
                    ++cn;
                    x/=p;
                }
                pp[p] |= 1 << (cn-1);
            }
        }
        if(x>1) pp[x] |=1;
	}
    dp[0] = 0;
    int ans = 0;
    for(auto e : pp)
        ans ^= g(e.S);
    puts(ans ? "Mojtaba" : "Arpa");
}

signed main(){
    FAST_IO;
    int TC = 1; 
//	cin >> TC;
    while(TC--) Solve();
    return 0;
}