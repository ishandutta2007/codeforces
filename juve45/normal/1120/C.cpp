#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;
using ull = long long;

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

const int N = 5005;
const ull B = 31;
const int MOD = 1e9 + 7;
const int MODH = 2e6 + 67013;
int n, a, b, dp[N];
ull hsh, hsh1;
string s;

struct hasher {

	vector <pair <int, int> > v[MODH];

	void add(int hsh1, int hsh, int pos) {
		if(get(hsh1, hsh) == -1) 
			v[hsh1].push_back({hsh, pos});
	}

	int get(int hsh1, int hsh) {
		for(auto i : v[hsh1])
			if(i.st == hsh)
				return i.nd;
		return -1;
	}
} hhh;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> a >> b;
	cin >> s;

	s = "#" + s;

	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + a;

		hsh = 0;
		hsh1 = 0;
		for(int j = i; j >= 1; j--) {
			hsh = (hsh * B + s[j] - 'a' + 1) % MOD;
			hsh1 = (hsh1 * 37 + s[j] - 'a' + 1) % MODH;
			// dbg(i, j, hsh, hsh1);

			int min_val = hhh.get(hsh1, hsh);
			// dbg(min_val);

			if(min_val != -1) {
				if(min_val < j)
					dp[i] = min(dp[i], dp[j - 1] + b);
			} else 
				hhh.add(hsh1, hsh, i);
		}
	}
	// dbg_v(dp, n+ 1);
	cout << dp[n] << '\n';
}