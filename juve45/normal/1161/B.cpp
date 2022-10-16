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
int n, k, m, a, b;
vector <int> v[N];

bool check(vector <int> &pos, int offset, int dif) {
	if(pos.size() == 0) return 1;
	// dbg(pos, offset, dif);
	// if(flag) {
	// 	if(dif == n / 2)
	// 		return 1;

	// }
	for(int i = 0; i < pos.size(); i++) {
		if((pos[i] + dif) % n != pos[(i + offset) % pos.size()])
			return 0;
	}
	return 1;
}

bool ok(int depl) {
	int perioada = n / depl;
	// dbg(depl, perioada);
	for(int i = 0; i <= n; i++)
		if(v[i].size() % perioada != 0 || !check(v[i], v[i].size() / perioada, depl))
			return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);


	cin >> n >> m;

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		int len = b - a;
		int min_pos = a;
		if(len < 0) len += n;
		if(len > n / 2) len = n - len, min_pos = b;
		if(len == n / 2) {
			v[0].push_back(b % n);
			v[0].push_back(a % n);
		} else v[len].push_back(min_pos % n);
	}

	for(int i = 0; i <= n; i++)
		sort(v[i].begin(), v[i].end());

	for(int i = 1; i < n; i++) {
		if(n % i == 0)
			if(ok(i))
				return cout << "Yes\n", 0;
	}
	cout << "No\n";
	return 0;
}