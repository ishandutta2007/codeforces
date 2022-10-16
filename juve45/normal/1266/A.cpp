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
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> s;
		int nr = 0, par = 0;
		sort(s.begin(), s.end());
		for(int i = 1; i < s.size(); i++) {
			nr += (s[i] - '0');
			if((s[i] - '0') % 2 == 0) par = 1;
		}
		// dbg(par, nr);
		if(s[0] == '0' && nr % 3 == 0 && par) {
			// if(s.size() >= 3 && nr > 0)
				cout << "red\n";
			// else if(s.size() == 2 && nr >= 6)
			// 	cout << "red\n";
			// else cout << "cyan\n";
		}
		else {
			cout << "cyan\n";
		}
	}
}