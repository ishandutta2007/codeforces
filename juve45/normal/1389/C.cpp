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
int n, t;

int f[100], f2[10];

int solve() {
	string s;
	cin >> s;
	memset(f, 0, sizeof f);
	memset(f2, 0, sizeof f2);

	for(auto i : s) {
		int k = i - '0';
		f2[k]++;

		for(int j = 0; j < 10; j++)
			f[j * 10 + k] = max(f[k * 10 + j] + 1, f[j * 10 + k]);
	}
	
	int ans = 1;
	
	for(int i = 0; i < 10; i++) 
		ans = max(ans, f2[i]);

	for(int i = 0; i < 100; i++) 
		ans = max(ans, f[i] / 2 * 2);
	return s.size() - ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> t;
	while(t--) {
		cout << solve() << '\n';
	}


}