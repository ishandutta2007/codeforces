#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 300100;
int n, a[N], pos[N];
vector <pair <int, int> > v;

void sw(int i, int j) {
	// dbg_ok;
	swap(pos[a[i]], pos[a[j]]);
	swap(a[i], a[j]);
	v.push_back({i, j});
}

void move(int from, int to)  {// to < from 

	if(to == from) return;

	if(from > n / 2) {
		if(to == 1) {
			sw(from, to);
		}else if(to <= n / 2) {
			if(from == n) {
				sw(from, to);
			} else {
				sw(from, 1);
				sw(1, n);
				sw(n, to);
				sw(from, 1);
			}
		} else {
			sw(from, 1);
			sw(1, to);
			sw(from, 1);
		}
	} else {
		sw(from, n);
		// dbg(from, to);
		sw(n, to);
	}

}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	for(int i = 1; i <= n; i++) {
		// dbg(i, pos[i]);
		move(pos[i], i);
		// dbg_v(a, n + 1);
	}
	cout << v << '\n';
	// dbg_v(a, n + 1);
}