#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long MOD = 1e9 + 7;
const long long N = 1e5 + 6;
long long n, k, fact[N], invf[N], p25[N], p26[N], inv26[N], op;

map <long long, vector <int> > calc; 

long long powMod(long long base, long long exp) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}

long long invMod(long long a) {
	return powMod(a, MOD - 2);
}

long long comb(long long n, long long k) {
	if(k == 0 || n == k) return 1;
	return (fact[n] * invf[k] % MOD )* invf[n - k] % MOD; //invMod((1LL * fact[k] * fact[n - k]) % MOD)) % MOD;
}

long long perm_rep(vector <long long> v) {
	long long sum = 0;
	for(auto i : v) 
		sum += i;
	long long ans = fact[sum];
	for(auto i : v) 
		ans = (1LL * ans * invMod(fact[i])) % MOD;
	// dbg(v);
	// dbg(ans);
	return ans;
}

void pre() {
	fact[0] = 1;
	for(long long i = 1; i < N; i++) {
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
		invf[i] = invMod(fact[i]);
	}
	p25[0] = p26[0] = 1;
	for(int i = 1; i < N; i++) {
		p25[i] = p25[i - 1] * 25 % MOD;
		p26[i] = p26[i - 1] * 26 % MOD;
		inv26[i] = invMod(p26[i]);
	}
}

long long dp(long long i, long long j) {
	if(i < j) return 0;
	return (p25[i - j] * comb(i - 1, j - 1)) % MOD;
}

vector <int> prec(long long sz) {
	vector <int> res;
	// long long N = 5;
	long long sum = 0;
	for(long long i = 0; i < N; i++) {
		long long mul = p26[N - i - 1];
		// if(i < 10) dbg(mul);
		// dbg(mul);
		sum += (mul * dp(i, sz)) % MOD;
		sum %= MOD;
		res.push_back(sum);
	}
	return res;
}

vector <long long> vrt;

long long get(long long sz, long long n) {
	// assert(calc.count(sz));
	return 1LL * calc[sz][n] * inv26[N - n - 1] % MOD;
}

string s;
long long m, x;

int main() {
	ios_base::sync_with_stdio(false);

	pre();

	cin >> n;
	cin >> s;
	long long sz = s.size();

	if(calc.count(sz) == 0)
		calc[sz] = prec(sz);


	for(long long i = 1; i <= n; i++) {
		cin >> op;
		if(op == 2) {
			cin >> x;
			cout << get(sz, x) << '\n';
		} else {
			cin >> s;
			sz = s.size();
			if(calc.count(sz) == 0)
				calc[sz] = prec(sz);
		}
	}
}