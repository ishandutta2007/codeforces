#include <bits/stdc++.h>
#define st first
#define nd second
 
using namespace std;
 
void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
 
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
 
const long long N = 255;
const long long MOD = 1e9 + 9;
const long long B = 257;
long long n, m, hsh[N][N], pb[N], ans, x, a;
string s[N];
 
long long Manacher(vector <long long> s, bool parity) {
  long long n = s.size(), z = parity, l = 0, r = 0;
  vector<long long> ret(n - !z, 0);
  
  for (long long i = 0; i < n - !z; ++i) {
    if (i + !z < r) ret[i] = min(r - i, ret[l + r - i - !z]);
    long long L = i - ret[i] + !z, R = i + ret[i];
    while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1])
      ++ret[i], --L, ++R;
    if (R > r) l = L, r = R;
  }
  long long ans = 0;
  for(auto i : ret) ans += i + parity;
  return ans;
  // return ret;
}
 
long long xorr[N][N];
 
int main() {
	ios_base::sync_with_stdio(false);
 
	// dbg(Manacher({1, 4, 6}, 1));
 
	cin >> n >> m;
	for(long long i = 0; i < n; i++)
		cin >> s[i];
 
	pb[0] = 1;
	for(long long i = 1; i <= 26; i++)
		pb[i] = (pb[i - 1] * B) % MOD;
 
	for(long long i = 0; i < n; i++) {
		hsh[i][0] = pb[s[i][0] - 'a'];
		xorr[i][0] = (1 << (s[i][0] - 'a'));
		for(long long j = 1; j < m; j++) {
			hsh[i][j] = (hsh[i][j - 1] + pb[s[i][j] - 'a']) % MOD;
			xorr[i][j] = xorr[i][j - 1] ^ (1 << (s[i][j] - 'a'));
		}
	}
 
	// dbg_v(hsh[0], 4);
 
	for(long long i = 0; i < m; i++)
		for(long long j = i; j < m; j++) {
			vector <long long> v;
			for(long long k = 0; k < n; k++) {
				if(i) {
					a = (MOD + hsh[k][j] - hsh[k][i - 1]) % MOD; 
					x = (xorr[k][j] ^ xorr[k][i - 1]);
				}
				else {
					a = hsh[k][j];
					x = xorr[k][j];
				}
				if(__builtin_popcountll(x) <= 1) {
					v.push_back(a);
				} else {
					// dbg(i, j, k, v);
					if(v.size())
						ans += Manacher(v, 1) + Manacher(v, 0);
					v.clear();
				}
			}
			if(v.size())
				ans += Manacher(v, 1) + Manacher(v, 0);
			// dbg(i, j, v);
 
		}
	cout << ans << '\n';
}