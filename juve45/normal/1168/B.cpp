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

int r[300100];
string s;

long long solve(string s) {
	int n = s.size();

	for(int i = 0; i < n; i++) {
		r[i] = n;
		for(int j = 1; j < 7 && i + 2 * j < n; j++) {
			if(s[i] == s[i + j] && s[i] == s[i + 2 * j]) {
				r[i] = i + 2 * j;
				break;
			}
		}
	}

	// dbg_v(r, n + 1);

	r[n] = n;
	for(int i = n - 1; i >= 0; i--)
		r[i] = min(r[i], r[i + 1]);

	// dbg_v(r, n + 1);

	long long ans = 0;
	for(int i = 0; i < n; i++) {
		// dbg(i, r[i]);
		ans += 1LL * (n - r[i]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> s;
	cout << solve(s) << '\n';
	// for(int msk = 0; msk < (1 << 9); msk++ ){
	// 	string s;
	// 	for(int i = 0; i < 9; i++)
	// 		if(msk & (1 << i))
	// 			s += "1";
	// 		else s += "0";
	// 	if(solve(s) == 0) cout << s << '\n';
	// }
}