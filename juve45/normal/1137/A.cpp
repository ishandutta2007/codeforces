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

const int N = 1010;

int n, k, m, a[N][N], ans[N][N];
vector <int> lin[N], col[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			lin[i].push_back(a[i][j]);
			col[j].push_back(a[i][j]);
		}

	for(int i = 1; i <= n; i++) {
		sort(lin[i].begin(), lin[i].end());
		lin[i].resize( std::distance(lin[i].begin(), unique(lin[i].begin(), lin[i].end())) );
	}

	for(int i = 1; i <= m; i++) {
		sort(col[i].begin(), col[i].end());
		col[i].resize( std::distance(col[i].begin(), unique(col[i].begin(), col[i].end())) );
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			int v1 = lower_bound(lin[i].begin(), lin[i].end(), a[i][j]) - lin[i].begin() + 1;
			int v2 = lower_bound(col[j].begin(), col[j].end(), a[i][j]) - col[j].begin() + 1;
			ans[i][j] = max(v1, v2) + max(lin[i].size() - v1, col[j].size() - v2);
		}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}

}