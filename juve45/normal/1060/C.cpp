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
long long n, m, mina[N], minb[N], x, ans;
long long a[N], b[N];

int main() {
	ios_base::sync_with_stdio(false);
	memset(mina, 0x3f, sizeof(mina));
	memset(minb, 0x3f, sizeof(minb));
	cin >> n >> m;
	for(long long i = 1; i <= n; i++) cin >> a[i];	
	for(long long i = 1; i <= m; i++) cin >> b[i];	

	for(long long i = 1; i <= n; i++) {
		long long sum = 0;
		for(long long j = i; j <= n; j++) {
			sum += a[j];
			mina[j - i + 1] = min(mina[j - i + 1], sum);
		}
	}
	for(long long i = 1; i <= m; i++) {
		long long sum = 0;
		for(long long j = i; j <= m; j++) {
			sum += b[j];
			minb[j - i + 1] = min(minb[j - i + 1], sum);
		}
	}

	cin >> x;
	for(long long i = 1; i <= n; i++) {
		long long sch = x / mina[i];
		// dbg(i, mina[i], sch);
		long long pos = upper_bound(minb + 1, minb + m + 1, sch) - minb;
		pos--;
		// dbg(pos);
		ans = max(ans, i * pos);
	}
	cout << ans << '\n';
}