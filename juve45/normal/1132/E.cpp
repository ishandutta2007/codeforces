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
const long long NR = 3 * 5 * 7 * 8;
long long n, sum, dp[8 * NR + 10], f[11], ans;

int main() {
	ios_base::sync_with_stdio(false);	
	dbg(NR);
	cin >> n;

	for(long long i = 1; i <= 8; i++) {
		cin >> f[i];
	}
	
	for(long long i = 8; i > 0; i--) {
		long long cnt = min((f[i] - NR / i), (n - sum - NR) / NR * NR / i);
		cnt = max(cnt, 0LL);
		f[i] -= cnt;
		dbg(i, cnt, f[i]);
		sum += cnt * i;//(NR / i);
	}

	// ajung la sum;
	dbg(sum);
	dp[0] = 1;

	for(long long i = 1; i <= 8; i++) {
		for(long long j = 1; j <= min(f[i], 8 * (NR / i)); j++) {
			for(long long k = NR * 8; k > 0; k--)
				if(k - i >= 0)
					dp[k] |= dp[k - i];
		}
	}
	dbg(sum);
	dbg(f[3]);
	dbg(f[8]);
	for(long long i = 0; i <= 8 * NR; i++) {
		if(sum + i > n) break;
		if(dp[i]) ans = sum + i;
	}
	cout << ans << '\n';
}