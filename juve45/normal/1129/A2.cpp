#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 5005;
// const int MOD = 666013;



int n, k, m, a[4 * N], b[4 * N];

int dist(int a, int b) {
	if(a <= b) return b - a;
	return n - a + b;
}
vector <pair<int, int> > v[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;


	for(int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
		v[a[i]].push_back({dist(a[i], b[i]), b[i]});
	}

	for(int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());

	for(int i = 1; i <= n; i++) {
		int ans = 0;
		// dbg(i);
		for(int j = 1; j <= n; j++) {
			if(v[j].size() == 0) continue;
			int last = v[j][0].nd;
			// dbg(j);
			// dbg(dist(i, j));
			// dbg(dist(j, last));
			ans = max(dist(i, j) + ((int)v[j].size() - 1) * n + dist(j, last), ans);
		}
		cout << ans << ' ';
	}
}