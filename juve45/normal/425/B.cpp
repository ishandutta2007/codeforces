#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << ':'; for(auto e : v) out << e << ' '; return out << endl;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <int> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const int N = 110;
int n, k, m, a[N][N], b, ans = N * N;

int cost(vector <int> v, int * a, int x) {
	int ret = 0;
	for(int i = 0; i < v.size(); i++)
		ret += ((v[i] ^ a[i]) == x);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];

	vector <vector <int> > fixed;

	// dbg(n, m, k);
	if(n > k) {
		// dbg_ok;
		for(int l = 0; l < n; l++) {
			vector <int> v;
			for(int i = 0; i < m; i++)
				v.push_back(a[l][i]);
			fixed.push_back(v);
		}
	} else {
		for(int msk = 0; msk <= (1 << n); msk++) {
			vector <int> v;
			int mm = msk;
			for(int i = 0; i < n; i++, mm /= 2)
				v.push_back(mm % 2);
			fixed.push_back(v);
		}

		for(int i = 0; i < max(n, m); i++)
			for(int j = i; j < max(n, m); j++)
				swap(a[i][j], a[j][i]);
		swap(n, m);
	}

	// dbg(fixed);
	for(auto v : fixed) {
		int tmp = 0;
		for(int i = 0; i < n; i++)
			tmp += min(cost(v, a[i], 1), cost(v, a[i], 0));
		ans = min(ans, tmp);
	}

	if(ans > k) ans = -1;
	cout << ans << '\n';
}