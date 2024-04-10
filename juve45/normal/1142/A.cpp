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
long long n, k, a, b;

long long dist(long long a, long long b) {
	if(b < 0) return n * k + b - a;
	if(a < b) return b - a;
	return n * k + b - a;
}

long long cnt(long long d) {
	// dbg(d);
	return n * k / __gcd(d, n * k);
}

void upd(pair<long long, long long> &p, long long nr) {
	if(p.st > nr) p.st = nr;
	if(p.nd < nr) p.nd = nr;
}

pair<long long, long long> get(long long st) {

	pair <long long, long long> ret = {1e12, 0};
	for(long long i = 0; i < n; i++) {
		upd(ret, cnt(dist(st, i * k + 1 - b)));
		upd(ret, cnt(dist(st, i * k + 1 + b)));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	cin >> a >> b;
	long long start1 = a + 1;
	long long start2 = k + 1 - a;

	auto p1 = get(start1);
	auto p2 = get(start2);
	cout << min(p1.st, p2.st) << ' ' << max(p1.nd, p2.nd) << '\n';
}