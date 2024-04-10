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

const int N = 300100;

int n, k, m, p[N], a, b, ok[N];

set <int> s[N];
vector <int> imp[N];

void push_l(int pos) {
	dbg(pos);
	while(pos > 0 && s[p[pos - 1]].count(p[pos])) {
		swap(p[pos], p[pos - 1]);
		pos--;
	}
}

void push_r(int pos) {
	while(pos < n && s[p[pos]].count(p[pos + 1])) {
		swap(p[pos], p[pos + 1]);
		pos++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> p[i];

	int me = p[n];

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		s[a].insert(b);
		imp[b].push_back(a);
	}

	for(int i = 1; i < n; i++)
		if(s[p[i]].count(me))
			ok[p[i]] = 1;

	for(int i = n - 1; i > 0; i--) {
		if(ok[p[i]])
			push_r(i);
		// dbg_v(p, n + 1);
	}

	for(int i = 1; i <= n; i++)
		if(p[i] == me)
			return cout << n - i << '\n', 0;
}