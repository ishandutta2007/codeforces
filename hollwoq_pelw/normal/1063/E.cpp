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
const int mod1 = 998244353, p = 1e9+7;
const int MAX_N = 100005, MAX_M = 200010;
// code
const int N = 1005;
char mat[N][N];
int stt[N], fin[N];
void Solve() {
	int n; cin >> n;
	bool corner = false;
	for (int i = 1; i <= n; i++){
		cin >> stt[i];
		fin[stt[i]] = i;
		if(stt[i] != i) corner = true;
	}
	for (int i = 1; i <= n; i++){
	    for (int j = 1; j <= n; j++){
	        mat[i][j] = '.';
	    }
	}
	cout << n - (int) (corner) << endl;
	if(corner) {
		int f = n, P = 0; // the current floor
    	for(int i = 1; i <= n; i++)
    	    if(stt[i] == 1)
    	        P = i;
    	mat[f][1] = mat[f][P] = '/'; 
    	f --;
    	swap(stt[1], stt[P]);
    	for(int i = 1; i <= n; i++) 
    	    fin[stt[i]] = i;
    	for(int val = 2; val <= n; val++){
    	    if(stt[val] != val) {
        		mat[f][1] = '\\';
        		vector<int> cyc; cyc.pb(val);
        		int cur = fin[val];
        		while(cur != val) {
        			cyc.pb(cur);
        			cur = fin[cur];
        		}
        		for(int i = 1; i < sz(cyc); i++) {
        			swap(stt[cyc[i]], stt[cyc[i-1]]);
        			if(cyc[i] > cyc[i-1]) // we need to move to right
        			    mat[f][cyc[i]] = mat[f][cyc[i-1]]='\\';
        			else // move to left
        			    mat[f][cyc[i]] = mat[f][cyc[i-1]]='/';
        			f--;
        		}
        		mat[f][1]='/', mat[f][cyc.back()]='/';
        		f--;
        	}
        }
	}
	
	for (int i = 1; i <= n; i++){
	    for (int j = 1; j <= n; j++)
	        cout << mat[i][j];
	    cout << endl;
	}
}


signed main(){
    FAST_IO;
    int TC = 1; 
	//cin >> TC;
    while(TC--) Solve();
    return 0;
}