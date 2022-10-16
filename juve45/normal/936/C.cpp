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

string s, t;
vector <int> ans;

void apply(string & s, int nr) {
	string a = s.substr(0, s.size() - nr);
	string b = s.substr(s.size() - nr,nr);
	reverse(b.begin(), b.end());
	s = b + a;
}

bool check(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

int main() {
	ios_base::sync_with_stdio(false);

	// string ss = "abcde";
	// apply(s, 3);
	// dbg(s);


	cin >> n;
	cin >> s >> t;

	if(!check(s, t)) {
		cout << "-1\n";
		return 0;
	}

	int pref_size = 0, j;


	for(int i = 1; i <= (n + 1)/ 2; i++) {


		ans.push_back(n - pref_size);
		apply(s, n - pref_size);

		for(j = 0; j < n; j++) 
			if(s[j] == t[pref_size])
				break;
			
		ans.push_back(n - j - 1);
		apply(s, n - j - 1);

		ans.push_back(1);
		apply(s, 1);

		pref_size++;

		// dbg(pref_size);
		// dbg(s);
		// dbg(t);

		// halfway
		if(pref_size == n) {

			ans.push_back(n);
			apply(s, n);
			break;
		}


		for(j = pref_size; j < n; j++) 
			if(s[j] == t[pref_size])
				break;

		ans.push_back(n - j);
		apply(s, n - j);

		ans.push_back(n - (n - j) - pref_size);
		apply(s, n - (n - j) - pref_size);

		pref_size++;

		ans.push_back(pref_size);
		apply(s, pref_size);

		// dbg(pref_size);
		// dbg(s);
		// dbg(t);
		// dbg_ok;
	}
	cout << ans << '\n';


}