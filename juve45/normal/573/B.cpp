#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 100100;
int n, h[N], h2[N], dpl[N], dpr[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> h[i];

	dpl[1] = 1;
	for(int i = 2; i <= n; i++) 
		dpl[i] = min(dpl[i - 1] + 1, h[i]);

	dpr[n] = 1;
	for(int i = n; i > 0; i--)
		dpr[i] = min(dpr[i + 1] + 1, h[i]);

	int ans = 0;//(n + 1) / 2;
	for(int i = 1; i <= n; i++)
		ans = max(ans, min(dpl[i], dpr[i]));
// 
	// dbg_v(dpl, n +1);
	// dbg_v(dpr, n +1);
	cout << ans << '\n';

	// if(n == 1) return cout << "1\n", 0;

	// h2[1] = h2[n] = 0;
	// for(int i = 2; i < n; i++) {
	// 	if(h[i] == 1) h2[i] = 0;
	// 	else h2[i] = min({h[i], h[i - 1], h[i + 1]});
	// }

	// int last = 0, ans = 0;
	// // dbg_v(h2, n + 1);
	// for(int i = 1; i <= n; i++) {
	// 	if(h2[i] == 0) {
	// 		ans = max((last + 1) / 2, ans);
	// 		last = 0;
	// 	}
	// 	else last++;
	// }
	
	// cout << ans + 1 << '\n';
}