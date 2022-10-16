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
long long n, p, w, d;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> p >> w >> d;

	long long g = __gcd(w, d);
	if(p % g != 0) return cout << "-1\n", 0; 
	w /= g;
	d /= g;
	p /= g;

	for(long long i = 0; i <= w; i++) {
		long long pp = p - i * d;
		if(pp % w == 0 && pp >= 0) {
			long long nr = pp / w;
			if(nr + i <= n) return cout << nr << ' ' << i << ' ' << n - i - nr << '\n', 0;
		}
	}

	for(long long i = 0; i <= d; i++) {
		long long pp = p - i * w;
		if(pp % d == 0 && pp >= 0) {
			long long nr = pp / d;
			if(nr + i <= n) return cout << i << ' ' << nr << ' ' << n - i - nr << '\n', 0;
		}
	}
	cout << "-1\n";
	return 0;
}