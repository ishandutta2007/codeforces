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
int n, bad[255][255], k, dp[255];
string s, t;
int main() {
	ios_base::sync_with_stdio(false);

	cin >> s;
	n = s.size();
	cin >> k;
	for(int i = 1; i <= k; i++) {
		cin >> t;
		bad[t[0]][t[1]] = 1;
		bad[t[1]][t[0]] = 1;
	}
	
	for(int i = 0; i < n; i++) {
		// dp[i % 2][s[i] - 'a'] = dp[1 - i%2][s[i] - 'a'];
		int haha = dp[s[i] - 'a'];
		for(char c = 'a'; c <= 'z'; c++)
			if(!bad[c][s[i]])
				haha = max(haha, dp[c - 'a'] + 1);
		dp[s[i] - 'a'] = haha;
	}
	// dbg_v(dp, 26);
	cout << n - *max_element(dp, dp + 26);
}