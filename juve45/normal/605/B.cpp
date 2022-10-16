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

const int N = 100100;

int n, k, m, a, b;
pair<int, int> ans[N];
vector <pair<pair<int, int>, int> > v;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v.push_back({{a, -b}, i});
	}

	sort(v.begin(), v.end());
	// dbg(v);

	int last_in = 1, last_free_big = 1, last_free_small = 1;

	for(auto i : v) {
		// dbg(i);
		if(i.st.nd == -1) {
			ans[i.nd] = {1, ++last_in};
		} else {
			while(last_free_big == last_free_small)
				last_free_big++, last_free_small = 2;

			if(last_in < last_free_big)
				return cout << "-1\n", 0;
			ans[i.nd] = {last_free_big, last_free_small++};
		}
	}

	for(int i = 1; i <= m; i++)
		cout << ans[i].st << ' ' << ans[i].nd << '\n';
}