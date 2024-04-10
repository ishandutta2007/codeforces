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

const int N = 100100;
int n, k, q, m, a, b, f[N], aib[N], op, x, y, val;
int reversed, l, r;

int lsb(int k) {
	return k &(-k);
}

void add(int pos, int val) {
	for(; pos < N; pos += lsb(pos))
		aib[pos] += val;
}

int que(int pos) {
	int ret = 0;
	if(!pos) return 0;
	for(; pos; pos -= lsb(pos))
		ret += aib[pos];
	return ret;
}

int new_val(int pos) {	
	if(reversed) return r - pos + 1;
	return l + pos - 1;
}

int put(int pos) {
	pos = new_val(pos);
	if(reversed) pos--;
	// dbg(pos);
	int mid = (l + r) / 2;
	if(pos <= mid) {
		for(int i = pos + 1; i <= r; i++) {
			if(pos - (i - pos - 1) < l) 
				break;
			add(i, f[pos - (i - pos - 1)]);
			f[i] += f[pos - (i - pos - 1)];
		}
		l = pos + 1;
		if(reversed)
			reversed ^= 1;
	} else {
		for(int i = pos; i >= l; i--) {
			if(pos + (pos - i) + 1 > r) 
				break;
			add(i, f[pos + (pos - i) + 1]);
			f[i] += f[pos + (pos - i) + 1];
		}
		// dbg(pos);
		r = pos;
		if(!reversed)
			reversed ^= 1;
	}
}

int solve(int x, int y) {
	// dbg(x, y);
	x = new_val(x);
	y = new_val(y);
	if(x >  y) swap(x, y);
	if(reversed) x--, y--;
	// dbg(x, y, que(y), que(x));
	return que(y) - que(x);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> q;
	l = 1;
	r = n;
	for(int i = 1; i <= n; i++) {
		add(i, 1);
		f[i] = 1;
	}

	for(int i = 1; i <= q; i++) {
		cin >> op;
		if(op == 1) {
			cin >> val;
			put(val);
		} else {
			cin >> x >> y;
			cout << solve(x, y) << '\n';
		}
		// dbg(l, r, reversed);
		// dbg_v(f, n + 1);
	}

	// put(1);
	// put(5);


}