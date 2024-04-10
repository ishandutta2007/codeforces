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
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd; }

const int N = 110;
const int MOD = 666013;
int n, k, m, a[N][N];

vector <pair<string, int> > ans;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];

	int minn = 1e9;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			minn = min(minn, a[i][j]);

	if(n > m)
		for(int k = 1; k <= minn; k++)
			for(int i = 1; i <= m; i++)
				ans.push_back({"col", i});
	else 
		for(int k = 1; k <= minn; k++)
			for(int i = 1; i <= n; i++)
				ans.push_back({"row", i});

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] -= minn;

	for(int i = 1; i <= n; i++) {
		int minn = a[i][1];
		for(int j = 2; j <= m; j++)
			minn = min(minn, a[i][j]);

		for(int j = 1; j <= minn; j++)
			ans.push_back({"row",i});

		for(int j = 1; j <= m; j++)
			a[i][j] -= minn;
	}

	for(int j = 1; j <= m; j++) {
		for(int i = 1; i <= n; i++)
			if(a[i][j] != a[1][j]) {
				cout << "-1\n";
				return 0;
			}

		for(int i = 1; i <= a[1][j]; i++)
			ans.push_back({"col", j});
	}
	cout << ans << '\n';
}