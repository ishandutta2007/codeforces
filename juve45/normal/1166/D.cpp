#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << ' '; for(auto e : v) out << e << ' '; return out << '\n';}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <ynt> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


// const long long N = ;
long long n, k, m, a, b;

vector <long long> solve(long long a, long long b, long long m) {
	vector <long long> ret;
	vector <long long> no;
	long long current = a;
	long long minoff = 1;
	long long maxoff = m;
	long long add = 1, kk, offset;

	if(a == b) {
		no.push_back(a);
		return no;
	}

	for(long long k = 1; k <= 49; k++) {
		// dbg(current, b, minoff, maxoff);
		if(b < current + minoff)
			return no;
		if(current + minoff <= b && b <= current + maxoff) {
			dbg_ok;
			kk = k;
			offset = b - current;
			break;
		}
		current = 2 * current;
		minoff += add;
		maxoff += add * m;
		add *= 2;
	}

	vector <long long> v;
	v.push_back(a);
	long long sum = a;

	// dbg(offset, kk);
	offset -= (1LL << (kk - 1));
	
	long long mul = (1LL << (kk - 2));
	if(kk == 1) mul = 1;
	// dbg(mul);
	
	for(long long i = 1; i <= kk; i++) {
		// dbg(i, offset, sum, mul);
		
		long long cant = min(offset / mul, m - 1);
		offset -= mul * cant;
		
		mul /= 2; if(mul == 0) mul = 1;
		
		// dbg(cant);
		cant++;
		
		v.push_back(sum + cant);
		sum = 2 * sum + cant;
	}
	return v;
}


int main() {
	ios_base::sync_with_stdio(false);

	long long q;
	cin >> q;
	for(long long i = 1; i <= q; i++) {
		cin >> a >> b >> m;
		auto v = solve(a, b, m);
		if(v.size())
			cout << v;
		else cout << "-1\n";
	}

}