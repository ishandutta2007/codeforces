#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { for(auto e : v) out << e << ' '; return out;}
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


const int N = 505;
int n, k, m, a[N][N], b, ans;
vector <int >res;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];

		ans ^= a[i][1];
		res.push_back(1);
	}

	int ok = 0;
	if(ans == 0) {
		for(int i = 1; i <= n; i++)
			for(int j = 2; j <= m && !ok; j++)
				if(a[i][j] != a[i][1]) {
					res[i - 1] = j, ok = 1;
					break;
				}
	} else ok = 1;

	if(ok)
		cout << "TAK\n" << res << '\n';
	else cout << "NIE\n";
}