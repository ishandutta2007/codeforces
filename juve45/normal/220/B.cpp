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

const int N = 100100;
int n, m, a[N], s[N], ans[N], l[N], r[N];
map <int, int> f;
vector <int> v[N], g;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		f[a[i]]++;
	}

	for(int i = 1; i <= m; i++)
		cin >> l[i] >> r[i];

	for(auto i : f)
		if(i.nd >= i.st)
			g.push_back(i.st);

	for(auto x : g) {
		memset(s, 0, sizeof s);
		for(int i = 1; i <= n; i++)
			s[i] = s[i - 1] + (x == a[i]);

		for(int i = 1; i <= m; i++)
			if(s[r[i]] - s[l[i] - 1] == x)
				ans[i]++;
	}

	for(int i = 1; i <= m; i++) 
		cout << ans[i] << '\n';

}