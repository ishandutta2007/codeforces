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
int n, f[1001003], s[10][1001002], l, r, k;

int prod(int x) {
	int p = 1;
	while(x) {
		if(x % 10 != 0)
			p *= (x % 10);
		x /= 10;
	}
	return p;
}

int getf(int nr) {
	if(nr < 10) return nr;
	return f[prod(nr)];
}

int main() {
	ios_base::sync_with_stdio(false);


	for(int i= 1; i <= 1000000; i++) {
		f[i] = getf(i);
		s[f[i]][i]++;
	}

	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= 1000000; j++)
			s[i][j] += s[i][j - 1];
	}
	// dbg_v(f, 40);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> l >> r >> k;
		cout << s[k][r] - s[k][l - 1] << '\n';
	}

}