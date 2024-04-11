#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt")
#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, fib[maxn];
void FWHT(vector<int> &a) {
	int n = a.size();
	for(int b = 1; b < n; b<<=1) {
		for(int i = 0; i < n; i++) if(i < (i^b)) {
			int j = i^b;
			int x = a[i] + a[j];
			int y = a[i] - a[j];
			if(y < 0) y += mod;
			if(x >= mod) x -= mod;
			a[i] = x, a[j] = y;
		}
	}
}
vector<int> mul(vector<int> a, vector<int> b) {
	a.resize(maxn), b.resize(maxn);
	FWHT(a), FWHT(b);
	for(int i = 0; i < maxn; i++) a[i] = a[i]*1ll*b[i]%mod;
	FWHT(a);
	int p = 1;
	for(int x = 1; x < maxn; x<<=1) p = p * 1ll * ((mod+1)/2) % mod;
	for(auto &i : a) i = i *1ll* p %mod;
	return a;
}
template<int SUP, bool inv>
void transform(vector<int> &a) {	
	for(int j = 1; j < a.size(); j<<=1)
		for(int i = 0; i < a.size(); i++)
			if((i&j) == (!SUP*j))
				a[i] = (a[i] + (inv?mod-a[i^j]:a[i^j]))%mod;
}
template<int AND>//0 for OR, 1 for AND
vector<int> conv(vector<int> a, vector<int> b) {
	transform<AND, 0>(a);
	transform<AND, 0>(b);
	for(int i = 0; i < maxn; i++) a[i] = a[i]*1ll*b[i]%mod;
	transform<AND, 1>(a);
	return a;
}
vector<int> conv_disjoint(vector<int> a, vector<int> b) {
	vector<vector<int>> f(18, vector<int>(a.size()));
	auto g = f;
	auto q = f;
	for(int i = 0; i < a.size(); i++) f[__builtin_popcount(i)][i] = a[i];
	for(int i = 0; i < b.size(); i++) q[__builtin_popcount(i)][i] = b[i];
	for(int i = 0; i < 18; i++) transform<0, 0>(f[i]);
	for(int i = 0; i < 18; i++) transform<0, 0>(q[i]);
	for(int i = 0; i < a.size(); i++) {
		for(int x = 0; x < 18; x++)
			for(int y = 0; x+y < 18; y++) {
				g[x+y][i] = (g[x+y][i] + f[x][i]*1ll*q[y][i])%mod;
			}
	}
	for(int i = 0; i < 18; i++) transform<0, 1>(g[i]);
	for(int i = 0; i < a.size(); i++) a[i] = g[__builtin_popcount(i)][i];
	return a;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	fib[1] = 1;
	for(int i = 2; i < maxn; i++) fib[i] = (fib[i-1] + fib[i-2])%mod;
	vector<int> f(maxn);
	for(int t,  i = 0; i < n; i++) cin >> t, f[t]++;
	auto fw = mul(f, f);
	auto di = conv_disjoint(f, f);
	for(int i = 0; i < maxn; i++) {
		f[i] = f[i]*1ll*fib[i]%mod;
		fw[i] = fw[i]*1ll*fib[i]%mod;
		di[i] = di[i]*1ll*fib[i]%mod;
	}
	f = conv<1>(f, fw);
	f = conv<1>(f, di);
	int ans = 0;
	for(int i = 1; i < maxn; i<<=1) ans = (ans + f[i])%mod;
	cout << ans << endl;
}