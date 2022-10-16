#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { for(auto e : v) out << e << ' '; return out;}
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

vector <int> ans;

int solve(int n, int k, int s) {
	if(k == 1) {
		if(n >= s) {
			ans.push_back(n);
			return 1;
		}
		return 0;
	}

	for(int i = s; i * i <= n; i++) {
		if(n % i == 0) {
			if(solve(n / i, k - 1, i + 1)) {
				ans.push_back(i);
				return 1;
			}
			return 0;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	for(cin >> t; t; t--) {
		cin >> n;
		ans.clear();
		if(solve(n, 3, 2)) {
			cout << "YES\n";
			cout << ans << '\n';
		} else {
			cout << "NO\n";
		}
	}
}