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

const int N = 555;

int n, k, m, a[N][N], b[N][N];
vector <int > v1[N * 2], v2[N * 2];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			v1[i + j].push_back(a[i][j]);
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> b[i][j];
			v2[i + j].push_back(b[i][j]);
		}

	for(int i = 2; i <= m + n; i++) {
		sort(v1[i].begin(), v1[i].end());
		sort(v2[i].begin(), v2[i].end());
		if(v1[i] != v2[i])
			return cout << "NO\n", 0;
	}

	cout <<"YES\n";
	return 0;
}