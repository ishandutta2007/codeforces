/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#pragma Ofast
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
#define debug(x)            cout << #x << " = " << x << endl;
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
const int MAXN = 3e5 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long
/*

13 5
--  1 2 3  4 5 6 7 8 9 10 11 12 13 --
a   2 2 3  9 5 4 6 5 7  8  3 11 13
b  -1 0 0 -5 0 2 1 3 2  2  8  1  0

++>>> delete a zero and decrease all number behind by 1

3 1


0 0


2 4


5 0


0 12

*/

int ans[MAXN], a[MAXN];
vector<int> query[MAXN];
int bit[MAXN], lf[MAXN];
int n, q;

void upd(int x, int v = 1){
    for (; x <= n; x += x & -x)
        bit[x] += v;
}

void qry(int x, int &v){
//  int res = 0;
	for (; x; x -= x & -x)
		v -= bit[x];
//      res += bit[x];
//	return res;
}

void Solve () {
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = i - a[i];
    }
    for (int i = 0, x, y; i < q; i++){
        cin >> x >> y;
        x = 1 + x;
        y = n - y;
		lf[i] = x;
		query[y].pb(i);
    }
	int cur = 0, jp = __lg(n);
	for (int r = 1; r <= n; ++r) {
		if (a[r] >= 0) {
			int pos = 0, tmp = cur;
			for (int j = 1 << jp; j; j >>= 1)
				if (pos + j <= r && tmp - bit[pos+j] >= a[r])
					pos += j, tmp -= bit[pos];
			++cur;
			upd(pos + 1);
		}
		for (int i : query[r]) {
			ans[i] = cur;
			qry(lf[i], ans[i]);
		}
	}

	for (int i = 0; i < q; ++i)
		cout << ans[i] << endl;
    
}

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