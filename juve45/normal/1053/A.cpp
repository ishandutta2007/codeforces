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
int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	int nn = n, mm = m;
	// long long a = n * m;
	int g = __gcd(n, k);
	n /= g;
	k /= g;

	g = __gcd(m, k);
	m /= g;
	k /= g;

	if(k == 2) {
		cout << "YES\n0 0\n";
		cout << n << " " << 0 << '\n';
		cout << 0 << " " << m << '\n';
	} else if(k == 1){
		if(n < nn) {
			cout << "YES\n0 0\n";
			cout << 2 * n << " " << 0 << '\n';
			cout << 0 << " " << m << '\n';
		} else if(m < mm) {

			cout << "YES\n0 0\n";
			cout << n << " " << 0 << '\n';
			cout << 0 << " " << 2 * m << '\n';
		} else cout << "NO\n";
	} else {
		cout << "NO\n";
	}

		

}