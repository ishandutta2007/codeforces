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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
const int MOD = 1e9 + 9;
int n, m, k;

int p2(int exp) {
	if(exp < 20) return (1 << exp);
	int tmp = p2(exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (2LL * tmp) % MOD;
	return tmp;
}

int res(int cnt) {
	dbg(cnt);
	int val = p2(cnt + 1);
	return (1LL * k*(val - 2)) % MOD;
}

/// 0 2^1 - 2 0
/// 1 2^2 - 2 2
/// 2 2^3 - 2 6
/// 3 14

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	int cnt = min(n - m, (m + k - 2) / (k - 1));
	dbg(cnt);
	m -= cnt * (k - 1);
	dbg(m);
	int ans = (1LL * cnt * (k - 1)) % MOD + res(m / k) + m % k;
	
	cout << (ans % MOD + MOD) % MOD << '\n';
}