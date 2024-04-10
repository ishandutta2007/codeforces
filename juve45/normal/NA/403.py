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

long long ciclu, k, d, t;
// long double t;
int main() {
	ios_base::sync_with_stdio(false);

	cout << fixed << setprecision(9);

	cin >> k >> d >> t;

	ciclu = (k + d - 1) / d;
	ciclu *= d;
	long double pc = k + 0.5 * (ciclu - k);


	long double times = t / pc;
	times = floor(times);
	long double rest = 1.0 * t - times * pc;
	long double ans = times * ciclu;
	// if(rest > pc) return 1;
	dbg(times);
	dbg(pc);
	dbg(rest);
	dbg(k);
	dbg(ciclu);
	if(rest < k) ans += rest;
	else ans += k + 2 * (rest - k);

	cout << ans << '\n';

}