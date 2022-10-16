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

// const int N = ;
int n, m, f[1004][366], val[1234], ans;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++)
			f[j][s[j]]++;
	}
	for(int j = 0; j < m; j++)
		cin >> val[j];

	for(int j = 0; j < m; j++) {
		int mx = 0;
		for(int i = 'A'; i <= 'E'; i++)
			mx = max(mx, f[j][i]);
		ans += mx* val[j];
	}
	cout << ans << '\n';


}