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

// const int N = 10;
// const int MOD = 666013;
int n, k, m, val;
vector <int> v, dif;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	set<int> s;

	for(int i = 0; i < min(30, n); i++) {
		int pos = (rand() * rand())% n + 1;
		while(s.count(pos)) pos = (rand() * rand()) % n + 1;
		cout << "? " << pos << endl;
		s.insert(pos);
		cin >> val;
		v.push_back(val);
	}

	for(auto i : v)
		for(auto j : v)
			if(i != j)
				dif.push_back(abs(i - j));

	sort(v.begin(), v.end());

	int gcd = 0;
	for(auto i : dif)
		gcd = __gcd(i, gcd);

	int l = v.back();
	int r = 1e9;
	int ras;
	while(l != r) {
		int mid = (l + r) / 2;
		cout << "> " << mid << endl;
		cin >> ras;
		if(ras) l = mid + 1;
		else r = mid;
	}
	dbg(r);
	cout << "! " << r - (n - 1) * gcd << ' ' << gcd << endl;
}