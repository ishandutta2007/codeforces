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

const long long N = 1005;
long long n;
long long x[N], y[N];
set <pair<pair<long long, long long>, pair<long long, long long> > > s;
map <pair<long long, long long> ,  set <pair<long long, long long> > > m;

pair<pair <long long, long long>, pair<long long, long long> > line(long long i, long long j) {
	long long dx = x[i] - x[j];
	long long dy = y[i] - y[j];
	// dbg(dx, dy);
	if(dy < 0) dx  *= -1, dy *= -1;
	long long g = __gcd(dx, dy);
	dx /= g;
	dy /= g;
	pair <long long, long long> m = {dx, dy};
	if(dx == 0) dy = 1;

	long long nx = y[i] * dx - dy * x[i];
	long long ny = dy;
	if(ny == 0) {nx = y[i], ny = 1;}
	g = __gcd(nx, ny);
	// dbg(nx, ny, g);
	if(nx == 0) ny = 1;
	if(g) {
		nx /= g;
		ny /= g;
	}
	if(ny < 0 ) ny *= -1, nx *= -1;
	// dbg_ok;
	return {m, {nx, ny}};
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}

	for(long long i = 1; i <= n; i++)
		for(long long j = i + 1; j <= n; j++) {
			auto p = line(i, j);
			dbg(p);
			s.insert(p); // toate liniile
			if(m.count(p.st) == 0)
				m[p.st] = set <pair<long long, long long> > ();
			m[p.st].insert(p.nd); //pun la fiecare panta n-ul
		}
	
	dbg(s);

	long long tot = s.size();
	dbg(tot);
	tot = tot * (tot - 1) / 2;
	dbg(tot);
	for(auto &i : m) {
		dbg(i.nd);
		tot -= i.nd.size() * (i.nd.size() - 1) / 2;
	}
	cout << tot;

}