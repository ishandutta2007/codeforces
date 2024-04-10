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
long long n, p[N], m, t;

long long cnt(long long val) {
	vector <long long> v;

	long long sum = 0;

	for(long long i = 1; i <= n; i++)  {
		if(p[i] <= val)
			v.push_back(p[i]);
	}

	long long last = 0;

	for(long long i = 0; i < v.size(); i++) {
		if(i % m == 0) {
			sum += last;
			last = 0;
			if(sum > t) return i;
		}
		sum += v[i];
		last += v[i];
		if(sum > t) return i;
	}
	return v.size();
}

bool whole(long long val) {
	long long req =0;
	for(long long i = 1; i <= n; i++) 
		if(p[i] <= val) req++;
	return req == cnt(val);
}

long long solve() {
	cin >> n >> m >> t;
	
	set <long long> s;

	for(long long i = 1; i <= n; i++) {
		cin >> p[i];
		s.insert(p[i]);
	}

	long long l = 1, r = t;
	while(l  != r) {
		long long mid = (l + r + 1) / 2;
		if(whole(mid))
			l = mid;
		else 
			r = mid - 1;
	}

	long long ans1 = cnt(l);
	long long ans2 = -1;

	if(s.upper_bound(l) != s.end())
		ans2 = cnt(*s.upper_bound(l));

	// dbg(l, *s.upper_bound(l));

	if(ans1 >= ans2) {
		cout << ans1 << ' ' << l << '\n';
	} else 
	cout << ans2 << ' ' << *s.upper_bound(l) << '\n';

	// return max(ans1, ans2);
}

int main() {
	ios_base::sync_with_stdio(false);
	long long tt; cin >> tt;
	while(tt--) solve();

}