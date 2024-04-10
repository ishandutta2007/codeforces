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
int n, c, m, x, q;

bool ok(int nrt) {
	if(c < nrt || m < nrt) return 0;
	c -= nrt;
	m -= nrt;
	// dbg(res, c, m, x);
	int rem = x + c + m;
	c += nrt;
	m += nrt;
	if(rem >= nrt) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> c >> m >> x;
		// dbg(ok(3));

		int l = 0, r = 1e8;
		while(l != r) {
			// dbg(l, r);
			int mid = (l + r + 1) / 2;
			if(ok(mid)) l = mid;
			else r = mid - 1;
		}
		cout << l << '\n';

		// cout << min(res, rem) << '\n';
	}
}