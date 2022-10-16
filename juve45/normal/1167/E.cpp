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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const long long N = 1000100;
long long n, k, m, a[N], b, x, fi[N], la[N], ans, nxt[N];
vector <long long> v;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> x;

	// memset(fi, 0x3f, sizeof(fi));
	long long maxx = 0;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		if(!fi[a[i]]) fi[a[i]] = i;
		la[a[i]] = i;
		maxx = max(a[i], maxx);
	}
	fi[0] = -1;
	la[0] = -1;
	fi[x + 1] = n + 1;
	la[x + 1] = n + 1;

	long long lll = 0;
	for(long long i = 0; i <= x + 1; i++) 
		if(fi[i]) 
			v.push_back(i);

	long long r = v.size() - 1;
	while(r > 0 && fi[v[r]] > la[v[r - 1]])
		r--;
	// dbg(v);
	// dbg_v(fi, x + 2);
	// dbg_v(la, x + 2);
	// dbg(r);
	long long last = -1e9;
	for(long long l = 0; l <= x + 1; l++) {
		// dbg(l, last);
		if(fi[l]) {
			if(fi[l] < last)
				break;
			last = la[l];
		}

		while(r < v.size() && (fi[v[r]] <= last || l >= v[r])) r++;
		if(r >= v.size()) break;

		// dbg(l, v[r]);
		if(v[r - 1] <= l + 1) 
			ans += (x - l);
		else ans += (x - (v[r - 1] - 1));
		// dbg(ans);
	}
	cout << ans << '\n';	

}