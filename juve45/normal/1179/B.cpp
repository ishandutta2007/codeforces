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
int n, x = 1, y = 1, m;

void move(int a, int b) {
	cout << a << ' ' << b << '\n';
	x = a, y = b;
}

void moveCols(int a, int b) {
	// dbg(a, b);
	move(b, m);
	// dbg_ok;
	for(int i = 2; i <= m; i++) {
		move(a, i);
		move(b, m - i + 1);
	}
}



int main() {
	ios_base::sync_with_stdio(false);	

	cin >> n >> m;
	move(1, 1);
	for(int i = 1; i < n - i + 1; i++) {
		int a = i, b = n - i + 1;
		if(x != a) swap(a, b);
		// move(a, 1);
		moveCols(a, b);

		if(x <= n / 2 - (n % 2 == 0))
			move(b - 1, 1);
		else if(x > n / 2 + (n % 2 == 0))
			move(a + 1, 1);
	}

	if(n % 2 == 1) {

		for(int i = 1; i < m - i + 1; i++) {
			move(x, m - i + 1);
			if(i + 1 != m - i + 1)
				move(x, i + 1);
		}
	}

}