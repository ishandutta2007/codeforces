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
long long n, k, m, a, b, p[N], scad_adun[N], adun_scad[N], adun, scad, change[N];

int main() {
	// ios_base::sync_with_stdio(false);
	long long tmp_ans[N];
	tmp_ans[0] = 0;

	// cin >> n;
	scanf("%d", &n);
	for(long long i = 1; i <= n; i++) {
		// cin >> p[i];
		scanf("%d", p + i);
		tmp_ans[0] += abs(i - p[i]);
		
		if(i < p[i]) {
			scad++;
			scad_adun[p[i] - i]++;
			adun_scad[n - i]++;
			change[n - i] += (p[i] - 1) - (n + 1 - p[i]);
		} else {
			adun++;
			scad_adun[n - i + p[i]]++;
			adun_scad[n - i]++;
			change[n - i] += (p[i] - 1) - (n + 1 - p[i]);
		}
	}
	// dbg(scad, adun, tmp_ans);
	// dbg_v(change, n + 1);
	long long ans = 0;
	for(long long i = 1; i < n; i++) {
		tmp_ans[i] = tmp_ans[i - 1]; 
		tmp_ans[i] += change[i - 1] + adun - scad;
		adun += scad_adun[i] - adun_scad[i];
		scad -= scad_adun[i] - adun_scad[i];
		if(tmp_ans[ans] > tmp_ans[i])
			ans = i;
		// dbg(tmp_ans);
	}
	// dbg_v(tmp_ans, n + 1);
	cout << tmp_ans[ans] << ' ' << ans << '\n';
}