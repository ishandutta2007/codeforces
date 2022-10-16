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
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <ynt> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const int N = 100100;
int n, k, m, a, b, x, f[N], ff[N], ans = 1;

int main() {
	ios_base::sync_with_stdio(false);

	set <int> s;

	cin >> n;
	// ans = min(3, n);
	for(int i = 1; i <= n; i++) {
		cin >> x;
		f[x]++;

		ff[f[x]]++;
		s.insert(f[x]);
		ff[f[x] - 1]--;
		
		if(f[x] > 1 && ff[f[x] - 1] == 0) s.erase(f[x] - 1);
		
		// dbg(s);
		// dbg(i, ff[1], ff[2], ff[3]);
		if(s.size() == 2) {
			if(*s.begin() == 1 && (ff[*s.begin()] == 1))
				ans = i;
			if(*s.begin() + 1 == *s.rbegin() && ff[*s.rbegin()] == 1)
				ans = i;
		} else if(s.size() == 1 && (ff[*s.begin()] == 1 || *s.begin() == 1))
			ans = i;	
		// dbg(i, ans);
	}
	cout << ans << '\n';
}