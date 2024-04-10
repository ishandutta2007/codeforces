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

// const long long N = ;
const long long MOD = 1e9 + 7;
long long n, x;
vector <long long> p;

long long powMod(long long base, long long exp) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> x >> n;

	for(long long i = 2; i * i <= x; i++)
		if(x % i == 0) {
			p.push_back(i);
			while(x % i == 0) x /= i;
		}
	if(x != 1) p.push_back(x);
	// dbg(p);

	long long ans = 1;
	for(auto i : p) {
		long long pp = i;
		long long cnt = 0;
		while(true) {
			// dbg(pp);
			cnt += n / pp;
			if(pp <= n / i)
				pp *= i;
			else break;
		}
		// dbg(i, cnt);
		ans *= powMod(i, cnt);
		ans %= MOD;
	}
	cout << ans << '\n';
}