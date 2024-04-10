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
int n;

int get_sqr(int n) {
	int k = sqrt(2 * n);
	while(k * (k + 1) <= 2 * n) k++;
	return k;
}

void solve(int n) {
	vector <int> v;
	while(n) {
		int x = get_sqr(n);
		v.push_back(x);
		n -= x * (x - 1) / 2;
		dbg(n);
	}

	// cout << v;
	dbg(v);
	string s = "1";

	for(int i = 1; i <= 50000 && !v.empty(); i++) {
		s += "3";
		while(!v.empty() && v.back() == i) {
			s += "7";
			v.pop_back();
		}
	}
	cout << s << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		solve(n);
	}
	
}