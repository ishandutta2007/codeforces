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

const long long N = 2019;
long long n, dp[N], a[N], k;

inline long long cost(long long from, long long to, long long step) {
	return (abs(from - to) + step - 1) / step;
}

bool ok(long long mid) {

	dp[0] = 0;
	dp[n + 1] = -2e9;
	for(long long i = 1; i <= n; i++)
		dp[i] = -2e9;

	for(long long i = 0; i <= n; i++)
		for(long long j = i + 1; j <= n + 1; j++) 
			if(i == 0 || j == n + 1 || cost(a[i], a[j], j - i) <= mid)
				dp[j] = max(dp[j], dp[i] + 1);

	return (dp[n + 1] >= n - k + 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(long long i = 1; i <= n; i++)
		cin >> a[i];

	long long l = 0, r = 4e9 + 1;

	while(l != r) {
		long long mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
}