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

const int N = 300100;
int n, dp[N][22], q, first[N], last[N], x, y, a[N], ult[N];


string solve(int x, int y) {

	for(int j = 0; j < 20; j++)
		if(a[y] & (1 << j))
			if(dp[x][j] <= y)
				return "Shi";
	return "Fou";
} 

int main() {
	ios_base::sync_with_stdio(false);	

	cin >> n >> q;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		// if(!first[a[i]])
		// 	first[a[i]] = i;
		// last[a[i]] = i;
	}

	// ult[bit] = ult poz cu bitul bit setat

	memset(dp, 0x3f, sizeof dp);

	for(int i = 0; i < 20; i++) 
		ult[i] = n + 1;

	for(int i = n; i > 0; i--) {

		for(int j = 0; j < 20; j++) 
			if(a[i] & (1 << j)) 
				for(int k = 0; k < 20; k++)
					dp[i][k] = min(dp[i][k], dp[ult[j]][k]); 
		// dbg(i);
		// dbg_v(dp[i], 5);

		for(int j = 0; j < 20; j++)
			if(a[i] & (1 << j)) {
				ult[j] = i;
				dp[i][j] = i;
			}
	}

	for(int i = 1; i <= q; i++) {
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}
}