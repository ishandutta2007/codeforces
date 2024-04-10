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


const int N = 2000100;
int n, k, m, a[N], b;
int l[N], r[N], aib[N];
unordered_map<int, int> f;
long long ans;

int lsb(int k) {
	return k & (-k);
}

void add(int pos, int val) {
	pos++;
	for(; pos < N; pos += lsb(pos))
		aib[pos] += val;
}


int que(int pos) {
	pos++;
	int ret = 0;
	for(; pos; pos -= lsb(pos))
		ret += aib[pos];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		f[a[i]]++;
		l[i] = f[a[i]];
	}
	f.clear();
	for(int i= n; i > 0; i--) {
		f[a[i]]++;
		r[i] = f[a[i]];
		add(r[i], 1);
	}

	for(int i = 1; i <= n; i++) {
		add(r[i], -1);
		ans += que(l[i] - 1);
	}
	cout << ans << '\n';

}