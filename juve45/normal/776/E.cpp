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
long long n, k;

long long phi(long long n, long long k) {

	if(k == 0) return n;
	if(n == 1) return 1;

	long long ret = 1;
	for(long long i = 2; i * i <= n; i++) {
		if(n %  i == 0) {
			ret *= (i - 1);
			n /= i;
			while(n % i == 0) 
				n /= i, ret *= i;
		}
	}
	if(n > 1) ret *= (n - 1);
	return phi(ret, k - 1);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	cout << phi(n, (k + 1) / 2) % MOD;
}