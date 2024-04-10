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
long long n, k, l1, l2, r2, r1, t;

long long solve() {
	cin >> n >> k;
	cin >> l1 >> r1;
	cin >> l2 >> r2;
	
	long long ans = 0, nr1, nr0;

	if(r1 > r2) swap(l1, l2), swap(r1, r2);

	if(l2 > r1) {
		nr0 = l2 - r1;
		nr1 = r2 - l1;
	} else if(l2 > l1) {
		nr0 = 0;
		nr1 = r2 - r1 + l2 - l1;
		k -= n * (r1 - l2);
	} else {
		nr0 = 0;
		nr1 = r2 - l2 - (r1 - l1);
		k -= n * (r1 - l1);
	}

	k = max(k, 0LL);
	// dbg(nr0, nr1, k);

	for(long long i = 0; i < n && k; i++) {
		long long req = min(k, nr1);
		ans += min(nr0, (i > 0 ? req : nr0));
		ans += req;
		k -= req;
		// dbg(ans, k);
	}

	ans += 2 * k;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> t;
	while(t--) cout << solve() << '\n';

}