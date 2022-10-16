#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
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


int n, k, m, a, b, nr, f[779], last;
string s;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> s;
	for(auto i : s) f[i]++;

	for(int i = 'b'; i <= 'z'; i++)
		if(f[i] % 2 != 0) {
			return cout << ":(\n", 0;
		} else f[i] /= 2, last += f[i];

	for(int i = 1; i <= last; i++) {
		if(s[s.size() - i] == 'a')
			return cout << ":(\n", 0;
		f[s[s.size() - i]]--;
		if(f[s[s.size() - i]] < 0)
			return cout << ":(\n", 0;
	}
	string s1 = s.substr(s.size() - last), s2;
	for(auto i : s.substr(0, s.size() - last)) if(i != 'a') s2 += i;

	// dbg(s1, s2);
	

	if(s1 != s2) 
			return cout << ":(\n", 0;

	cout << s.substr(0, s.size() - last);

}