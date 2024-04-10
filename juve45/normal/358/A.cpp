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
long long n, k, m, x[N];

vector <pair<int, int> > seg;

bool inter(pair<int, int> a, pair<int, int> b) {
	// dbg(a);
	// dbg(b);
	if(a.st < b.st && b.st < a.nd && a.nd < b.nd)
		return 1;
	swap(a, b);
	if(a.st < b.st && b.st < a.nd && a.nd < b.nd)
		return 1;
	// dbg_ok;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> x[i];

	for(int i = 2; i <= n; i++)
		seg.push_back({min(x[i], x[i - 1]), max(x[i], x[i - 1])});

	for(int i = 0; i < seg.size(); i++)
		for(int j = i + 1; j < seg.size(); j++)
			if(inter(seg[i], seg[j]))
				return cout << "yes\n", 0;

	cout << "no\n";
}