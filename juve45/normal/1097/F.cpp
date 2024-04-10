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


const int N = 7010;
const int NMAX = 100100;
int n, k, m, a, b, q, op, who, val, x, y, z;
bitset <N> pre[N], v[NMAX], step4[N], sqf;
string ans;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> q;

	for(int i = 0; i < N; i++)
		for(int j = 1; j * j < N; j++)
			if(i % j == 0)
				pre[i][j] = pre[i][i / j] = 1;

	sqf.set();
	for(int i = 0; i < N; i++)
		for(int j = 2; j * j < N; j++)
			if(i % (j * j) == 0)
				sqf[i] = 0;

	for(int i = 1; i < N; i++)
		for(int j = i; j < N; j += i)
			if(sqf[j / i])
				step4[i][j] = 1;

	// dbg_ok;
	// dbg(sqf);
	// dbg(step4[2]);
	for(int i = 1; i <= q; i++) {
		cin >> op;
		if(op == 1) {
			cin >> who >> val;
			v[who] = pre[val];
		} else if(op == 2) {
			cin >> x >> y >> z;
			v[x] = v[y] ^ v[z];
		} else if(op == 3) {
			cin >> x >> y >> z;
			v[x] = v[y] & v[z];
		} else {
			cin >> x >> y;
			ans += (step4[y] & v[x]).count() % 2 + '0';
			// hard times
		}
	}
	cout << ans;

}