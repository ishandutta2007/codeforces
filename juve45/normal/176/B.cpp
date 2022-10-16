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
// long long n;

const long long MOD = 1e9 + 7;
const long long N = 1e5 + 6;
long long n, k, nr;
string s, t;

long long powMod(long long base, long long exp) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> s >> t >> k;
	s = s + s;

	for(long long i = 0; i < t.size(); i++)
		if(s.substr(i, t.size()) == t) nr++;

	long long same = (s.substr(0, t.size()) == t);
	long long diff = 1 - same;
	n = t.size();
	for(long long kk = 1; kk <= k; kk++) {
		// dbg(same, diff);
		long long sam = same;
		same = (diff * nr + same * (nr - 1)) % MOD;
		diff = (diff * (n - nr - 1) + sam * (n - nr)) % MOD;
	}
	cout << same << '\n';
	// cout << powMod(t.size() - 1, k - 1) * nr % MOD;
}