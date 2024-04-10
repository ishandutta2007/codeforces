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

const long long N = 100100;
long long n, k, a[N], m;

int main() {
	ios_base::sync_with_stdio(false);

	cin>> n >> k >> m;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1, greater<long long> ());

	long long sum = 0;
	pair<long long, long long> ans = {0, 1};
	for(long long i = 1; i <= n; i++) {
		sum += a[i];
		if(m < n - i) continue;
		if(ans.st * i < ans.nd * (sum + min(m - n + i, i * k))) {
			ans = {sum + min(m - n + i, i * k), i};
		}
		// dbg(i, 1. *ans.st / ans.nd);
	}
	cout << fixed << setprecision(8) << (long double) ans.st / ans.nd << '\n';
}