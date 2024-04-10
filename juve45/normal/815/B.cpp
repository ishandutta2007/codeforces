#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 200100;
const int MOD = 1e9 + 7;

int n, k, m, p[N], a[N];

int powMod(int base, int exp) {
	if(exp == 0) return 1;
	if(exp == 1) return base;

	int tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2 == 0) return tmp;
	return (1LL * tmp * base) % MOD;
}

int comb(int n, int kk) {
	int ans = p[n];
	ans = (1LL * ans * powMod(p[kk], MOD - 2)) % MOD;
	ans = (1LL * ans * powMod(p[n - kk], MOD - 2)) % MOD;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	
	if(n == 1) {
		cout << a[1] << '\n';
		return 0;
	}

	long long sgn = 1;
	if(n % 2 == 1) {
		for(int i = 1; i < n; i++) {
			a[i] += sgn * a[i + 1], sgn *= -1;
			a[i] %= MOD;
		}
		n--;
	}

	int nr = (n - 2) / 2;
	sgn = 1;
	if(n % 4 == 0) sgn = -1;

	p[0] = 1;
	for(int i = 1; i <= nr; i++)
		p[i] = (1LL * p[i - 1] * i) % MOD;

	long long ans = 0;

	for(int i = 1; i <= n; i += 2) 
		ans += 1LL * a[i] * comb(nr, i / 2), ans %= MOD;
	

	for(int i = 2; i <= n; i += 2) 
		ans += sgn * a[i] * comb(nr, i / 2 - 1), ans %= MOD;


	ans += MOD;
	ans %= MOD;
	cout << ans << '\n';
}