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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
int n, ans, a[66], k, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> m;
	int s = 0;
	for(int i = 1; i <= k; i++) {
		cin >> a[i];
		s += a[i];
	}
	sort(a + 1, a + k + 1);

	for(int i = 0; i <= n; i++) {

		int cost = s * i;
		if(cost > m) break;
		int nr = (k + 1) * i;
		dbg(i, cost);
		for(int j = 1; j <= k; j++) {
			int rem = m - cost;
			dbg(rem);
			int cant = min(rem / a[j], n - i);
			dbg(cant);
			nr += cant;
			cost += a[j] * cant;
		} 
		dbg(i, nr, cost);
		ans = max(ans, nr);
	}
	cout << ans << '\n';
}