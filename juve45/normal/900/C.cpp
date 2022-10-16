#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << '['; for(auto e : v) out << e << ' '; return out << ']';}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 100100;
int n, p[N], mx[N];

int cnt(vector <int> & v, int lim) {
	return lower_bound(v.begin(), v.end(), lim, greater<int>()) - v.begin();
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	int ans = -n, x = -1;

	for(int i = 1; i <= n; i++)
		cin >> p[i], mx[i] = max(mx[i - 1], p[i]);

	// dbg_v(mx, n + 1);
	vector <int> st;
	for(int i = n; i > 0; i--) {

		// dbg(i, st.size(), mx[i], p[i], ans, x);
		// dbg(st);
		// while(!st.empty() && st.back() < mx[i - 1])  st.pop_back();
		int tot = cnt(st, mx[i - 1]);
		// dbg(st);
		while(!st.empty() && st.back() < p[i])  st.pop_back();
		// dbg(st);

		if(mx[i] != p[i]) {
			if(ans < 0 || ans == 0 && x > p[i]) {
				ans = 0;
				x = p[i];
			}
		}
		
		int me = (mx[i] == p[i]);
		if(x == -1 || tot - (int)st.size() - me > ans || ans == tot - (int)st.size() - me && x > p[i]) {
			// dbg_ok;
			// int add = 
			// int anyway = 
			ans = tot - (int) st.size() - me;
			x = p[i];
		}

		st.push_back(p[i]);
	}
	dbg(ans);
	cout << x << '\n';
}