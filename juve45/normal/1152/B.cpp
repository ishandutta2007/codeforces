#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << 2 * v.size() - 1 << '\n'; for(auto e : v) out << e << ' '; return out;}
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
vector <int> v;

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;

	while(__builtin_popcount(n) > 1) {
		int nr = n, cnt = 0;
		while(nr % 2 == 0) nr /= 2, cnt++;
		v.push_back(cnt);
		dbg(cnt);
		n = (n ^ ((1 << cnt) - 1)) + 1;
		dbg(n);
	}

	int nr = n, cnt = 0;
	while(nr % 2 == 0) nr /= 2, cnt++;
	v.push_back(cnt);
	
	if(v.size() == 0) {
		cout << "0\n";
		return 0;
	}
	cout << v;
	// int nr = n, cnt = 0;
	// while(nr % 2 == 0) nr /= 2, cnt++;
	// cout << cnt << '\n';
}