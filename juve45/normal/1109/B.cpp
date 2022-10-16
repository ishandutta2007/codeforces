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

const int N = 10;
const int MOD = 666013;
int n, k, m;

bool ispal(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return (s == t);
}

string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	bool ok = 0;
	for(auto i : s)
		if(i != s[0])
			ok = 1;
	if(!ok) return cout << "Impossible\n", 0;

	if(s.size() % 2 == 1) {
		bool ok = 0;
		for(auto i : s.substr(0, s.size() / 2))
			if(i != s[0])
				ok = 1;
		if(!ok) return cout << "Impossible\n", 0;
	}


	for(int i = 1; i <= s.size() / 2; i++) {
		string ss = s.substr(i) + s.substr(0, i);

		if(ss != s && ispal(ss))
			return cout << "1\n", 0;
	}

	cout << "2\n";
}