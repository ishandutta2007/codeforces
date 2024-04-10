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
int n, q, a, b, nr, nra, nrb;
string s;	

void add(int val, int &nr1, int &nr2, int c) {
	if(val >= 2 * b) nr1 += c;
	if(a <= val && val < 2 * b) nr2 += c;
}

string solve() {
		vector <int> v;
		nra = nrb = 0;
	
		cin >> a >> b;
		cin >> s;
		s = "X" + s + "X";

		for(auto i : s) {

			if(i == '.') nr++;
			else {
				if(nr) v.push_back(nr);
				nr = 0;

			}

			// if(nr == a) nra++, nr = 0;
		}

		// dbg(v);
		int sz, nr2 = 0, nr1 = 0;
		for(auto i : v) {
			if(i < b) continue;
			if(b <= i && i < a) return "NO\n";
			if(i >= 2 * b) nr1++;
			if(a <= i && i < 2 * b) nr2++;
		}

		// dbg(nr1, nr2);
		for(auto i : v) {
			if(i < b) continue;
			add(i, nr1, nr2, -1);
			// dbg(i, nr1, nr2);
			for(int j = 0; j + a <= i; j++) {
				int r = i - j - a;
				if (!(j < a && j >= b || r < a && r >= b)) {
					add(r, nr1, nr2, 1);
					add(j, nr1, nr2, 1);
					if(nr1 < 1 && nr2 % 2 == 0)  {
						// dbg(i, j, nr1, nr2);
						return "YES\n"; 
					}
					add(r, nr1, nr2, -1);
					add(j, nr1, nr2, -1);
				}
			}	
			add(i, nr1, nr2, 1);
		}
	return "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> q;

	while(q--) {
		cout << solve();
	}
}