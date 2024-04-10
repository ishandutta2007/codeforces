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

const int N = 200100;
int n, a[N], f[N], ans, q, ff[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		f[a[i]]++;
		ff[a[i]]++;
	}

	set <int> curr, past_curr;
	for(int i = 1; i <= n; i++) {
		curr.insert(a[i]);
		past_curr.insert(a[i]);

		f[a[i]]--;
		if(f[a[i]] == 0) 
			curr.erase(a[i]);

		// dbg(curr);
		// dbg(past_curr);
		if(curr.empty()) {
			int mx = 0, tot = 0;
			for(auto i : past_curr) {
				// dbg(i, ff	[i]);
				tot += ff[i];
				mx = max(ff[i], mx);
			}
			// dbg(tot, mx);
			ans += tot - mx;
			past_curr.clear();
		}
	}
	cout << ans << '\n';
}