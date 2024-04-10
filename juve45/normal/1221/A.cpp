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
long long n, a, q;

string solve() {
	cin >> n;
	multiset <long long> ms;

	for(long long i = 1; i <= n; i++) {
		cin >> a;
		ms.insert(a);
	}

	for(long long i = 1; i < n; i++) {
		long long x = *ms.begin();
		if(x == 2048) return "YES\n";
		ms.erase(ms.begin());
		assert(ms.size() == n - i);
		long long y = *ms.begin();
		if(x != y) continue;
		ms.erase(ms.begin());
		ms.insert(2LL * x);
	}

	long long x = *ms.begin();
	// dbg(x);
	if(x == 2048) return "YES\n";
	return "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> q;
	for(long long i = 1; i <=q ; i++) cout << solve();

	return 0;
}