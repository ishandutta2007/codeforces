
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

void solve(int n) {
	if(n <= 3) {cout << "-1\n"; return;}
	if(n == 4) {cout << "3 1 4 2\n"; return;}
	if(n == 5) {cout << "1 4 2 5 3\n"; return;}
	int start = 1;
	while(start <= n) cout << start << ' ', start += 2;
	if(n % 2 == 1) {
		start = n - 1;
		cout << start - 2 << ' ' << start <<  ' ' << start - 4 << ' ';
		start -= 6;
		while(start) cout << start << ' ', start -= 2;
	}
	else {
		start = n;
		cout << start - 4 << ' ' << start << ' ' << start - 2 << ' ';
		start -= 6;
		while(start) cout << start << ' ', start -= 2;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		cin >> n;
		solve(n);
	}
}	


// 1 3 5 7 [9 10 8] 6 4 2

// 				9 6 8 4
// 				7 6 8 4