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
const int mod1 = 998244353, mod = 1e9+7, INF = 2e9;
const int MAXN = 100005, MAXM = 200010;
// code
#define int long long
typedef vector < vector < int > > Mtx;

Mtx mul(Mtx a, Mtx b) {
    Mtx ans(a.size(), vector<int>(b[0].size()));
    for(int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[i].size(); j++){
            for (int k = 0; k < b[0].size(); k++){
                (ans[i][k] += a[i][j] * b[j][k]) %= mod;
            }
        }
    }
    return ans;
}

Mtx binpow(Mtx a, int b) {
	if (b == 1)
        return a;
    Mtx t = binpow(a, b/2);
    if (b & 1)
        return mul(mul(t, t), a);
	return mul(t, t);
}

int n, b, k, x;
int arr[50005];

void Solve() {
	cin >> n >> b >> k >> x;
	Mtx A(x, vector<int>(x));
	for (int i = 0; i < n; ++i)
        cin >> arr[i];
	for (int i = 0; i < x; ++i)
        for (int j = 0; j < n; ++j)
            A[i][(i * 10 + arr[j]) % x] ++;

	Mtx B(1, vector<int>(x));
	B[0][0] = 1;

    cout << mul(B, binpow(A, b))[0][k] << endl;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO;
    int TC = 1;
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