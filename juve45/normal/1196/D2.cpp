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
int n, k, q;
string s;
string st[] = {"RGB", "GBR", "BRG"};

void solve() {
	cin >> n >> k;
	cin >> s;

	int ans = k;
	for(int i = 0; i < 3; i++) {
		vector <int> v;
		for(int j = 0; j < s.size(); j++)
			if(s[j] == st[i][j % 3])
				v.push_back(1);
			else v.push_back(0);
		// dbg(v);
		for(int i  =1; i < v.size(); i++)
			v[i] += v[i - 1];

		ans = min(ans, k - v[k - 1]);
		for(int i = 1; i + k - 1 < v.size(); i++)
			ans = min(ans, k - v[i + k - 1] + v[i - 1]);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> q;
	while(q--) solve();
}