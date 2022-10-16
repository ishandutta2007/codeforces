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
int n, k, m, a;

string op[N], op2[4];

pair<string, int> prel(vector <pair<int, int> > &ops) {

	auto v = ops;
	sort(v.begin(), v.end(), greater<pair<int, int>>() );
	// dbg(v);
	string ret = "";
	int sv = 0;

	if(v.size() > 0) op[v[0].nd] = "pushBack";
	if(v.size() > 1) op[v[1].nd] = "pushStack";
	if(v.size() > 2) op[v[2].nd] = "pushQueue";

	if(v.size() < 3) {
		
		for(int i = 0; i < v.size(); i++)
			ret += " " + op2[i], sv++;

		return {ret, sv};
	}

	for(int i = 0; i < 3; i++)
		ret += " " + op2[i], sv ++;


	for(int i = 3; i < v.size(); i++)
		op[v[i].nd] = "pushFront";
	return {ret, sv};
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	op2[0] = "popBack";
	op2[1] = "popStack";
	op2[2] = "popQueue";

	vector <pair<int, int> > ops;
	for(int i = 1; i <= n; i++) {
		cin >> a;
		if(a == 0) {
			auto pp = prel(ops);
			// dbg(ops);
			for(int i = 0; i < ops.size(); i++)
				cout << op[i] << '\n';
			cout << pp.nd << pp.st << '\n';

			ops.clear();
		} else 
			ops.push_back({a, ops.size()});
	}
	for(int i = 0; i < ops.size(); i++)
		cout << "pushFront\n";
}