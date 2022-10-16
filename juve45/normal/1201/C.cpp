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
long long n, a[N], k;

bool ok(long long nr) {
	long long ans = 0;
	for(long long i = n / 2 + 1; i <= n; i++)
		ans += max((nr - a[i]), 0LL);
	// dbg(nr, ans);
	return ans <= k;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(long long i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1); 

	long long l = a[n / 2 + 1], r = 2e9 + 1000;
	while(l != r) {
		long long mid = (l + r + 1) / 2;
		if(ok(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
}