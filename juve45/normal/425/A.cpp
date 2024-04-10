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

#define dbg(...) cerr << #__VA_ARGS__ << " .", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const int N = 210;
int n, k, m, a[N], b;
priority_queue <int> L[N], R[N];

int solve(int l, int r) {
	int sum = 0;
	vector <int> interior, exterior;
	for(int i = 1; i <= n; i++)
		if(l <= i && i <= r)
			interior.push_back(a[i]), sum += a[i];
		else 
			exterior.push_back(a[i]);
	sort(interior.begin(), interior.end());
	sort(exterior.begin(), exterior.end(), greater<int> ());

	for(int i = 0; i < k && i < interior.size() && i < exterior.size(); i++)
		if(sum + exterior[i] - interior[i] > sum)
			sum = sum + exterior[i] - interior[i];
	return sum;
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	int ans = -1e8;
	for(int l = 1; l <= n; l++) {
		for(int r = l; r <= n; r++) {
			ans = max(solve(l, r), ans);
		}
	}
	cout << ans << '\n';
}