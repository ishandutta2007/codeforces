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
long long n, k, a[N], s[N];
map <long long, long long> m;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(long long i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + n + 1);
	// dbg_v(a, n + 1);

	for(long long i = 1; i <= n; i++) 
		s[i] = s[i - 1] + a[i];

	long long ans = a[n] - a[1];

	for(long long i = 1; i < n; i++) {
		long long lk = a[i] * i - s[i];
		// dbg(i, lk, k);
		if(lk > k) continue;
		long long l = i + 1, r = n;
		while(l != r) {
			long long mid = (l + r) / 2;
			if(s[n] - s[mid - 1] - a[mid] * (n - mid + 1) + lk <= k) r = mid;
			else l = mid + 1;
		}


		long long pos = l;
		k -= s[n] - s[pos - 1] - a[pos] * (n - pos + 1) + lk;
		long long nr = n - pos + 1;
		long long w = k / nr;
		long long maxx = max(a[pos - 1], a[pos] - w);
		// dbg(i, pos, a[i], maxx);
		ans = min(ans, maxx - a[i]);

		k += s[n] - s[pos - 1] - a[pos] * (n - pos + 1) + lk;
	}
	// dbg(ans);

	for(long long i = 2; i <= n; i++) {
		long long rk = s[n] - s[i - 1] - a[i] * (n - i + 1);

		if(rk > k) continue;

		long long l = 1, r = i - 1;
		while(l != r) {
			long long mid = (l + r + 1) / 2;
			if(rk + a[mid] * mid - s[mid] <= k) l = mid;
			else r = mid - 1;
		}

		long long pos = l;
		k -= a[pos] * pos - s[pos] + rk;
		long long nr = pos;
		long long w = k / nr;
		long long minn = min(a[pos + 1], a[pos] + w);
		// dbg(i, pos, a[i], minn, w, nr);
		ans = min(ans, a[i] - minn);

		k += a[pos] * pos - s[pos] + rk;
	}
	cout << ans << '\n';

}