#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 10020;
int n, dp[N][3];
string s;
set <string>ans;

bool ok(int pos, int cnt) {
	if(pos + 2 * cnt - 1 >= s.size()) return 1;
	if(s.substr(pos, 2) == s.substr(pos + 2, 2))
		return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);


	cin >> s;
	dp[s.size()][0] =  dp[s.size()][1] = 1;
	for(int i = s.size() - 1; i > 4; i--) {
		if(dp[i + 2][1] || (dp[i + 2][0] && ok(i, 2))) {
			dp[i][0] = 1;
			if(i + 1 < s.size()) ans.insert(s.substr(i, 2));
		}
		
		if(dp[i + 3][0] || (dp[i + 3][1] && ok(i, 3))) {
			dp[i][1] = 1;
			if(i + 2 < s.size()) ans.insert(s.substr(i, 3));
		}
		
	}
	cout << ans << '\n';
}