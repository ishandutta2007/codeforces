#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, multiset <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
int n, m, x, a, b;
vector <int> v;
vector <pair<int, int> >  seg;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	v.push_back(0);
	for(int i = 1; i <= n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	for(int j = 1; j <= m; j++) {
		cin >> a >> b >> x;
		seg.push_back({a, b});
	}

	sort(seg.begin(), seg.end());

	int j = 0, ans = m;
	multiset<int> started;
	v.push_back(1e9);

	while(j < seg.size() && seg[j].st <= 1)
		started.insert(seg[j++].nd);

	for(int i = 1; i < v.size(); i++) {
		
		while(!started.empty() && *started.begin() < v[i]) started.erase(started.begin());

		ans = min(ans, (int) started.size() + i - 1);
	}
	cout << ans << '\n';
}