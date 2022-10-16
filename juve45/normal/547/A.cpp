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

#define y1 y2143245

const long long M = 1e6 + 100;
long long n, use[M], m, h1, a1, h2, a2, x1, x2, y1, y2, f1 = -1, f2 = -1, ok1, ok2;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> m;
	cin >> h1 >> a1 >> x1 >> y1;
	cin >> h2 >> a2 >> x2 >> y2;


	long long x = h1, pas = 1;
	while(!use[x]) {
		if(x == a1) f1 = pas;
		use[x] = pas++;
		x = (x * x1 + y1) % m;
	}
	long long p1 = pas - use[x];
	if(f1 >= use[x]) ok1 = 1;

	memset(use, 0, sizeof use);
	x = h2, pas = 1;
	while(!use[x]) {
		if(x == a2) f2 = pas;
		use[x] = pas++;
		x = (x * x2 + y2) % m;
	}
	long long p2 = pas - use[x];
	if(f2 >= use[x]) ok2 = 1;

	dbg(ok1, ok2);

	if(ok1 && ok2) {
		dbg_ok;
		if(f1 < f2) {
			swap(f1, f2);
			swap(p1, p2);
		}
		// dbg(f1, f2, p1, p2);
		long long tmp = f1, tmp2 = f1;
		f2 %= p2;
		dbg(f2, tmp);
		tmp %= p2;
		for(long long i = 0; i <= p2; i++) {
			// dbg(tmp);
			if(tmp == f2) return cout << i * p1 + f1 - 1 << '\n', 0;
			tmp += p1;
			tmp %= p2;
		}

	} else {
		for(long long i = 1; i <= m; i++) {
			// dbg(h1, h2, a1, a2);
			if(h1 == a1 && h2 == a2) return cout << i - 1 << '\n', 0;
			h1 = (h1 * x1 + y1) % m;
			h2 = (h2 * x2 + y2) % m;
		}
	}

	cout << "-1\n";
	dbg(p1, p2);

}