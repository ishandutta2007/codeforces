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
#define Ptest(x) return cout << x << endl, (void) 0;
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
#define int long long

int a[MAXN], kp[MAXN], bit[MAXN], n;

void upd(int x, int v){
    for (; x < MAXN; x += x & (-x))
        bit[x] += v;
}

int query(int x){
    int r = 0;
    for (; x; x -= x & (-x))
        r += bit[x];
    return r;
}

void upd2(int l, int r, int v){
    r = min(r, n);
    if (l > r) return;
    upd(l, v);
    upd(r + 1, -v);
}

void Solve () {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= 1) continue;
		ans += a[i] - 1;
		for (int j = 1; j <= n; j++) bit[j] = 0;
	    upd2(i + 2, i + a[i], 1);
		for (int j = i + 1; j <= n; j++) {
			int d = query(j);
			if (a[j] - d < 1) {
				upd2(j + 1, j + 1, d - a[j] + 1);
				upd2(j + 2, j + a[j], 1);
				a[j] = 1;
			}
			else {
				upd2(j + a[j] - d + 1, j + a[j], 1);
				a[j] -= d;
			}
		}
		a[i] = 1;
// 		for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
	}
	cout << ans << '\n';
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