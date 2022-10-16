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
long long n, ans, a[N], nr, aib[N], sus, jos;

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

long long lsb(long long k) {return k & (-k);}

void upd(long long pos, long long val) {
	for(;pos < N; pos += lsb(pos))
		aib[pos] += val;
}

long long que(long long pos) {
	long long ans = 0;
	for(;pos; pos -= lsb(pos))
		ans += aib[pos];
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		upd(i, 1);
		cin >> a[i];
		if(a[i] == -1) nr++;
		else upd(a[i], -1);
	}
	long long tot = nr;

	sus = nr * (nr - 1);
	jos = 4;

	// ans = 

	dbg(sus, jos);
	// nr = 0;
	for(long long i = 1; i <= n; i++) {
		if(a[i] != -1 && tot) {
			long long smaller = que(a[i]);
			long long up = (smaller * nr) % MOD;
			long long down = tot;
			sus = (sus * down + up * jos) % MOD;
			jos = (jos * down) % MOD;
			ans %= MOD;
			// nr - poz de -1 din dreapta
			// dbg(i, a[i], smaller, nr, tot);
			// dbg(up, down);

			long long greater = que(n) - que(a[i]);
			up = (greater * (tot - nr)) % MOD;
			 down = tot;
			sus = (sus * down + up * jos) % MOD;
			jos = (jos * down) % MOD;
			ans %= MOD;

		} else {
			nr--;
		}
	}

	memset(aib, 0, sizeof aib);

	dbg(sus, jos);

	for(long long i = 1; i <= n; i++) 
		if(a[i] != -1) {
			sus += ((que(n) - que(a[i])) * jos) % MOD;
			sus %= MOD;
			upd(a[i], 1);
		}
	// dbg(ans);
	dbg(sus, jos);
	sus %= MOD;
	cout << ((sus * invMod(jos)) % MOD + MOD) % MOD << '\n';
}