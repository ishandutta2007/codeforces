#include <bits/stdc++.h>
using namespace std;
// type
#define int long long
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r, x)     for (int i = l; i < r; i+=x)
//#define ForE(i, l, r, x)    for (int i = l; i <= r; i+=x)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O 
#define openfile(file)      freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
#define testinput(file)     freopen(file".txt", "r", stdin); 
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
const int MAXN = 1000005, MAXM = 200010;
// code

pii arr[5050];
int n, S;

inline int area(pii A, pii B, pii C){
	return abs((B.F-A.F)*(C.S-A.S)-(B.S-A.S)*(C.F-A.F));
}

void Solve() {
    cin >> n >> S;
    for (int i = 0; i < n; i++)
        cin >> arr[i].F >> arr[i].S;
    sort(arr, arr+n);
    
	int a = 0, b = 1, c = 2;
	int s = area(arr[a], arr[b], arr[c]);
	while (1){
		bool chk = false;
		for(int i = 0; i < n; ++i){
			int ns = area(arr[a], arr[b], arr[i]);
			if (ns > s) s = ns, c = i, chk = true;
		}
		for(int i = 0; i < n; ++i){
		    int ns = area(arr[a], arr[c], arr[i]);
			if (ns > s) s = ns, b = i, chk = true;
		}
		for(int i = 0; i < n; ++i){
			int ns = area(arr[b], arr[c], arr[i]);
			if (ns > s) s = ns, a = i, chk = true;
		}
		// after each loop value of a, b, c must be larger
		if (!chk) break;
	}
	
	cout << arr[b].F+arr[c].F-arr[a].F << ' ' << arr[b].S+arr[c].S-arr[a].S << endl;
	cout << arr[b].F+arr[a].F-arr[c].F << ' ' << arr[b].S+arr[a].S-arr[c].S << endl;
	cout << arr[a].F+arr[c].F-arr[b].F << ' ' << arr[a].S+arr[c].S-arr[b].S << endl;
}

signed main(){
    FAST_IO;
    int TC = 1;
	//cin >> TC;
    while(TC--) Solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}