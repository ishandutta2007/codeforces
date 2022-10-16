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

#define dbg(...) //cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 1000100;
const long long MOD = 1e9 + 7;
long long n, a[N], l[N], r[N], k;

long long kk(long long x) {return x / k;}
long long nxt(long long x) { return (x + k - 1) / k * k;}
long long prv(long long x) { return x / k * k;}

long long cnt_lg(long long pos) {
	dbg(pos);
	if(pos <= 0) return 0;
	// pos++;
	// pos--;
	long long full = pos / (k - 1);
	long long extra = pos % (k - 1);
	// dbg(full, extra);
	return (k - 1) * full * (full - 1) / 2 + extra * full;
}

long long cnt(long long l, long long r) {
	// if(l > r) return 0;
	return cnt_lg(r - l + 1) % MOD;
}

long long cnt_mid(long long l, long long r, long long mid) {
	return (cnt(l, r) - cnt(l, mid - 1) - cnt(mid + 1, r) + 2 * MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	// k--;
	for(long long i = 1; i <= n; i++)
		cin >> a[i];

	a[0] = 1.5e18;
	a[n + 1] = 1.4e18;
	
	stack < long long > s;
	s.push(0);

	for(long long i = 1; i <= n + 1; i++) {
		// dbg(i);
		while(a[s.top()] <= a[i]) {
			r[s.top()] = i;
			s.pop();
		}
		l[i] = s.top();
		s.push(i);
	}
	// dbg_v(l, n + 1);
	// dbg_v(r, n + 1);

	// k = 2;
	// dbg(cnt_lg(2));
	// dbg(cnt_lg(3));
	// dbg(cnt_lg(4));

	// dbg(cnt_mid(1, 2, 1));
	// dbg(cnt_mid(1, 3, 3));

	long long ans = 0;
	for(long long i = 1; i <= n; i++) {
		ans += cnt_mid(l[i] + 1, r[i] - 1, i) * a[i];
		ans %= MOD;
	}
	cout << ans << '\n';

}	

/*

0 1 2 3 4 5 6
0-2 1-3

1 2 3 4 5 6 7
1-3 2-4 3-5 4-6 5-7
1-5 2-6 3-7
1-7


*/