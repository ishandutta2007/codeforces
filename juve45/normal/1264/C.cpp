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

const long long N = 200100;
const long long MOD = 998244353;
long long n, q, prod[N], p[N], sp[N], use[N], x;

long long powMod(long long base, long long exp) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}

long long invMod(long long a) {
	return powMod(a % MOD, MOD - 2);
}

long long ev(long long i, long long j) {

	long long pr = prod[j - 1] * invMod(prod[i - 1]) % MOD;
	long long scad = (i >= 1 ? sp[i - 2] : 0);
	long long adun = (j >= 1 ? sp[j - 2] : 0);
	long long up = (adun - scad) * invMod(prod[i - 1]) % MOD;
	return (up * invMod(pr)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	long long inv100 = invMod(100);
	for(long long i = 1; i <= n; i++) {
		cin >> p[i];
		p[i] *= inv100;
		p[i] %= MOD;
	}

	prod[0] = 1;
	sp[0] = 1;
	for(long long i = 1; i <= n; i++) {
		prod[i] = (prod[i - 1] * p[i]) % MOD;
		sp[i] = (sp[i - 1] + prod[i]) % MOD;
	}

	set < pair< pair<long long, long long>, long long> > s; 

	long long ans = ev(1, n + 1);
	s.insert({{1, n + 1}, ev(1, n + 1)});


	for(long long i = 1; i <= q; i++) {
		cin >> x;
		if(use[x] == 1) {
			auto it = s.lower_bound({{x, n + 1000}, 0});
			it--;
			auto it2 = it;
			it2--;
			ans -= it->nd;
			ans -= it2->nd;

			long long l = it2->st.st;
			long long r = it->st.nd;
			s.erase(it);
			s.erase(s.lower_bound({{l, -1}, 0}));
			ans += ev(l, r);
			s.insert({{l, r}, ev(l, r)});
		} else {

			auto it = s.lower_bound({{x, n + 1000}, 0});
			it--;	
			long long l = it->st.st;
			long long m = x;
			long long r = it->st.nd;
			ans -= it->nd;
			s.erase(it);

			ans += ev(l, m);
			ans += ev(m, r);
			s.insert({{l, m}, ev(l, m)});
			s.insert({{m, r}, ev(m, r)});

		}

		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		use[x] ^= 1;
		cout << ans << '\n';
	}

	// dbg_v(sp, n + 1);
	// dbg_v(p, n + 1);
	
	// dbg(ev(1, 2));
	// dbg(ev(2, 3));
	// dbg(ev(1, 3));
	// dbg(ev(1, 2));
	// dbg(ev(2, 6));

	// dbg((sp[n - 1] * invMod(prod[n])) % MOD);



}