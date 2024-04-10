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
#define msINT_MAX(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod2 = 1e9+7;
const int MAX_N = 100005, MAX_M = 200010;
//
const int B = 500;
int offset[MAX_M/B], cnt[MAX_M/B][B+2], his[MAX_M];
const int mod = 998244353;

void m_add(int& a, int b) {
	a += b;
	if(a >= mod) {
		a -= mod;
	}
}

void Solve() {
	int n, k;
	cin >> n >> k;
	vector<int> dp(B + n + 2);

	auto ogar = [&](int blk) {
		for(int i = 0; i <= B; ++i) {
			cnt[blk][i] = 0;
		}
		int mn = INT_MAX;
		for(int i = max(1, blk * B); i < (blk + 1) * B; ++i) {
			mn = min(mn, his[i]);
		}
		offset[blk] += mn;
		for(int i = max(1, blk * B); i < (blk + 1) * B; ++i) {
			his[i] -= mn;
			m_add(cnt[blk][his[i]], dp[i]);
		}
		for(int i = 1; i <= B; ++i) {
			m_add(cnt[blk][i], cnt[blk][i-1]); // prefix sum
		}
	};
	
	auto add = [&](int L, int R, int x) {
		int left = L / B;
		int right = R / B;
		for(int i = left + 1; i < right; ++i) {
			offset[i] += x;
		}
		for(int i = L; i <= R && i / B == left; ++i) {
			his[i] += x;
		}
		ogar(left);
		if(left != right) {
			for(int i = R; i / B == right; --i) {
				his[i] += x;
			}
			ogar(right);
		}
	};
	
	dp[1] = 1;	
	ogar(0);
	
	vector<int> last(n + 1), s_last(n + 1);
	for(int me = 1; me <= n; ++me) {
		int x;
		cin >> x;
		if(last[x]) {
			add(s_last[x] + 1, last[x], -1);
		}
		add(last[x] + 1, me, 1);
		s_last[x] = last[x];
		last[x] = me;
		
		int Z = 0;
		for(int blk = 0; blk <= me / B; ++blk) {
			int up_to = min(k - offset[blk], B);
			if(up_to >= 0) {
				m_add(Z, cnt[blk][up_to]);
			}
		}
		dp[me+1] = Z;
		ogar((me + 1) / B);
	}
	cout << dp[n+1];
}

signed main(){
    FAST_IO;
    int TC = 1; 
	// cin >> TC;
    while(TC--) Solve();
    return 0;
}