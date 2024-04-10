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

const int N = 100100;
int n, prv[N], a[N], p[N], pos[N], last;
vector <pair<int, int> > ans;

void swp(int x, int y) {
	if(x > y) swap(x, y);
	ans.push_back({x, y});
	swap(a[x], a[y]);
	swap(pos[a[x]], pos[a[y]]);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;


	for(int i = 2; i <= n; i++) {
		if(p[i] == 0) {
			last = i;
			for(int j = 2 * i; j <= n; j += i)
				p[j] = 1;
		}
		prv[i] = last;
	}

	for(int i = 1; i <= n; i++) {
		int j = pos[i];

		while(i != j) {
			int d = j - i + 1;
			int move = prv[d];
			swp(j, j - move + 1);
			j = j - move + 1;
		}
	}
	cout << ans << '\n';
}